from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG

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
    
def parabolic_cutoff_model_uncern(covariance_matrix,x_axis,x_axis_limit=5000,sigma=1.0):
    out = []
    for x in x_axis:
        if x<= x_axis_limit:
            sigma_a = covariance_matrix[0][0]
            sigma_b = covariance_matrix[1][1]
            sigma_c = covariance_matrix[2][2]
            
            cov_ab = covariance_matrix[0][1]
            cov_ac = covariance_matrix[0][2]
            cov_bc = covariance_matrix[1][2]
            
            diagonal_term = sigma_a*x**4 + sigma_b*x**2 + sigma_c
            no_diagonal_term = 2*cov_ab*x**3 + 2*cov_ac*x**2 + 2*cov_bc*x
            
            out.append(np.sqrt(diagonal_term+no_diagonal_term))
        else :
            out.append(sigma)
    return np.array(out)

# Test statistic
# Make fit parameters a list of variable length arguments
def reducedChiSquared(model, fitParameters, x,y,uncer):
    x = x[1:]
    y = y[1:]
    uncer = uncer[1:]
    chi=0
    for i in range(0,len(x)):
        chi+=((y[i]-model(x[i],*fitParameters))**2)/(uncer[i]**2)
        #print(x[i])
        #print(((y[i]-model(x[i],slope,level))**2)/(uncer[i]**2))
    return (chi/(len(x)-len(fitParameters)))


class FitExperiment:
    def __init__(self, name, model, fitParameters, x, y, y_uncer, chi2):
        if not self._check_name_scheme(name):
            ERROR.log(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
            raise ValueError(f"Experiment name {name} does not follow the required scheme: CRX_EWjj_QCDjj_shape")
        self.name = name
        self.model = model
        self.fitParameters = fitParameters
        self.x = x
        self.y = y
        self.y_uncer = y_uncer
        self.reduced_chi2 = chi2

    def __str__(self):
        return f"Experiment Name: {self.name}\n Model: {self.model}\n Parameters: {self.fitParameters}\n Reduced Chi2: {self.reduced_chi2}"
    
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
        return True
    
    def get_name_scheme(self):
        name_parts = self.name.split('_')
        CR = name_parts[0]  # Remove 'CR' prefix
        EW = name_parts[1][4:]  # Remove 'EWjj' prefix
        QCD = name_parts[2][5:]  # Remove 'QCDjj' prefix
        shape = name_parts[3]
        return CR, EW, QCD, shape


class FitExperimentContainer:
    def __init__(self):
        self.experiments = []

    def add_experiment(self, experiment: FitExperiment):
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
    chi_squared = reducedChiSquared(model, fit_params, x_axis, y_axis, y_uncer)
    new_experiment = FitExperiment(
        name=experiment_name,
        model=model,
        fitParameters=fit_params,
        x=x_axis,
        y=y_axis,
        y_uncer=y_uncer,
        chi2=chi_squared
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
        fit_params = experiment.fitParameters
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
    

