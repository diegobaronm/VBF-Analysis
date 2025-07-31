
import numpy as np
import math
from uncertainties import ufloat, correlated_values
from uncertainties.umath import *

from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG

################################## Models ##################################
def parabolic_model(mjj,a,b,c):
    return a*mjj*mjj + b*mjj + c

def linear_model(mjj,slope,level):
    return slope*mjj + level

def parabolic_cutoff_model(mjj,a,b,c,mass_limit=5000,level=1):
    mjj = np.array(mjj)
    if mjj<= mass_limit:
        return a*mjj*mjj + b*mjj + c
    else :
        return level
    
def exponential_model(mjj, a, b, c):
    y = c - b * (1 - math.e**(-a * mjj))
    return y

#################################################################################


# Test statistic
# Make fit parameters a list of variable length arguments
def reducedChiSquared(model, fit_parameters, x,y,uncer, is_cutoff_model=False, cutoff_value=5000):
    x = x[1:]
    y = y[1:]
    uncer = uncer[1:]
    chi=0
    for i in range(0,len(x)):
        if not is_cutoff_model:
            chi+=((y[i]-model(x[i],*fit_parameters))**2)/(uncer[i]**2)
        else:
            chi+=((y[i]-model(x[i],*fit_parameters, mass_limit=cutoff_value, level= model(cutoff_value,*fit_parameters)))**2)/(uncer[i]**2)

    if not is_cutoff_model:
        reduced_chi2 = (chi/(len(x)-len(fit_parameters)))
    else:
        reduced_chi2 = (chi/(len(x)-len(fit_parameters) - 1))

    return reduced_chi2


