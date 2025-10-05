import ROOT as r
import os
import numpy as np
import argparse
from uncertainties import ufloat, correlated_values
from uncertainties.umath import *

from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger
from Scripts.MjjFit import parabolic_model, exponential_model, linear_model
Logger.LOGLEVEL = 3

# Program constants

FIT_PARAMS = {"Sherpa_RWParabolicCutoff": [8.82838944E-08,-5.75209880E-04,1.43649628,2750.0],
              "SherpaNLO_RWParabolicCutoff" : [5.94966044e-08,-3.76772401e-04, 1.17521036, 2250.0],
              "MG_RWParabolicCutoff" : [6.54900406e-08,-3.82604146e-04, 9.17664656e-01, 2250.0],
              "MGNLO_RWParabolicCutoff" : [1.87328269e-08, -1.24610255e-05,  1.09966978, 2250.0],
              "Sherpa_RWParabolicCutoffClosure": [8.82838944E-08,-5.75209880E-04,1.43649628,2750.0],
              "SherpaNLO_RWParabolicCutoffClosure" : [5.94966044e-08,-3.76772401e-04, 1.17521036, 2250.0],
              "MG_RWParabolicCutoffClosure" : [6.54900406e-08,-3.82604146e-04, 9.17664656e-01, 2250.0],
              "MGNLO_RWParabolicCutoffClosure" : [1.87328269e-08, -1.24610255e-05,  1.09966978, 2250.0],
              "Sherpa_RWExponentialClosure" : [8.47307103E-04,1.06314779,1.54110821],
              "SherpaNLO_RWExponentialClosure" : [8.96860907e-04, 6.93896459e-01, 1.25625295],
              "MG_RWExponentialClosure" : [7.42436292e-04, 7.03633110e-01, 9.64192819e-01],
              "Sherpa_RWParabolic" : [8.82838944E-08,-5.75209880E-04,1.43649628],
              "MG_RWParabolic" : [6.54900406e-08,-3.82604146e-04, 9.17664656e-01],
              "Sherpa_Closure": [1.32414517e-04, 9.15044268e-01],
              "MG_Closure": [4.21819894e-05, 9.60973106e-01],
              "MGNLO_Closure": [2.52428835e-04, 8.42915241e-01],
              "SherpaNLO_Closure": [3.63250659e-05, 9.74936749e-01],
               }

