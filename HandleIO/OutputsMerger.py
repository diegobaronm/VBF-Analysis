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
"Signal_truth_MG.root": ["VBF_Ztautau_MG_*_truth_20*.root"],
"Ztautau_Sherpa.root": ["Ztautau_sherpa*.root"],
"Ztautau_PoPy.root": ["Ztautau_201*.root"],
"Ztautau_MG.root": ["Ztautau_MG[!NLO]*.root"],
"Ztautau_MGNLO.root": ["Ztautau_MGNLO*.root"],
"Ztautau_SherpaNLO.root": ["Ztautau_SherpaNLO*.root"],
"Zjets.root": ["Zmumu_201*.root"],
"Higgs.root": ["WpH*.root", "WmH*.root", "ZHllbb*.root", "ZHlltautau*.root", "ggHttlm15hp20*.root", "ggHttlp15hm20*.root"],
"Higgs_truth_EWK.root": ["VBFHttlm15hp20_truth*.root", "VBFHttlp15hm20_truth*.root"],
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
"Signal_truth_MG.root": ["VBF_Ztautau_MG_*_truth_20*.root"],
"Ztautau_Sherpa.root": ["Ztautau_sherpa*.root"],
"Ztautau_PoPy.root": ["Ztautau_201*.root"],
"Ztautau_MG.root": ["Ztautau_MG[!NLO]*.root"],
"Ztautau_MGNLO.root": ["Ztautau_MGNLO*.root"],
"Ztautau_SherpaNLO.root": ["Ztautau_SherpaNLO*.root"],
"Zjets.root": ["Zmumu_201*.root","Zee_201*.root"],
"Higgs.root": ["WpH*.root", "WmH*.root", "ZHllbb*.root", "ZHlltautau*.root", "ggHttlm15hp20*.root", "ggHttlp15hm20*.root"],
"Higgs_truth_EWK.root": ["VBFHttlm15hp20_truth*.root", "VBFHttlp15hm20_truth*.root"],
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
"Signal_truth_MG.root": ["VBF_Ztautau_MG_*_truth_20*.root"],
"Ztautau_Sherpa.root": ["Ztautau_sherpa*.root"],
"Ztautau_PoPy.root": ["Ztautau_201*.root"],
"Ztautau_MG.root": ["Ztautau_MG[!NLO]*.root"],
"Ztautau_MGNLO.root": ["Ztautau_MGNLO*.root"],
"Ztautau_SherpaNLO.root": ["Ztautau_SherpaNLO*.root"],
"Zjets.root": ["Zmumu_201*.root","Zee_201*.root"],
"Higgs.root": ["WpH*.root", "WmH*.root", "ZHllbb*.root", "ZHlltautau*.root", "ggHttlm15hp20*.root", "ggHttlp15hm20*.root"],
"Higgs_truth_EWK.root": ["VBFHttlm15hp20_truth*.root", "VBFHttlp15hm20_truth*.root"],
"VV.root": ["llll_*.root", "lllv_*.root", "llvv_*.root", "lvvv_*.root", "ZqqZvv_*.root", "ZqqZll_*.root", "WqqZvv_*.root", "WqqZll_*.root", "WlvZqq_*.root"],
"Wjets.root": ["Wplusenu_*.root", "Wminusenu_*.root", "Wplusmunu_*.root", "Wminusmunu_*.root", "Wplustaunu_*.root", "Wminustaunu_*.root"],
"singletop.root": ["st_schan_top_*.root", "st_schan_atop_*.root", "st_tchan_top_*.root", "st_tchan_atop_*.root", "st_wt_top_*.root", "st_wt_atop_*.root"],
"ttbar.root": ["ttbar_*.root"],
"W_EWK_Sherpa.root": ["W_EWK_sherpa*.root"],
"W_EWK_PoPy.root": ["W_EWK_PoPy*.root"],
"VV_EWK.root": ["VV_EWK*.root"],
"Data.root": ["data_*.root"],
}

Z_PRIME_MASS_LIST = list(range(200, 1050, 50)) + list(range(1000, 2200, 200)) + list(range(2000, 3500, 500))

# Function to add the Zprime pairs between 200 and 500 GeV.
def add_Zprime_samples(hadd_dict):

	for mass in Z_PRIME_MASS_LIST:
		hadd_dict[f'Zprime_{mass}.root'] = [f'VBF_Zprime_{mass}*.root']

# Add Zprime samples to tauhad-taulep channels.
add_Zprime_samples(hadd_etau)
add_Zprime_samples(hadd_mutau)

hadd_dictionaries = {'MuMu': hadd_mumu,
					 'Zee': hadd_ee,
					 'TauMu': hadd_mutau,
					 'EleTau': hadd_etau,
					 'MuEle': hadd_emu,}