class FitExperiment:
    def __init__(self, name, model, fit_parameters, fit_covariance,x, y, y_uncer, cutoff_value=None):
        if not self._check_name_scheme(name):
            ERROR.log(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
            raise ValueError(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
        self.name = name
        self.model = model
        self.fit_parameters = fit_parameters
        self.fit_covariance = fit_covariance
        self.is_cutoff_model = ('parabolic-cutoff' in name)
        self.cutoff_value = cutoff_value
        if self.is_cutoff_model and cutoff_value is None:
            ERROR.log(f"Experiment {name} is a cutoff model but no cutoff value provided.")
            raise ValueError(f"Experiment {name} is a cutoff model but no cutoff value provided.")
        self.x = x
        self.y = y
        self.y_uncer = y_uncer
        self.reduced_chi2 = reducedChiSquared(model, fit_parameters, x, y, y_uncer, is_cutoff_model=self.is_cutoff_model, cutoff_value=self.cutoff_value)

    def __str__(self):
        return f"Experiment Name: {self.name}\n Model: {self.model}\n Parameters: {self.fit_parameters}\n Parameters_E: {self.fit_covariance}\n Reduced Chi2: {self.reduced_chi2}"

    def to_file_string(self):
        write_string = "################## Experiment Name: %s ##################\n" % self.name
        write_string += "Model: %s\n" % self.model.__name__
        write_string += "Is cutoff model: %s\n" % self.is_cutoff_model
        if self.is_cutoff_model:
            write_string += "Cutoff value: %s\n" % self.cutoff_value
        write_string += "Parameters: %s\n" % self.fit_parameters
        write_string += "Covariance matrix: %s\n" % self.fit_covariance
        write_string += "Reduced Chi2: %s\n" % self.reduced_chi2
        write_string += "X: %s\n" % self.x
        write_string += "Y: %s\n" % self.y
        write_string += "Y Uncertainty: %s\n" % self.y_uncer
        return write_string

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
        if name_parts[3] not in ["parabolic", "linear", "parabolic-cutoff", "exponential"]:
            ERROR.log(f"Experiment name {name} does not contain a valid shape.")
            return False
        return True
    
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
            
            # Do the predictions for the whole x_axis
            DEBUG.log(f"Making predictions for the x_axis: {x_axis} using the model: {self.model}")
            predictions = [self.make_single_prediction(x_value) for x_value in x_axis]
            y_pred = np.array([i.n for i in predictions])
            y_uncer = np.array([i.s for i in predictions])
            return y_pred, y_uncer
        
        else:
            ERROR.log(f"Invalid prediction mode: {mode}. Valid modes are 'function-extrapolation' and 'point-by-point'.")
            raise ValueError(f"Invalid prediction mode: {mode}. Valid modes are 'function-extrapolation' and 'point-by-point'.")
        
    def make_single_prediction(self, x_value):
        if x_value < 250 or x_value > 5000:
            ERROR.log(f"x_value {x_value} is out of bounds for the model. It should be between 250 and 5000.")
            raise ValueError(f"x_value {x_value} is out of bounds for the model. It should be between 250 and 5000.")
        
        # Construct the correlated values for the parameters
        params = correlated_values(self.fit_parameters, self.fit_covariance)

        if self.is_cutoff_model:
            DEBUG.log("Using cutoff model to do single prediction.")
            if x_value < self.cutoff_value:
                DEBUG.log(f"x_value {x_value} is below the cutoff value {self.cutoff_value}. Using the model normally.")
                return self.model(x_value, *params)
            else:
                DEBUG.log(f"x_value {x_value} is above the cutoff value {self.cutoff_value}. Using the cutoff model.")
                # First obtain the value from the normal model - this is to extract the uncertainty.
                pred = self.model(self.cutoff_value, *params, mass_limit=5000, level = 1)
                percentage_uncertainty = pred.s / pred.n
                # Now use the cutoff value to return the value at the cutoff
                pred = self.model(self.cutoff_value, *params, mass_limit=self.cutoff_value, level = self.model(self.cutoff_value, *params).n)
                return ufloat(pred.n, pred.n * percentage_uncertainty)

        DEBUG.log("Using normal model to do single prediction.")
        return self.model(x_value, *params)

# This class is a container for multiple FitExperiment objects                
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
                DEBUG.log(f"Experiment with name {name} found.")
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

    def write_experiments_to_file(self, file_name):
        # Check if the file exists and if it does, ask the user if they want to overwrite it
        import os
        if os.path.exists(f"results/{file_name}"):
            INFO.log(f"File results/{file_name} already exists. Do you want to overwrite it? (y/n)")
            overwrite = input().strip().lower() == 'y'
            if not overwrite:
                WARNING.log("Not overwriting the file. Returning without writing.")
                return

        # Write the experiments to the file
        with open(f"results/{file_name}", 'w') as f:
            for exp in self.experiments:
                f.write(exp.to_file_string())
        INFO.log(f"Experiments written to file results/{file_name}.")

# Perform the fit in mjj and add this to the experiments container
from scipy.optimize import curve_fit
def mjj_fit_experiment(model , x_axis, y_axis, y_uncer, experiment_name=None, experiments_container: FitExperimentContainer = None):
    if experiment_name is None:
        WARNING.log("No experiment name provided, results will not be stored.")
        return curve_fit(model, x_axis, y_axis, sigma=y_uncer)
    
    if experiments_container is None:
        WARNING.log("No experiments container provided, results will not be stored.")
        return curve_fit(model, x_axis, y_axis, sigma=y_uncer)

    fit_hint = None
    if 'exponential' in experiment_name:
        fit_hint = [ 0.001, 1.2, 1.5] # a, b, c
    if 'parabolic-cutoff' in experiment_name:
            DEBUG.log(f"Experiment {experiment_name} is a parabolic-cutoff model, vectorizing the model.")
            model = np.vectorize(model)
    fit_params, fit_covariance = curve_fit(model, x_axis, y_axis, sigma=y_uncer, p0=fit_hint)
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
    if 'SR' not in CR: # Only plot data points in the CRs
        plt.errorbar(x_axis, y_axis, yerr=y_uncer, fmt='.', label='(Data-BG)/QCDjj')
    plt.rcParams['text.usetex'] = True
    X = np.append(x_axis,5000.0)

    # Plot the fit experiments
    experiment_counter = 1
    for iexperiment in experiment_names:
        experiment = experiments_container.get_experiment(iexperiment)
        # Compute predictions taking care of numbers with uncertainties or just floats
        predictions = []
        for x in X:
            pred = experiment.make_single_prediction(x)
            try:
                pred = pred.n  # If it's a ufloat, get the nominal value
            except AttributeError:
                pred = float(pred)  # If it's a float, just use it
            predictions.append(pred)
        predictions = np.array(predictions)
        model_name = experiment.get_name_scheme()[3]
        plt.plot(X, predictions, label='Fit-%s' % (model_name if 'FromCutoffCRs' not in experiment.name else model_name + ' (with cutoff CRs)'))

        # Plot the GoF of the experiments
        font = {'color':  'black',
        'weight': 'normal',
        'size': 14,}
        gof = experiment.reduced_chi2
        if 'SR' not in CR: # Only plot the GoF in the CRs
            plt.text(0.05, (experiment_counter + 1)*0.04, '%s = %s' % (model_name,round(gof,2)),fontdict=font, transform = ax.transAxes)
        experiment_counter += 1

    if 'SR' not in CR: # Only plot the GoF in the CRs
        plt.text(0.05, 0.03, 'Reduced chi-squared: ',fontdict=font, transform = ax.transAxes)


    plt.legend()
    plt.xlabel(r'$m_{jj}$ [GeV]',fontsize=20,horizontalalignment='center')
    if 'SR' not in CR:
        plt.ylabel(r'$r_{k}$',fontsize=18)
    else:
        plt.ylabel(r'$f_{k}$',fontsize=18)
    plt.xlim(0,5000)
    plt.title("%s QCDjj: %s EWjj: %s" % (CR[:3] if "CR" in CR else "SR", QCD, EW),fontsize=18)
    plt.xticks(fontsize = 15)
    plt.yticks(fontsize = 15)
    

    # Save the figure if save is True, if not show it
    if save:
        if save_name is None:
            ERROR.log("No save name provided, cannot save the figure.")
            raise ValueError("No save name provided, cannot save the figure.")
        INFO.log(f"Saving the figure to results/{save_name}.pdf")
        plt.savefig(f"results/{save_name}.pdf", bbox_inches='tight')
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

if __name__ == "__main__":
    # This is a test to see if the module works correctly
    INFO.log("This is a library module for fitting Mjj distributions. Not meant to be run directly.")