FIT_COVARIANCE =  {"Sherpa_RWParabolicCutoff": [[ 4.20605912e-18, -1.05427079e-14,  5.06421195e-12],
                                                    [-1.05427079e-14,  2.95603005e-11, -1.56011963e-08],
                                                    [ 5.06421195e-12, -1.56011963e-08,  9.61124646e-06]],
                     "SherpaNLO_RWParabolicCutoff": [[ 2.06553470e-17, -8.20011301e-14,  4.90184092e-11],
                                                    [-8.20011301e-14,  3.64367633e-10, -2.33870975e-07],
                                                    [ 4.90184092e-11, -2.33870975e-07,  1.80087363e-04]],
                     "MG_RWParabolicCutoff": [[ 6.28300443e-17, -2.44733463e-13,  1.45860273e-10],
                                                [-2.44733463e-13,  1.07657090e-09, -6.89771768e-07],
                                                [ 1.45860273e-10, -6.89771768e-07,  5.26126101e-04]],
                     "MGNLO_RWParabolicCutoff": [[ 1.25043836e-16, -4.22720216e-13,  2.17411396e-10],
                                                [-4.22720216e-13,  1.71261502e-09, -9.58016471e-07],
                                                [ 2.17411396e-10, -9.58016471e-07,  6.38964869e-04]],
                    "Sherpa_RWParabolicCutoffClosure": [[ 4.20605912e-18, -1.05427079e-14,  5.06421195e-12],
                                                    [-1.05427079e-14,  2.95603005e-11, -1.56011963e-08],
                                                    [ 5.06421195e-12, -1.56011963e-08,  9.61124646e-06]],
                     "SherpaNLO_RWParabolicCutoffClosure": [[ 2.06553470e-17, -8.20011301e-14,  4.90184092e-11],
                                                    [-8.20011301e-14,  3.64367633e-10, -2.33870975e-07],
                                                    [ 4.90184092e-11, -2.33870975e-07,  1.80087363e-04]],
                     "MG_RWParabolicCutoffClosure": [[ 6.28300443e-17, -2.44733463e-13,  1.45860273e-10],
                                                [-2.44733463e-13,  1.07657090e-09, -6.89771768e-07],
                                                [ 1.45860273e-10, -6.89771768e-07,  5.26126101e-04]],
                     "MGNLO_RWParabolicCutoffClosure": [[ 1.25043836e-16, -4.22720216e-13,  2.17411396e-10],
                                                [-4.22720216e-13,  1.71261502e-09, -9.58016471e-07],
                                                [ 2.17411396e-10, -9.58016471e-07,  6.38964869e-04]],
                     "Sherpa_RWExponentialClosure": [[ 5.70295287e-10, -1.39309227e-07,  1.55388883e-07],
                                                [-1.39309227e-07,  9.14875204e-05, -8.28027500e-06],
                                                [ 1.55388883e-07, -8.28027500e-06,  5.94002775e-05]],
                     "SherpaNLO_RWExponentialClosure": [[ 2.37155393e-09, -3.31116570e-07,  4.15405141e-07],
                                                    [-3.31116570e-07,  1.38673767e-04, -9.34866513e-06],
                                                    [ 4.15405141e-07, -9.34866513e-06,  1.01018969e-04]],
                     "MG_RWExponentialClosure": [[ 5.36921036e-11, -1.05729868e-08,  1.06524362e-08],
                                            [-1.05729868e-08,  5.75756160e-06, -2.94019349e-07],
                                            [ 1.06524362e-08, -2.94019349e-07,  3.10751010e-06]],
                     "Sherpa_RWParabolic": [[ 4.20605912e-18, -1.05427079e-14,  5.06421195e-12],
                                            [-1.05427079e-14,  2.95603005e-11, -1.56011963e-08],
                                            [ 5.06421195e-12, -1.56011963e-08,  9.61124646e-06]],
                     "MG_RWParabolic": [[ 6.28300443e-17, -2.44733463e-13,  1.45860273e-10],
                                        [-2.44733463e-13,  1.07657090e-09, -6.89771768e-07],
                                        [ 1.45860273e-10, -6.89771768e-07,  5.26126101e-04]],
                     "Sherpa_Closure": [[ 6.22183566e-10, -4.86375579e-07],
                                          [-4.86375579e-07,  5.14027312e-04]],
                     "MG_Closure": [[ 5.01070485e-09, -3.38644698e-06],
                                      [-3.38644698e-06,  3.05006567e-03]],
                     "MGNLO_Closure": [[ 2.72316965e-09, -1.66491926e-06],
                                         [-1.66491926e-06,  1.23410973e-03]],
                     "SherpaNLO_Closure":  [[ 9.70273239e-11, -7.86988760e-08],
                                                [-7.86988760e-08,  8.42092075e-05]],
                     }

def custom_parabolic_cutoff_model(x, a, b, c, cutoff):
    if x < cutoff:
        return a * x**2 + b * x + c
    else:
        return a * cutoff**2 + b * cutoff + c


FUNCTIONS_DICT = {
    "RWParabolic" : parabolic_model,
    "RWExponentialClosure" : exponential_model,
    "RWParabolicCutoff" : custom_parabolic_cutoff_model,
    "RWParabolicCutoffClosure" : custom_parabolic_cutoff_model,
}

REMOTE_PATH = "/afs/cern.ch/work/d/dbaronmo/private/Fitter/"

def get_generator_rw_tag(sample_name):
    # Find the first occurrence of of "_" in the sample name
    underscore_index = sample_name.find("_")
    if underscore_index == -1:
        raise ValueError("Sample name does not contain an underscore: " + sample_name)
    # Extract the substring after underscore
    return sample_name[underscore_index + 1:-5] # To remove the ".root" at the end

def rw_tag(generator_rw_tag):
    # Find the first occurrence of of "_" in the sample name
    underscore_index = generator_rw_tag.find("_")
    if underscore_index == -1:
        raise ValueError("Sample name does not contain an underscore: " + generator_rw_tag)
    # Extract the substring after underscore
    return generator_rw_tag[underscore_index + 1:]

def generator_tag(generator_rw_tag):
    # Find the first occurrence of of "_" in the sample name
    underscore_index = generator_rw_tag.find("_")
    if underscore_index == -1:
        raise ValueError("Sample name does not contain an underscore: " + generator_rw_tag)
    # Extract the substring before underscore
    return generator_rw_tag[:underscore_index]


