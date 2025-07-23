import os
import sys
from argparse import ArgumentParser

from HandleIO.CreateListToRun import menu
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger, CreateOutputsDir
Logger.LOGLEVEL = 3

hadd_ee = {
"Zee_Sherpa.root" : ["Zee_sherpa*.root"],
"Zee_PoPy.root" : ["Zee_201*.root"],
"Zee_MGNLO.root" : ["Zee_MGNLO*.root"],
"Zee_MG.root" : ["Zee_MG[!NLO]*.root"],
"Zee_SherpaNLO.root" : ["Zee_SherpaNLO*.root"],
"Signal_old.root" : ["VBF_Zee_old_201*.root"],
"Signal_Sherpa.root" : ["VBF_Zee_sherpa_201*.root"],
"Signal_PoPy.root" : ["VBF_Zee_201*.root"],
"Ztautau_PoPy.root" : ["Ztautau_*.root"],
"Zmumu.root" : ["Zmumu_201*.root"],
"VV.root" : ["llll_*.root", "lllv_*.root", "llvv_*.root", "lvvv_*.root", "ZqqZvv_*.root", "ZqqZll_*.root", "WqqZvv_*.root", "WqqZll_*.root", "WlvZqq_*.root"],
"Wjets.root" : ["Wplusenu_*.root", "Wminusenu_*.root", "Wplusmunu_*.root", "Wminusmunu_*.root", "Wplustaunu_*.root", "Wminustaunu_*.root"],
"singletop.root" : ["st_schan_top_*.root", "st_schan_atop_*.root", "st_tchan_top_*.root", "st_tchan_atop_*.root", "st_wt_top_*.root", "st_wt_atop_*.root"],
"ttbar.root" : ["ttbar_*.root"],
"Data.root" : ["data_*.root"],
"VV_EWK.root" : ["VV_EWK*.root"],		
"W_EWK_Sherpa.root" : ["W_EWK_sherpa*.root"],
"W_EWK_PoPy.root" : ["W_EWK_PoPy*.root"],
}

hadd_mumu = {
"Zmumu_Sherpa.root" : ["Zmumu_sherpa*.root"],
"Zmumu_PoPy.root" : ["Zmumu_201*.root"],
"Zmumu_MGNLO.root" : ["Zmumu_MGNLO*.root"],
"Zmumu_MG.root" : ["Zmumu_MG[!NLO]*.root"],
"Zmumu_SherpaNLO.root" : ["Zmumu_SherpaNLO*.root"],
"Signal_old.root" : ["VBF_Zmumu_old_201*.root"],
"Signal_Sherpa.root" : ["VBF_Zmumu_sherpa_201*.root"],
"Signal_PoPy.root" : ["VBF_Zmumu_201*.root"],
"Ztautau_PoPy.root" : ["Ztautau_*.root"],
"Zee.root" : ["Zee_201*.root"],
"VV.root" : ["llll_*.root", "lllv_*.root", "llvv_*.root", "lvvv_*.root", "ZqqZvv_*.root", "ZqqZll_*.root", "WqqZvv_*.root", "WqqZll_*.root", "WlvZqq_*.root"],
"Wjets.root" : ["Wplusenu_*.root", "Wminusenu_*.root", "Wplusmunu_*.root", "Wminusmunu_*.root", "Wplustaunu_*.root", "Wminustaunu_*.root"],
"singletop.root" : ["st_schan_top_*.root", "st_schan_atop_*.root", "st_tchan_top_*.root", "st_tchan_atop_*.root", "st_wt_top_*.root", "st_wt_atop_*.root"],
"ttbar.root" : ["ttbar_*.root"],
"Data.root" : ["data_*.root"],
"VV_EWK.root" : ["VV_EWK*.root"],	
"W_EWK_Sherpa.root" : ["W_EWK_sherpa*.root"],
"W_EWK_PoPy.root" : ["W_EWK_PoPy*.root"],
}