def hadd_datasets(channel_dict, input_path, output_path, filter_string=None, rw_dictionary=None):
	# Loop trough the channel dictionary and hadd the files
	for output_file, input_patters in channel_dict.items():
		if filter_string is not None and filter_string not in output_file:
			INFO.log(f"Skipping {output_file} as it does not match the filter {filter_string}.")
			continue

		input_files_string = " ".join([os.path.join(input_path, pattern) for pattern in input_patters])
		if rw_dictionary is None:
			cmd = "hadd -v1 %s/%s %s" % (output_path, output_file, input_files_string)
		else:
			cmd = "hadd -v1 %s/%s %s" % (output_path, output_file, input_files_string)
			for sample, tag in rw_dictionary.items():
				if sample in output_file:
					INFO.log("Hadding reweighted sample %s with tag %s." % (sample, tag))
					cmd = "hadd -v1 %s/%s %s" % (output_path, output_file.replace(".root", f"_{tag}.root"), input_files_string)
					break

		INFO.log("Creating %s sample." % output_file)
		DEBUG.log(f"Running command: {cmd}")
		output =os.system(cmd)
		if output != 0:
			ERROR.log(f"Error while hadding sample {output_file}")
			ERROR.log(f"Command: {cmd}")
			exit(1)

def create_cli_args():
	# Options...
	parser = ArgumentParser(description="File Merger channels.")
	parser.add_argument("--inputs", type=str, required=True, help="Path to the input files.")
	parser.add_argument("--outputs", type=str, required=True, default=None, help="Path to the output files.")
	# parser.add_argument("--tree", type=str, default="NOMINAL", help="Name of the tree to check in the output files.")
	parser.add_argument("--channel", type=str, required=True, default=None, help="Channel to process.")
	parser.add_argument("--filter", type=str, default=None, help="Filter to apply to the input files. For example, 'Zmumu' to only process Zmumu files.")
	parser.add_argument("--rw-samples", help="Comma-separated list of samples that were reweighted.", default=None)
	parser.add_argument("--rw-tags", help="Comma-separated list of tags for the reweighted samples.", default=None)
	args = parser.parse_args()

	# Check that the paths exist
	if not os.path.exists(args.inputs):
		ERROR.log(f"Input path {args.inputs} does not exist.")
		exit(1)

	# Check that she same number of reweighted samples and tags are provided.
	if args.rw_samples is None and args.rw_tags is not None:
		ERROR.log("Reweighted samples provided but no tags. Please provide both or neither.")
		exit(1)
	if args.rw_tags is None and args.rw_samples is not None:
		ERROR.log("Reweighted tags provided but no samples. Please provide both or neither.")
		exit(1)
	if args.rw_samples is not None and args.rw_tags is not None:
		rw_samples = args.rw_samples.split(",")
		rw_tags = args.rw_tags.split(",")
		if len(rw_samples) >= 1:
			if len(rw_tags) == 1:
				INFO.log("Only one tag provided for reweighted samples. Using the same tag for all samples.")
			elif len(rw_samples) != len(rw_tags):
				ERROR.log("Number of reweighted samples and tags do not match. Please provide the same number of samples and tags.")
				exit(1)
		else:
			ERROR.log("Wrong format for reweighted samples or tags.")
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

def create_rw_dictionary(rw_samples, rw_tags):
	rw_samples = rw_samples.split(",")
	rw_tags = rw_tags.split(",")
	rw_dictionary = {}
	if len(rw_samples) != len(rw_tags):
		for i in rw_samples:
			rw_dictionary[i] = 'RW'+rw_tags[0]
	else:
		for i, j in zip(rw_samples, rw_tags):
			rw_dictionary[i] = 'RW'+j

	return rw_dictionary

def main():
	# Create CLI arguments
	args = create_cli_args()

	# Check that the output path exists
	if not os.path.exists(args.outputs):
		# Create the output directory if it does not exist
		CreateOutputsDir(args.outputs, tree_name='') # Tree_name empty to use the function correctly.
		INFO.log(f"Output path {args.outputs} does not exist. Creating it.")
	else:
		INFO.log(f"Output path {args.outputs} already exists. Using it.")
		# Clean input directories if needed
		clean = menu("Clean the output directories?",["No","Yes"]) == 2
		if clean:
			INFO.log(f"Cleaning the output directory {args.outputs}.")
			os.system("rm %s/*.root" % args.outputs)

	# Get the channel dictionary
	hadd_dict = get_channel(args.channel)

	# Create the re-weighting dictionary if needed.
	rw_dictionary = None
	if args.rw_samples is not None:
		INFO.log("Creating re-weighting dictionary from provided samples and tags.")
		rw_dictionary = create_rw_dictionary(args.rw_samples, args.rw_tags)
	else:
		WARNING.log("No re-weighting samples or tags provided. Proceeding without re-weighting.")

	# Hadd the datasets
	hadd_datasets(hadd_dict, args.inputs, args.outputs, args.filter, rw_dictionary)

	INFO.log("File merging completed successfully.")


if __name__ == "__main__":
	main()