def scaleBinUncertainty(histogram,sampleName):

    generator_rw_tag = get_generator_rw_tag(sampleName)
    INFO.log("Modifiying weights of generator = ", generator_rw_tag)
    rw_function = FUNCTIONS_DICT[rw_tag(generator_rw_tag)]
    INFO.log("RW function = ", rw_tag(generator_rw_tag))
    
    for i in range(1,histogram.GetNbinsX()+1):
        # 1) Data-driven RW.
        # Get the current bin center and error
        x = histogram.GetBinCenter(i)
        error = histogram.GetBinError(i)

        # Treat the cutoff case specially
        if "Cutoff" in generator_rw_tag:
            # Make the fit parameters and covariance matrix available for the RW 
            params = correlated_values(FIT_PARAMS[generator_rw_tag][0:3], FIT_COVARIANCE[generator_rw_tag])
            cutoff_pred = rw_function(x, *params, cutoff=FIT_PARAMS[generator_rw_tag][3])

            # Before cutoff, use just the prediction 
            if x < FIT_PARAMS[generator_rw_tag][3]: 
                rw = cutoff_pred.nominal_value
                rw_error = cutoff_pred.std_dev
            # After cutoff, we need the fractional uncertainty given by the no-cutoff prediction
            else:
                no_cutoff_pred = rw_function(x, *params, cutoff=6000.0)
                relative_no_cutoff_error = no_cutoff_pred.std_dev / no_cutoff_pred.nominal_value
                rw = cutoff_pred.nominal_value
                rw_error = cutoff_pred.nominal_value * relative_no_cutoff_error

            DEBUG.log("Bin x: %s RW prediction: %s +- %s" % (x, rw, rw_error))
        else:
            params = correlated_values(FIT_PARAMS[generator_rw_tag], FIT_COVARIANCE[generator_rw_tag])
            pred = rw_function(x, *params)
            rw = pred.nominal_value
            rw_error = pred.std_dev
            DEBUG.log("Bin x: %s RW prediction: %s" % (x, pred))

        # Do the scaling
        newError = np.sqrt(error**2 + ((rw_error/rw)**2)*(error**2))
        DEBUG.log("Bin: %d | Old error: %f | New error: %f" % (i, error, newError))
        histogram.SetBinError(i,newError)

        # 2) MC-driven closure RW.
        # Get the current bin center and error
        x = histogram.GetBinCenter(i)
        error = histogram.GetBinError(i)

        # Check if the sample was affected by thus RW type
        if "Closure" in generator_rw_tag:
            DEBUG.log("Doing MC-driven closure RW uncertainty adjustment.")
            # Form the key = generator + "_Closure"
            closure_key = generator_tag(generator_rw_tag) + "_Closure"
            # Load parameters and predict
            params = correlated_values(FIT_PARAMS[closure_key], FIT_COVARIANCE[closure_key])
            pred = linear_model(x, *params)
            # Extract the RW value and error
            rw = pred.nominal_value
            rw_error = pred.std_dev
            DEBUG.log("Bin x: %s RW prediction: %s" % (x, pred))
            # Update the uncertianty
            newError = np.sqrt(error**2 + ((rw_error/rw)**2)*(error**2))
            DEBUG.log("Bin: %d | Old error: %f | New error: %f" % (i, error, newError))
            histogram.SetBinError(i,newError)

def channel(path):
    if "MuMu" in path:
        return "Zmumu"
    elif "Zee" in path:
        return "Zee"
    elif "TauTau" in path or "MuEle" in path:
        return "Ztautau"
    elif "Zll" in path:
        return "Zll"
    else :
        raise ValueError("Path not found")

# Step 1: Gather the correct files and samples.