hadd_mutau = {
"Signal_Sherpa.root": ["VBF_Ztautau_sherpa_20*.root"],
"Signal_PoPy.root": ["VBF_Ztautau_201*.root"],
"Signal_truth_Sherpa.root": ["VBF_Ztautau_sherpa_truth_20*.root"],
"Signal_truth_PoPy.root": ["VBF_Ztautau_truth_201*.root"],
"Ztautau_Sherpa.root": ["Ztautau_sherpa*.root"],
"Ztautau_PoPy.root": ["Ztautau_201*.root"],
"Ztautau_MG.root": ["Ztautau_MG[!NLO]*.root"],
"Ztautau_MGNLO.root": ["Ztautau_MGNLO*.root"],
"Ztautau_SherpaNLO.root": ["Ztautau_SherpaNLO*.root"],
"Zjets.root": ["Zmumu_201*.root"],
"Higgs.root": ["WpH*.root WmH*.root", "ZHllbb*.root", "ZHlltautau*.root", "ggHttlm15hp20*.root", "ggHttlp15hm20*.root"],
"Higgs_EWK.root": ["VBFHttlm15hp20*.root", "VBFHttlp15hm20*.root"],
"VV.root": ["llll_*.root", "lllv_*.root", "llvv_*.root", "lvvv_*.root", "ZqqZvv_*.root", "ZqqZll_*.root", "WqqZvv_*.root", "WqqZll_*.root", "WlvZqq_*.root"],
"Wjets.root": ["Wplusenu_*.root", "Wminusenu_*.root", "Wplusmunu_*.root", "Wminusmunu_*.root", "Wplustaunu_*.root", "Wminustaunu_*.root"],
"singletop.root": ["st_schan_top_*.root", "st_schan_atop_*.root", "st_tchan_top_*.root", "st_tchan_atop_*.root", "st_wt_top_*.root", "st_wt_atop_*.root"],
"ttbar.root": ["ttbar_*.root"],
"W_EWK_Sherpa.root": ["W_EWK_sherpa*.root"],
"W_EWK_PoPy.root": ["W_EWK_PoPy*.root"],
"VV_EWK.root": ["VV_EWK*.root"],
"Data.root": ["data_*.root"],
}

hadd_etau = {
"Signal_Sherpa.root": ["VBF_Ztautau_sherpa_20*.root"],
"Signal_PoPy.root": ["VBF_Ztautau_201*.root"],
"Signal_truth_Sherpa.root": ["VBF_Ztautau_sherpa_truth_20*.root"],
"Signal_truth_PoPy.root": ["VBF_Ztautau_truth_201*.root"],
"Ztautau_Sherpa.root": ["Ztautau_sherpa*.root"],
"Ztautau_PoPy.root": ["Ztautau_201*.root"],
"Ztautau_MG.root": ["Ztautau_MG[!NLO]*.root"],
"Ztautau_MGNLO.root": ["Ztautau_MGNLO*.root"],
"Ztautau_SherpaNLO.root": ["Ztautau_SherpaNLO*.root"],
"Zjets.root": ["Zmumu_201*.root","Zee_201*.root"],
"Higgs.root": ["WpH*.root WmH*.root", "ZHllbb*.root", "ZHlltautau*.root", "ggHttlm15hp20*.root", "ggHttlp15hm20*.root"],
"Higgs_EWK.root": ["VBFHttlm15hp20*.root", "VBFHttlp15hm20*.root"],
"VV.root": ["llll_*.root", "lllv_*.root", "llvv_*.root", "lvvv_*.root", "ZqqZvv_*.root", "ZqqZll_*.root", "WqqZvv_*.root", "WqqZll_*.root", "WlvZqq_*.root"],
"Wjets.root": ["Wplusenu_*.root", "Wminusenu_*.root", "Wplusmunu_*.root", "Wminusmunu_*.root", "Wplustaunu_*.root", "Wminustaunu_*.root"],
"singletop.root": ["st_schan_top_*.root", "st_schan_atop_*.root", "st_tchan_top_*.root", "st_tchan_atop_*.root", "st_wt_top_*.root", "st_wt_atop_*.root"],
"ttbar.root": ["ttbar_*.root"],
"W_EWK_Sherpa.root": ["W_EWK_sherpa*.root"],
"W_EWK_PoPy.root": ["W_EWK_PoPy*.root"],
"VV_EWK.root": ["VV_EWK*.root"],
"Data.root": ["data_*.root"],
}

