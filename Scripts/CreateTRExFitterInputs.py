import ROOT as r
import os
import numpy as np
import argparse
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG


# Program constants

fitParams = {"Sherpa": [ 1.29830478e-07, -6.86843818e-04,  1.49385117e+00],
              "SherpaNLO" : [ 9.82221362e-08, -4.74780468e-04,  1.21850173e+00],
              "MG" : [ 1.43497535e-07, -5.60660936e-04,  9.95732869e-01],
               "MGNLO" : [ 1.31215631e-07, -2.44056445e-04,  1.18831132e+00]}

covarianceMatrix =  {"Sherpa" : [[ 4.37933189e-17, -9.78166325e-14,  4.33532089e-11],
                                 [-9.78166325e-14,  2.38588198e-10, -1.15458381e-07],
                                 [ 4.33532089e-11, -1.15458381e-07,  6.46145772e-05]],
                     "SherpaNLO" : [[ 4.88721411e-17, -1.04467382e-13,  4.43766971e-11],
                                    [-1.04467382e-13,  2.43818533e-10, -1.12809488e-07],
                                    [ 4.43766971e-11, -1.12809488e-07,  6.00411993e-05]],
                    "MG" : [[ 4.29977493e-17, -9.10704127e-14,  3.87653933e-11],
                            [-9.10704127e-14,  2.10011698e-10, -9.70820577e-08],
                            [ 3.87653933e-11, -9.70820577e-08,  5.12322795e-05]],
                    "MGNLO" : [[ 2.96293197e-16, -5.64587228e-13,  2.15110041e-10],
                               [-5.64587228e-13,  1.20075868e-09, -5.04193636e-07],
                               [ 2.15110041e-10, -5.04193636e-07,  2.45157055e-04]]}

remotePath = "/afs/cern.ch/work/d/dbaronmo/private/Fitter/"

# Functions to calculate the uncertainties based on the covariance matrix and the parabolic shape of the reweighting function

def model_uncern(covariance_matrix,x):
    var_a = covariance_matrix[0][0]
    var_b = covariance_matrix[1][1]
    var_c = covariance_matrix[2][2]
    
    cov_ab = covariance_matrix[0][1]
    cov_ac = covariance_matrix[0][2]
    cov_bc = covariance_matrix[1][2]
    
    diagonal_term = var_a*(x**4) + var_b*(x**2) + var_c
    no_diagonal_term = 2*cov_ab*(x**3) + 2*cov_ac*(x**2) + 2*cov_bc*x
    
    return np.sqrt(diagonal_term+no_diagonal_term)

def parabolic_shape(mjj,parameters):
    a = parameters[0]
    b = parameters[1]
    c = parameters[2]
    return a*mjj*mjj+b*mjj+c

# Vectorize the functions to apply them to numpy arrays

model_uncer = np.vectorize(model_uncern)
parabolic_shape = np.vectorize(parabolic_shape,excluded=['parameters'])

def scaleBinUncertainty(histogram,sampleName):
    
    generator = sampleName.split("_")[1][:-5]
    generator = generator.replace("RW","")
    generator = generator.replace("2","") # For MGNLO samples
    INFO.log("Modifiying weights of generator = ",generator)
    
    for i in range(1,histogram.GetNbinsX()+1):
        x = histogram.GetBinCenter(i)
        error = histogram.GetBinError(i)
        # Get the errors for the parabolic part of the RW
        rw = parabolic_shape(x,parameters=fitParams[generator])
        rw_error = model_uncern(covarianceMatrix[generator],x)
        
        # Parameters that we apply for the flat part of the distribution
        # The dictionary structure is sampleName : [mjj-value-where-flatRW-starts,rw-value,rw-error]
        flatRWParameters = {"MGNLO":[2250,1.5,0.9],"SherpaNLO":[2750,0.8,0.4],"Sherpa":[2750,0.6,0.4],"MG":[2750,0.5,0.4]}
        
        if (x > flatRWParameters[generator][0]): # Check the current m-jj value to apply the correct error modification
            newError = np.sqrt(error**2 + ((flatRWParameters[generator][2]/flatRWParameters[generator][1])**2)*(error**2))
        else :
            newError = np.sqrt(error**2 + ((rw_error/rw)**2)*(error**2))
        histogram.SetBinError(i,newError)
        #if (i%249==0):
            #INFO.log("Error change in bin = ",x," is ",round(100*(newError-error)/error,2))

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
    
