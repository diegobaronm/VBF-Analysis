#!/usr/bin/env python3

# ----------------------------------------------------------------
#
#   Unified RunAnalysis entry point.
#   Run any channel from the project root directory.
#
#   Usage:
#     python3 RunAnalysis.py EleTau InputDatasets/Higgs.txt no NOMINAL NewZpeakOS --j10
#
#   The --channel flag is REQUIRED when running from the project root.
#   The script changes into <channel>/MC/ before executing to keep
#   C++ backend paths working, while resolving metadata automatically.
#
#   This is compatible with Condor submissions.
#
#   The shebang above is MANDATORY for Condor execution!
#
# ----------------------------------------------------------------

import sys
import os
import argparse

from AnalysisCommons.Logger import INFO, WARNING, ERROR, BANNER

def createParser():
    from AnalysisCommons.Metadata.ChannelConfig import VALID_CHANNELS
    # Create parser
    parser = argparse.ArgumentParser(description="Run VBF Analysis!")

    # Add positional arguments
    parser.add_argument("channel", help="Channel to run (e.g. EleTau, MuMu, Zee, TauMu, MuEle). When provided, metadata is resolved automatically from the channel registry.", type=str, default=None, choices=VALID_CHANNELS)
    parser.add_argument("sample", help="The name of the sample from the ones on the metadata. It can also be a file in which case the code will check that the path exists and will do parallel processing according to the optional --j parameter.", type=str)
    parser.add_argument("remote", help="Is the code running remotely? (yes/no)", type=str, choices=["yes", "no"])
    parser.add_argument("tree", help="Tree to run over. Usually NOMINAL.", type=str,)
    parser.add_argument("region", help="Region to run over. Should contain OS or SS in the name.", type=str)
    parser.add_argument("--mode", help="Whether the code produces histograms or NTuples. Default is histograms.", type=str, choices=["h", "n", "hn"], default="h")
    parser.add_argument("--j", help="Number of jobs to run in parallel. Default is 1.", type=int, default=1)
    parser.add_argument("--clean", help="Clean the output directory before running the analysis. Default is False.", action='store_true')
    parser.add_argument("--output", help="Output directory for the analysis results. Default is out/<tree>/", type=str)
    parser.add_argument("--loglevel", help="Set the log level. Default is INFO.", type=int, choices=[1, 2, 3, 4], default=3)
    parser.add_argument("--sys", help="If set, the code will run the systematic variations. Default is False.", action='store_true')
    parser.add_argument("--sys-channel", help="When --sys is set, this has to be set to select the associated systematics variations for the channel. Default is None and will raise an error if --sys is set.", type=str, choices=["Zee", "Zmm", "Zem", "Ztm","Zte"], default=None)
    parser.add_argument("--sys-type", help="Comma separated list of types of systematics to run. By default only experimental ones (sf and kinematic) are run. If you want to run theory systematics too, set this to 'all'.", type=str, default="sf,kinematic")

    # Parse arguments
    args = parser.parse_args()

    # Check a couple of things...
    if args.region.find("OS") == -1 and args.region.find("SS") == -1:
        ERROR.log("Region should contain OS or SS in the name.")
        exit(1)

    if args.sys and args.sys_channel is None:
        ERROR.log("When --sys is set, --sys-channel has to be set too.")
        exit(1)

    if "n" in args.mode and args.sys:
        ERROR.log("Running in NTuple mode is not compatible with running systematics.")
        exit(1)

    type_sys_to_run = args.sys_type.split(",")
    valid_types_sys_to_run = ["sf", "kinematic", "theory"]
    for t in type_sys_to_run:
        if t not in valid_types_sys_to_run and t != "all":
            ERROR.log("Type of systematic %s not recognised. Valid types are: %s." % (t, ", ".join(valid_types_sys_to_run)))
            exit(1)
    if 'sf' in type_sys_to_run and 'kinematic' in type_sys_to_run and 'theory' in type_sys_to_run:
        ERROR.log("You are trying to run all types of systematics. Since theory ones are in different files this need to be done separately.")
        exit(1)
    # Always add the NOMINAL
    args.sys_type = args.sys_type + ",nominal"

    return args
import ROOT as r

def main():
    # Determine the project root from this script's location
    project_root = os.path.dirname(os.path.abspath(__file__))
    sys.path.insert(0, project_root)

    # create parser
    parser = createParser()

    INFO.log(BANNER(parser.channel))
    # Change into the channel's MC directory so that C++ backend paths resolve correctly
    mc_dir = os.path.join(project_root, parser.channel, 'MC')
    if not os.path.isdir(mc_dir):
        ERROR.log("Channel directory not found: %s" % mc_dir)
    os.chdir(mc_dir)

    from AnalysisCommons.Run import RunAnalysisFromChannel
    RunAnalysisFromChannel(parser,parser.channel)
    # Once finished go back to the project root
    os.chdir(project_root)


if __name__ == "__main__":
    main()