hadd_emu ={
"Signal_Sherpa.root": ["VBF_Ztautau_sherpa_20*.root"],
"Signal_PoPy.root": ["VBF_Ztautau_201*.root"],
"Signal_truth_Sherpa.root": ["VBF_Ztautau_sherpa_truth_20*.root"],
"Signal_truth_PoPy.root": ["VBF_Ztautau_truth_201*.root"],
"Ztautau_Sherpa.root": ["Ztautau_sherpa*.root"],
"Ztautau_PoPy.root": ["Ztautau_201*.root"],
"Ztautau_MG.root": ["Ztautau_MG[!NLO]*.root"],
"Ztautau_MGNLO.root": ["Ztautau_MGNLO*.root"],
"Ztautau_SherpaNLO.root": ["Ztautau_SherpaNLO*.root"],
"Zjets.root": ["Zmumu_201*.root","Zee_201*.root"],
"Higgs.root": ["WpH*.root WmH*.root", "ZHllbb*.root", "ZHlltautau*.root", "ggHttlm15hp20*.root", "ggHttlp15hm20*.root"],
"Higgs_EWK.root": ["VBFHttlm15hp20*.root", "VBFHttlp15hm20*.root"],
"VV.root": ["llll_*.root", "lllv_*.root", "llvv_*.root", "lvvv_*.root", "ZqqZvv_*.root", "ZqqZll_*.root", "WqqZvv_*.root", "WqqZll_*.root", "WlvZqq_*.root"],
"Wjets.root": ["Wplusenu_*.root", "Wminusenu_*.root", "Wplusmunu_*.root", "Wminusmunu_*.root", "Wplustaunu_*.root", "Wminustaunu_*.root"],
"singletop.root": ["st_schan_top_*.root", "st_schan_atop_*.root", "st_tchan_top_*.root", "st_tchan_atop_*.root", "st_wt_top_*.root", "st_wt_atop_*.root"],
"ttbar.root": ["ttbar_*.root"],
"W_EWK_Sherpa.root": ["W_EWK_sherpa*.root"],
"W_EWK_PoPy.root": ["W_EWK_PoPy*.root"],
"VV_EWK.root": ["VV_EWK*.root"],
"Data.root": ["data_*.root"],
}

# Function to add the Zprime pairs between 200 and 500 GeV.
def add_Zprime_samples(hadd_dict):
	for mass in range(200,550,50):
		hadd_dict[f'Zprime_{mass}.root'] = [f'VBF_Zprime_{mass}*.root']

# Add Zprime samples to tauhad-taulep channels.
add_Zprime_samples(hadd_etau)
add_Zprime_samples(hadd_mutau)

hadd_dictionaries = {'MuMu': hadd_mumu,
					 'Zee': hadd_ee,
					 'TauMu': hadd_mutau,
					 'EleTau': hadd_etau,
					 'MuEle': hadd_emu,}

def hadd_datasets(channel_dict, input_path, output_path, filter_string=None):
	# Loop trough the channel dictionary and hadd the files
	for output_file, input_patters in channel_dict.items():
		if filter_string is not None and filter_string not in output_file:
			INFO.log(f"Skipping {output_file} as it does not match the filter {filter_string}.")
			continue

		input_files_string = " ".join([os.path.join(input_path, pattern) for pattern in input_patters])
		cmd = "hadd -v1 %s/%s %s" % (output_path, output_file, input_files_string)
		INFO.log("Creating %s sample." % output_file)
		DEBUG.log(f"Running command: {cmd}")
		os.system(cmd)

def create_cli_args():
	# Options...
	parser = ArgumentParser(description="File Merger channels.")
	parser.add_argument("--inputs", type=str, required=True, help="Path to the input files.")
	parser.add_argument("--outputs", type=str, required=True, default=None, help="Path to the output files.")
	# parser.add_argument("--tree", type=str, default="NOMINAL", help="Name of the tree to check in the output files.")
	parser.add_argument("--channel", type=str, required=True, default=None, help="Channel to process.")
	parser.add_argument("--filter", type=str, default=None, help="Filter to apply to the input files. For example, 'Zmumu' to only process Zmumu files.")
	args = parser.parse_args()

	# Check that the paths exist
	if not os.path.exists(args.inputs):
		ERROR.log(f"Input path {args.inputs} does not exist.")
		exit(1)

	return args


def get_channel(channel_string = None):
	if channel_string is None:
		ERROR.log("No channel specified. Please provide a channel.")
		exit(1)
	try: 
		hadd_dict = hadd_dictionaries[channel_string]
		return hadd_dict
	except KeyError:
		ERROR.log(f"Channel {channel_string} not found in hadd dictionaries.")
		exit(1)

def main():
	# Create CLI arguments
	args = create_cli_args()

	# Check that the output path exists
	if not os.path.exists(args.outputs):
		# Create the output directory if it does not exist
		CreateOutputsDir(args.outputs, tree_name='') # Tree_name empty to use the function correctly.
		INFO.log(f"Output path {args.outputs} does not exist. Creating it.")

	else:
		# Clean input directories if needed
		clean = menu("Clean the output directories?",["No","Yes"])
		if clean:
			os.system("rm %s/*.root" % args.outputs)

	# Get the channel dictionary
	hadd_dict = get_channel(args.channel)

	# Hadd the datasets
	hadd_datasets(hadd_dict, args.inputs, args.outputs, args.filter)

	INFO.log("File merging completed successfully.")


if __name__ == "__main__":
	main()