def gather_samples(localPath, add_systematics = False):

    dataSamples = ['Data.root']
    signalSamples = ['Signal_Sherpa.root','Signal_PoPy.root']
    qcdSamples = ["%s_%s.root" % (channel(localPath), i) for i in FIT_PARAMS.keys() if 'RW' in i]
    backgroundSamples = ['Wjets.root','VV.root',"ttbar.root",'singletop.root','VV_EWK.root']
    if "Tau" in localPath or "MuEle" in localPath:
        backgroundSamples += ['Higgs.root','Higgs_truth_EWK.root','Zjets.root','W_EWK_Sherpa.root','MJ.root']

    samples = dataSamples + signalSamples + qcdSamples + backgroundSamples

    if add_systematics:
        # Look for files with the SYS tag in the name
        sys_samples = [file for file in os.listdir(localPath) if (file.endswith('.root') and 'SYS' in file)]
        if len(sys_samples) == 0:
            ERROR.log("No systematic samples found in the provided local path.")
            exit(1)
        # Print the found systematic samples and make the user confirm
        INFO.log("Found the following systematic samples: ", sys_samples)
        user_input = input("Do you want to include these systematic samples? (y/n): ")
        if user_input.lower() != 'y':
            INFO.log("User opted not to include systematic samples. Exiting.")
            exit(0)
        
        # Add the systematic samples to the list of samples to be processed
        samples += sys_samples

    # Final check: ensure all samples exist in the local path
    final_samples = samples.copy()
    for sample in samples:
        if not os.path.isfile(localPath+sample):
            WARNING.log("Sample not found: %s . Dropping it from the list." % sample)
            final_samples.remove(sample)

    return final_samples

# Step 2: Correct QCDjj uncertainties.

def correct_qcd_uncertainties(localPath, samples):

    histogramNames = ["mass_jj"] # NOTE: This is hardcoded for this analysis.

    # Open the output file
    outputFile = r.TFile.Open(channel(localPath)+"histograms.root","RECREATE")

    for sample in samples:
        for histogramName in histogramNames:
            file = r.TFile.Open(localPath+sample,"READ")

            # For no systematics samples...
            if "SYS" not in sample:
                histogram = file.Get(histogramName)
                if "RW" in sample:
                    INFO.log(sample)
                    scaleBinUncertainty(histogram,sample)
                # Include NOMINAL tag to samples used for systematics    
                if "Signal_Sherpa" in sample[:-5] or "SherpaNLO_RWParabolicCutoff" in sample[:-5]:
                    outputFile.WriteObject(histogram,histogramName+"_"+sample[:-5]+'_NOMINAL')
                else :
                    outputFile.WriteObject(histogram,histogramName+"_"+sample[:-5])
                file.Close()
            else:
                # For systematic samples... all the histograms in the file should be included.
                list_of_histograms = [key.GetName() for key in file.GetListOfKeys() if key.GetName().startswith(histogramName)]
                sample = sample.replace("_SYS","") # Remove the SYS tag for naming consistency
                for sys_histogram_name in list_of_histograms:
                    histogram = file.Get(sys_histogram_name)
                    save_name = histogramName+'_'+sample[:-5]+sys_histogram_name.replace(histogramName,'')
                    if "RW" in sample:
                        INFO.log("Scaling systematic...")
                        scaleBinUncertainty(histogram,sample)
                    outputFile.WriteObject(histogram,save_name)
                file.Close()
    
    outputFile.Close()

# Step 4: Upload the file.

def upload_file(remotePath, localPath, outputName):
    if not outputName.endswith(".root"):
        ERROR.log("Output name must end with .root")
        exit(1)

    exitStatus = os.system("scp "+channel(localPath)+"histograms.root "+"dbaronmo@lxplus.cern.ch:"+remotePath+outputName)
    if exitStatus==0:
        INFO.log("Sample Uploaded!")

def main():
    parser = argparse.ArgumentParser(description="Create TRExFitter inputs for VBF Analysis.")
    parser.add_argument("--remote-path", type=str, default=REMOTE_PATH, help="Path to the remote directory where the files will be uploaded.")
    parser.add_argument("local_path", type=str, help="Path to the local directory where the files are stored.")
    parser.add_argument("output_name", type=str, help="Name of the output file to be created.")
    parser.add_argument("--sys", action='store_true', help="Pass this flag to add systematics to the output file.")
    args = parser.parse_args()

    if args.sys:
        INFO.log("Adding systematics to the output file...")

    INFO.log("Gathering samples from the local path: ", args.local_path)
    list_of_samples = gather_samples(args.local_path, add_systematics = args.sys)
    INFO.log("Gathered samples: ", list_of_samples)


    INFO.log("Correcting QCDjj uncertainties...")
    correct_qcd_uncertainties(args.local_path, list_of_samples)
    INFO.log("QCDjj uncertainties corrected.")

    INFO.log("Uploading the file to the remote path...")
    upload_file(args.remote_path, args.local_path, args.output_name)


if __name__ == "__main__":
    main()
    INFO.log("Script finished successfully.")