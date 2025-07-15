from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG
import numpy as np

# Models
def parabolic_model(mjj,a,b,c):
    return a*mjj*mjj + b*mjj + c

def linear_model(mjj,slope,level):
    return slope*mjj + level

def parabolic_cutoff_model(mjj,a,b,c,mass_limit=5000,level=1):
    mjj = np.array(mjj)
    if mjj<= mass_limit:
        return a*mjj*mjj+b*mjj+c
    else :
        return level
    
def linear_model_uncertainty(x, covariance_matrix):
    sigma_slope = covariance_matrix[0][0]
    sigma_level = covariance_matrix[1][1]
    cov = covariance_matrix[0][1]

    return np.sqrt(sigma_slope*x**2 + sigma_level + 2*cov*x)

def parabolic_model_uncertainty(x, covariance_matrix):
    sigma_a = covariance_matrix[0][0]
    sigma_b = covariance_matrix[1][1]
    sigma_c = covariance_matrix[2][2]
    
    cov_ab = covariance_matrix[0][1]
    cov_ac = covariance_matrix[0][2]
    cov_bc = covariance_matrix[1][2]
    
    diagonal_term = sigma_a*x**4 + sigma_b*x**2 + sigma_c
    no_diagonal_term = 2*cov_ab*x**3 + 2*cov_ac*x**2 + 2*cov_bc*x
    
    return np.sqrt(diagonal_term+no_diagonal_term)

def parabolic_cutoff_model_uncertainty(x_axis, covariance_matrix, x_axis_limit=5000, sigma=1.0):
    x = x_axis
    if x<= x_axis_limit:
        sigma_a = covariance_matrix[0][0]
        sigma_b = covariance_matrix[1][1]
        sigma_c = covariance_matrix[2][2]
        
        cov_ab = covariance_matrix[0][1]
        cov_ac = covariance_matrix[0][2]
        cov_bc = covariance_matrix[1][2]
        
        diagonal_term = sigma_a*x**4 + sigma_b*x**2 + sigma_c
        no_diagonal_term = 2*cov_ab*x**3 + 2*cov_ac*x**2 + 2*cov_bc*x
    
        return np.sqrt(diagonal_term+no_diagonal_term)
    else :
        return sigma


# Test statistic
# Make fit parameters a list of variable length arguments
def reducedChiSquared(model, fit_parameters, x,y,uncer):
    x = x[1:]
    y = y[1:]
    uncer = uncer[1:]
    chi=0
    for i in range(0,len(x)):
        chi+=((y[i]-model(x[i],*fit_parameters))**2)/(uncer[i]**2)
        #print(x[i])
        #print(((y[i]-model(x[i],slope,level))**2)/(uncer[i]**2))
    return (chi/(len(x)-len(fit_parameters)))


