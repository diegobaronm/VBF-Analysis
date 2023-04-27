import os 
import ROOT as r

# Function to extract systematics names from the input file path and histogram name
def getSystematicsName(path, histogramName):
    # First, the shape systematics
    sysFiles = os.listdir(path)
    # Extract names of the samples associated with systematics by removing the .root extension and the NOMINAL string from file
    sampleNames = [i.replace('_NOMINAL.root','') for i in sysFiles if i.endswith('.root') and 'NOMINAL' in i]
    systematicShapeNames = []
    firstSampleString = sampleNames[0]
    for sysFile in sysFiles:
        if sysFile.endswith('.root') and firstSampleString in sysFile:
            # Remove .root and the first sample name from the file name
            name = sysFile.strip('.root').replace(firstSampleString+'_','')
            systematicShapeNames.append(name)

    # Second the ones in the NOMINAL file
    nominalFile = r.TFile.Open(path+firstSampleString+'_NOMINAL.root')
    systematicWeightNames = []
    for i in nominalFile.GetListOfKeys():
        histogramName = i.GetName()
        if "mass_jj_" in histogramName:
            systematicWeightNames.append(histogramName.replace('mass_jj_',''))
    
    return {'weightSys':systematicWeightNames, 'shapeSys':systematicShapeNames,'samples':sampleNames}


if __name__ == "__main__":
    r.TH1.AddDirectory(False)
    # Define paths of the two input channels
    path1 = "/Users/diegomac/Documents/HEP/VBF-Analysis/TauMu/Plots/Systematics/"
    path2 = "/Users/diegomac/Documents/HEP/VBF-Analysis/EleTau/Plots/Systematics/"
    targetPath = "/Users/diegomac/Documents/HEP/VBF-Analysis/TauTau/TauhadTaulep/AnalysisCrosscheck/Systematics/"

    systematics1 = getSystematicsName(path1, "mass_jj")
    systematics2 = getSystematicsName(path2, "mass_jj")
    
    # Extract the systematics names and the samples names
    sysWeight1 = systematics1['weightSys']
    sysWeight2 = systematics2['weightSys']
    sysShape1 = systematics1['shapeSys']
    sysShape2 = systematics2['shapeSys']
    samples = {'Ztautau_SherpaRW':['Ztautau_SherpaRW','Ztautau_SherpaRW'], 
               'Signal_Sherpa':['Signal_Sherpa','Signal_Sherpa']}

    # Get all the systematics names combined
    sysWeight = list(set(sysWeight1 + sysWeight2))
    sysShape = list(set(sysShape1 + sysShape2))

    # Get the nominal histogram for each sample and channel
    nominalHistograms = {}
    for targetSample,sourceSample in samples.items():
        histogram1 = r.TH1F(r.TFile.Open(path1+sourceSample[0]+"_NOMINAL.root").Get("mass_jj"))
        histogram2 = r.TH1F(r.TFile.Open(path2+sourceSample[1]+"_NOMINAL.root").Get("mass_jj"))
        nominalHistograms[targetSample] = [histogram1, histogram2]
    
    # First, process the shape systematics
    for targetSample,sourceSample in samples.items():
        for sysName in sysShape:
            # If the two channels have the same shape systematics, then we can add them using hadd
            if sysName in sysShape1 and sysName in sysShape2:
                print("Systematic "+sysName+" in both channels, adding them.")
                os.system("hadd -f "+targetPath+targetSample+"_"+sysName+".root "+path1+sourceSample[0]+"_"+sysName+".root "+path2+sourceSample[1]+"_"+sysName+".root")
                print("\n")
            # If only the first channel has the shape systematic, then we need to add the nominal histogram from the second channel
            elif sysName in sysShape1:
                # Create a root file in the target directory and write a histogram with the sum of the shape1 and nominal2 histograms
                print("Systematic "+sysName+" only in channel 1, adding NOMINAL of "+sourceSample[1])
                targetFile = r.TFile.Open(targetPath+targetSample+"_"+sysName+".root", "RECREATE")
                histoSystematic = r.TH1F(r.TFile.Open(path1+sourceSample[0]+"_"+sysName+".root").Get("mass_jj"))
                histoSystematic.Add(nominalHistograms[targetSample][1])
                targetFile.WriteTObject(histoSystematic, "mass_jj")
                targetFile.Close()
                print("\n")
            # Do the same for the second channel
            elif sysName in sysShape2:
                print("Systematic "+sysName+" only in channel 2, adding NOMINAL of "+sourceSample[0])
                targetFile = r.TFile.Open(targetPath+targetSample+"_"+sysName+".root", "RECREATE")
                histoSystematic = r.TH1F(r.TFile.Open(path2+sourceSample[1]+"_"+sysName+".root").Get("mass_jj"))
                histoSystematic.Add(nominalHistograms[targetSample][0])
                targetFile.WriteTObject(histoSystematic, "mass_jj")
                targetFile.Close()
                print("\n")

    # Now, process the weight systematics
    for targetSample,sourceSample in samples.items():
        for sysName in sysWeight:
            # Fist open the file in the target location with the NOMINAL name
            targetFile = r.TFile.Open(targetPath+targetSample+"_NOMINAL.root", "UPDATE")
            # If the two channels have the weight systematic, add the two histograms and write in the target file
            if sysName in sysWeight1 and sysName in sysWeight2:
                print("Systematic "+sysName+" in both channels, adding them.")
                histoSystematic1 = r.TH1F(r.TFile.Open(path1+sourceSample[0]+"_NOMINAL.root").Get("mass_jj_"+sysName))
                histoSystematic2 = r.TH1F(r.TFile.Open(path2+sourceSample[1]+"_NOMINAL.root").Get("mass_jj_"+sysName))
                histoSystematic1.Add(histoSystematic2)
                targetFile.WriteTObject(histoSystematic1, "mass_jj_"+sysName)
            # If only the first channel has the weight systematic, then we need to add the nominal histogram from the second channel
            elif sysName in sysWeight1:
                print("Systematic "+sysName+" only in channel 1, adding NOMINAL of "+sourceSample[1])
                histoSystematic1 = r.TH1F(r.TFile.Open(path1+sourceSample[0]+"_NOMINAL.root").Get("mass_jj_"+sysName))
                histoSystematic1.Add(nominalHistograms[targetSample][1])
                targetFile.WriteTObject(histoSystematic1, "mass_jj_"+sysName)
            # Do the same for the second channel
            elif sysName in sysWeight2:
                print("Systematic "+sysName+" only in channel 2, adding NOMINAL of "+sourceSample[0])
                histoSystematic2 = r.TH1F(r.TFile.Open(path2+sourceSample[1]+"_NOMINAL.root").Get("mass_jj_"+sysName))
                histoSystematic2.Add(nominalHistograms[targetSample][0])
                targetFile.WriteTObject(histoSystematic2, "mass_jj_"+sysName)
        
            targetFile.Close()