# TODO: Adapt this function to the other part of the code.
def add_systematics():
    from SystematicsAdd import getSystematicsName

    systematicsPath = '/Users/user/Documents/HEP/VBF-Analysis/VBFAnalysisPlots/TauTau/Z-peak/Systematics/'
    systematicSamples = ['Signal_Sherpa.root',channel(systematicsPath)+'_SherpaRW.root']

    # Extract the systematics names
    systematicNames = getSystematicsName(systematicsPath,'mass_jj')
    systematicShapeNames = systematicNames['shapeSys']
    systematicWeightNames = systematicNames['weightSys']

    # Clean single SFs identified with tags (only for Z->ll samples --- put something that does not remove anything for Z->tautau) ['elec_0','elec_1','muon_0','muon_1']
    tags = ['elec_x','elec_x','muon_x','muon_x']
    removeNames = []
    for systematicName in systematicWeightNames:
        for tag in tags:
            if tag in systematicName:
                removeNames.append(systematicName)
    for removeSys in removeNames:
        INFO.log('Removing ... ',removeSys)
        systematicWeightNames.remove(removeSys)

    # Open the output file        
    outputFile = r.TFile.Open(channel(localPath)+"histograms.root","UPDATE")

    # Clean the nominal samples
    #for sample in systematicSamples:
        #INFO.log("mass_jj"+sample[:-5]+";*")
        #outputFile.Delete("mass_jj_"+sample[:-5]+";*")

    # Fill shape systematics (NOMINAL Shape is extracted here)
    for sample in systematicSamples:
        
        for systematicName in systematicShapeNames:
            file = r.TFile.Open(systematicsPath+sample[:-5]+'_'+systematicName+'.root',"READ")
            histogram = file.Get("mass_jj")

            if "RW" in sample:
                scaleBinUncertainty(histogram,sample)
                
            if "NOMINAL" in systematicName:
                outputFile.WriteObject(histogram,"mass_jj"+"_"+sample[:-5])
            else:
                outputFile.WriteObject(histogram,"mass_jj"+"_"+sample[:-5]+'_'+systematicName)

    # Fill weight systematics        
    for sample in systematicSamples:
        
        for systematicName in systematicWeightNames:
            file = r.TFile.Open(systematicsPath+sample[:-5]+'_NOMINAL.root',"READ")
            histogram = file.Get("mass_jj"+'_'+systematicName)

            if "RW" in sample:
                scaleBinUncertainty(histogram,sample)

            outputFile.WriteObject(histogram,"mass_jj"+"_"+sample[:-5]+'_'+systematicName)
            
            
    outputFile.Close()


# Step 1: Gather the correct files and samples.

def gather_samples(localPath):

    dataSamples = ['Data.root']
    signalSamples = ['Signal_Sherpa.root','Signal_PoPy.root']
    qcdSamples = [channel(localPath)+i for i in ["_SherpaRW.root",#"_SherpaRW-Alternative.root",
                                                "_MGRW.root",#"_MGRW-Alternative.root",
                                                "_MGNLORW.root", "_SherpaNLORW.root",
                                                ]]
    backgroundSamples = ['Wjets.root','VV.root',"ttbar.root",'singletop.root']
    if "Tau" in localPath or "MuEle" in localPath:
        backgroundSamples += ['Higgs.root','Higgs_EWK.root','Zjets.root','W_EWK_Sherpa.root','VV_EWK.root','MJ.root']
        
    samples = dataSamples+signalSamples+qcdSamples+backgroundSamples

    return samples

# Step 2: Correct QCDjj uncertainties.

def correct_qcd_uncertainties(localPath, samples):

    histogramNames = ["mass_jj"]

    outputFile = r.TFile.Open(channel(localPath)+"histograms.root","RECREATE")

    for sample in samples:
        for histogramName in histogramNames:
            file = r.TFile.Open(localPath+sample,"READ")
            histogram = file.Get(histogramName)
            
            if "RW" in sample:
                INFO.log(sample)
                scaleBinUncertainty(histogram,sample)
            
            # Include NOMINAL tag to samples used for systematics    
            if "Signal_Sherpa" in sample[:-5] or "SherpaRW" in sample[:-5]:
                outputFile.WriteObject(histogram,histogramName+"_"+sample[:-5]+'_NOMINAL')
            else :
                outputFile.WriteObject(histogram,histogramName+"_"+sample[:-5])
            file.Close()
            
    outputFile.Close()

# Step 3 (optional): Add systematics to the output file.
# TODO: Look to the add_systematics() function.

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
    parser.add_argument("--remote-path", type=str, default=remotePath, help="Path to the remote directory where the files will be uploaded.")
    parser.add_argument("local_path", type=str, help="Path to the local directory where the files are stored.")
    parser.add_argument("output_name", type=str, help="Name of the output file to be created.")
    args = parser.parse_args()

    INFO.log("Gathering samples from the local path: ", args.local_path)
    list_of_samples = gather_samples(args.local_path)
    INFO.log("Gathered samples: ", list_of_samples)

    INFO.log("Correcting QCDjj uncertainties...")
    correct_qcd_uncertainties(args.local_path, list_of_samples)
    INFO.log("QCDjj uncertainties corrected.")

    INFO.log("Uploading the file to the remote path...")
    upload_file(args.remote_path, args.local_path, args.output_name)



if __name__ == "__main__":
    main()
    INFO.log("Script finished successfully.")