class FitExperiment:
    def __init__(self, name, model, fit_parameters, fit_covariance,x, y, y_uncer):
        if not self._check_name_scheme(name):
            ERROR.log(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
            raise ValueError(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
        self.name = name
        self.model = model
        self.model_uncertainty = self._get_uncertainty_function()
        self.fit_parameters = fit_parameters
        self.fit_covariance = fit_covariance
        self.x = x
        self.y = y
        self.y_uncer = y_uncer
        self.reduced_chi2 = reducedChiSquared(model, fit_parameters, x, y, y_uncer)

    def __str__(self):
        return f"Experiment Name: {self.name}\n Model: {self.model}\n Model_E: {self.model_uncertainty}\n Parameters: {self.fit_parameters}\n Parameters_E: {self.fit_covariance}\n Reduced Chi2: {self.reduced_chi2}"
    
    # Name should always be of type CRX_EWjj_QCDjj_shape
    def _check_name_scheme(self, name):
        name_parts = name.split('_')
        if len(name_parts) != 4:
            ERROR.log(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
            return False
        
        if name_parts[0][:2] != "CR" and name_parts[0][:2] != "SR":
            ERROR.log(f"Experiment name {name} does not start with 'CR'.")
            return False
        if name_parts[1][:4] != "EWjj":
            ERROR.log(f"Experiment name {name} does not contain 'EWjj'.")
            return False
        if name_parts[2][:5] != "QCDjj":
            ERROR.log(f"Experiment name {name} does not contain 'QCDjj'.")
            return False
        if name_parts[3] not in ["parabolic", "linear", "parabolic-cutoff"]:
            ERROR.log(f"Experiment name {name} does not contain a valid shape.")
            return False
        return True
    
    # Assign the correct uncertainty function based on the model
    def _get_uncertainty_function(self):
        if self.name.endswith("parabolic"):
            return parabolic_model_uncertainty
        elif self.name.endswith("linear"):
            return linear_model_uncertainty
        elif self.name.endswith("parabolic-cutoff"):
            return parabolic_cutoff_model_uncertainty
        else:
            ERROR.log(f"Experiment name {self.name} does not contain a valid shape.")
            raise ValueError(f"Experiment name {self.name} does not contain a valid shape.")
    
    def get_name_scheme(self):
        name_parts = self.name.split('_')
        CR = name_parts[0]  # Remove 'CR' prefix
        EW = name_parts[1][4:]  # Remove 'EWjj' prefix
        QCD = name_parts[2][5:]  # Remove 'QCDjj' prefix
        shape = name_parts[3]
        return CR, EW, QCD, shape

    # This function take the model, the fit parameters and the uncertainties and calculates the model predictions
    def make_predictions(self, mode = 'function-extrapolation', x_axis = None):
        if mode == 'point-by-point':
            return self.y, self.y_uncer
        elif mode == 'function-extrapolation':
            if x_axis is None:
                ERROR.log("No x_axis provided for function extrapolation mode. This is required when using function-extrapolation mode.")
                raise ValueError("No x_axis provided for function extrapolation mode. This is required when using function-extrapolation mode.")
            x = x_axis
            model = self.model
            fit_params = self.fit_parameters
            model_uncertainty = self.model_uncertainty
            try:
                y_pred = model(x, *fit_params)
                y_uncer = model_uncertainty(x, self.fit_covariance)
            except ValueError:
                DEBUG.log(f"Error in model prediction for experiment {self.name}. Trying with cutoff model way of passsing params.")
                model = np.vectorize(model)
                model_uncertainty = np.vectorize(model_uncertainty, excluded=['covariance_matrix'])
                y_pred = model(x, *fit_params)
                y_uncer = model_uncertainty(x, covariance_matrix=self.fit_covariance[0],
                                             x_axis_limit=self.fit_covariance[1],
                                             sigma=self.fit_covariance[2])

            return y_pred, y_uncer
        else:
            ERROR.log(f"Invalid prediction mode: {mode}. Valid modes are 'function-extrapolation' and 'point-by-point'.")
            raise ValueError(f"Invalid prediction mode: {mode}. Valid modes are 'function-extrapolation' and 'point-by-point'.")

class FitExperimentContainer:
    def __init__(self):
        self.experiments = []

    # Produce warning if the experiment is already in the container
    def add_experiment(self, experiment: FitExperiment):
        if self.get_experiment(experiment.name) is not None:
            WARNING.log(f"Experiment with name {experiment.name} already exists.")
        self.experiments.append(experiment)

    def remove_experiment(self, name):
        self.experiments = [exp for exp in self.experiments if exp.name != name]
        INFO.log(f"Experiment with name {name} removed.")

    def get_experiment(self, name):
        for exp in self.experiments:
            if exp.name == name:
                return exp
        DEBUG.log(f"Experiment with name {name} not found. Returning None.")
        return None

    def __str__(self):
        return "\n".join(str(exp) for exp in self.experiments)
    
    def print_experiments(self):
        if len(self.experiments) == 0:
            INFO.log("No experiments in the container.")
            return
        for exp in self.experiments:
            INFO.log(str(exp))

# Perform the fit in mjj and add this to the experiments container
from scipy.optimize import curve_fit
def mjj_fit_experiment(model , x_axis, y_axis, y_uncer, experiment_name=None, experiments_container: FitExperimentContainer = None):
    if experiment_name is None:
        WARNING.log("No experiment name provided, results will not be stored.")
        return curve_fit(model, x_axis, y_axis, sigma=y_uncer)
    
    if experiments_container is None:
        WARNING.log("No experiments container provided, results will not be stored.")
        return curve_fit(model, x_axis, y_axis, sigma=y_uncer)


    fit_params, fit_covariance = curve_fit(model, x_axis, y_axis, sigma=y_uncer)
    new_experiment = FitExperiment(
        name=experiment_name,
        model=model,
        fit_parameters=fit_params,
        fit_covariance=fit_covariance,
        x=x_axis,
        y=y_axis,
        y_uncer=y_uncer
    )
    
    if not experiments_container.get_experiment(experiment_name) is None:
        WARNING.log(f"Experiment with name {experiment_name} already exists.")
        INFO.log("Do you want to overwrite it? (y/n)")
        overwrite = input().strip().lower() == 'y'
        if overwrite:
            INFO.log(f"Overwriting experiment {experiment_name}.")
            # Remove the existing experiment
            experiments_container.remove_experiment(experiment_name)
            experiments_container.add_experiment(new_experiment)
            return fit_params, fit_covariance

        else:
            WARNING.log(f"Experiment with name {experiment_name} already exists. Results will not be stored.")
            return fit_params, fit_covariance
    else:
        INFO.log(f"Adding new experiment {experiment_name}.")
        experiments_container.add_experiment(new_experiment)
        return fit_params, fit_covariance
    

# This function displays the Data/QCDjj points vs the fit experiments
import matplotlib.pyplot as plt
import numpy as np
def display_fit_experiments(experiments_container: FitExperimentContainer, CR_name, experiment_names : list[str], save: bool = False, save_name : str = None):
    if len(experiment_names) == 0:
        WARNING.log("No experiment names provided, nothing to display.")
        return

    for i in experiment_names:
        if CR_name not in i:
            ERROR.log(f"Experiment name {i} does not contain the required CR name {CR_name}.")
            raise ValueError(f"Experiment name {i} does not contain the required CR name {CR_name}.")

    x_axis = experiments_container.get_experiment(experiment_names[0]).x
    y_axis = experiments_container.get_experiment(experiment_names[0]).y
    y_uncer = experiments_container.get_experiment(experiment_names[0]).y_uncer
    CR, EW, QCD, shape = experiments_container.get_experiment(experiment_names[0]).get_name_scheme()

    fig, ax = plt.subplots()
    # Plot the data points
    plt.errorbar(x_axis, y_axis, yerr=y_uncer, fmt='.', label='(Data-BG)/QCDjj')
    plt.rcParams['text.usetex'] = True
    X = np.append(x_axis,5000.0)

    # Plot the fit experiments
    experiment_counter = 1
    for iexperiment in experiment_names:
        experiment = experiments_container.get_experiment(iexperiment)
        experiment_model = experiment.model
        fit_params = experiment.fit_parameters
        model_name = experiment.get_name_scheme()[3]
        plt.plot(X, experiment_model(X, *fit_params), label='Fit-%s' % model_name)

        # Plot the GoF of the experiments
        font = {'color':  'black',
        'weight': 'normal',
        'size': 16,}
        gof = experiment.reduced_chi2
        plt.text(0.05, (experiment_counter + 1)*0.05, '%s = %s' % (model_name,round(gof,2)),fontdict=font, transform = ax.transAxes)
        experiment_counter += 1

    plt.text(0.05, 0.03, 'Reduced chi-squared: ',fontdict=font, transform = ax.transAxes)


    plt.legend()
    plt.xlabel(r'$m_{jj}$ [GeV]',fontsize=20,horizontalalignment='center')
    plt.ylabel(r'$r_{k}$',fontsize=18)
    plt.xlim(0,5000)
    plt.title("%s QCDjj: %s EWjj: %s" % (CR, QCD, EW),fontsize=18)
    plt.xticks(fontsize = 15)
    plt.yticks(fontsize = 15)
    

    # Save the figure if save is True, if not show it
    if save:
        if save_name is None:
            ERROR.log("No save name provided, cannot save the figure.")
            raise ValueError("No save name provided, cannot save the figure.")
        plt.savefig(save_name, bbox_inches='tight')
    else:
        INFO.log("Displaying the figure without saving.")
        plt.show()
    

# Function to store fit results in a DataFrame
import pandas as pd
def convert_fit_result_to_dataframe(params,covariance,params_names):
    result = []
    for i in range(0,len(params)):
        result.append(params[i])
        result.append(np.sqrt(covariance[i][i]))
        
    column_name = []
    for i in params_names:
        column_name.append(i)
        column_name.append('Sigma '+i)
        
    df = pd.DataFrame (result,index=column_name)
    return df.T
    

# Predict the SR values from a particular set of experiments.
def predict_SR_from_experiments(experiments_container : FitExperimentContainer, experiment_type : str = None, prediction_mode : str = 'function-extrapolation', x_axis = None):

    # Check that the prediction mode is valid
    if prediction_mode not in ['function-extrapolation', 'point-by-point']:
        ERROR.log(f"Invalid prediction mode: {prediction_mode}.")
        raise ValueError(f"Invalid prediction mode: {prediction_mode}. Valid modes are 'function-extrapolation' and 'point-by-point'.")

    if experiments_container == None:
        ERROR.log("No experiments container provided, cannot predict SR values.")
        raise ValueError("No experiments container provided, cannot predict SR values.")
    if experiment_type == None:
        ERROR.log("No experiment type provided, cannot predict SR values.")
        raise ValueError("No experiment type provided, cannot predict SR values.")

    # It should follow the scheme EWjj_QCDjj_shape
    experiment_type_parts = experiment_type.split('_')
    if len(experiment_type_parts) != 3:
        ERROR.log(f"Experiment type {experiment_type} does not follow the required scheme: EWjj_QCDjj_shape")
        raise ValueError(f"Experiment type {experiment_type} does not follow the required scheme: EWjj_QCDjj_shape")

    # For now just check that no CR or SR are passed in the experiment_type
    if 'SR' in experiment_type_parts[0] or 'CR' in experiment_type_parts[0]:
        ERROR.log(f"Experiment type {experiment_type} should not contain CR or SR in the first part.")
        raise ValueError(f"Experiment type {experiment_type} should not contain CR or SR in the first part.")
    

    # Now find the relevant experiments in the container
    n_found_matching_experiments = 0
    CRa_experiment = None
    CRb_experiment = None
    CRc_experiment = None
    for i_experiment in experiments_container.experiments:
        CR, EW, QCD, shape = i_experiment.get_name_scheme()
        if EW in experiment_type_parts[0] and QCD in experiment_type_parts[1] and shape == experiment_type_parts[2]:
            DEBUG.log(f"Found experiment {i_experiment.name} matching the type {experiment_type}.")
            n_found_matching_experiments += 1
            if CR == 'CRa':
                CRa_experiment = i_experiment
            elif CR == 'CRb':
                CRb_experiment = i_experiment
            elif CR == 'CRc':
                CRc_experiment = i_experiment

    if n_found_matching_experiments != 3:
        ERROR.log(f"Found {n_found_matching_experiments} experiments matching the type {experiment_type}, expected 3 (CRa, CRb, CRc).")
        raise ValueError(f"Found {n_found_matching_experiments} experiments matching the type {experiment_type}, expected 3 (CRa, CRb, CRc).")
    if CRa_experiment is None or CRb_experiment is None or CRc_experiment is None:
        ERROR.log(f"Could not find all required experiments for type {experiment_type}.")
        raise ValueError(f"Could not find all required experiments for type {experiment_type}.")        

    # Get prediction region by region
    CRa_pred,CRa_pred_uncer = CRa_experiment.make_predictions(mode=prediction_mode, x_axis=x_axis)
    CRb_pred,CRb_pred_uncer = CRb_experiment.make_predictions(mode=prediction_mode, x_axis=x_axis)
    CRc_pred,CRc_pred_uncer = CRc_experiment.make_predictions(mode=prediction_mode, x_axis=x_axis)

    # Calculate the SR_y and SR_error
    # For function-extrapolation we should have the same x_axis for all three CRs
    if prediction_mode == 'function-extrapolation':
        SR_y = CRa_pred*CRc_pred/CRb_pred
        SR_error = SR_y*np.sqrt((CRa_pred_uncer/CRa_pred)**2+(CRb_pred_uncer/CRb_pred)**2+(CRc_pred_uncer/CRc_pred)**2)
    # We only have the info for up to the last bin to which we can apply the ABCD
    else:
        INFO.log("Using point-by-point prediction mode. These are the axis of the CRs: ")
        INFO.log(f"CRa: {CRa_experiment.x}")
        INFO.log(f"CRb: {CRb_experiment.x}")
        INFO.log(f"CRc: {CRc_experiment.x}")
        n_valid_elements = 0
        for bin in CRa_experiment.x:
            if bin in CRb_experiment.x and bin in CRc_experiment.x:
                n_valid_elements += 1
            else:
                break
        INFO.log(f"Found {n_valid_elements} valid elements in the CRs. Using them for the ABCD extrapolation")
        CRa_pred,CRa_pred_uncer = CRa_pred[:n_valid_elements],CRa_pred_uncer[:n_valid_elements]
        CRb_pred,CRb_pred_uncer = CRb_pred[:n_valid_elements],CRb_pred_uncer[:n_valid_elements]
        CRc_pred,CRc_pred_uncer = CRc_pred[:n_valid_elements],CRc_pred_uncer[:n_valid_elements]

        # Calculate the SR_y and SR_error
        SR_y = CRa_pred*CRc_pred/CRb_pred
        SR_error = SR_y*np.sqrt((CRa_pred_uncer/CRa_pred)**2+(CRb_pred_uncer/CRb_pred)**2+(CRc_pred_uncer/CRc_pred)**2)

    return SR_y, SR_error

