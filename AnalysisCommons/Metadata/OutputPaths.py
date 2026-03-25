# Library with paths to the places where outputs should be saved when running in HTCondor
# Running local we always assume the output will go to the current directory under out/
# Or somewhere else if specified by the CLI
#
# To add paths for a new user, either:
#   1. Add entries to the dictionaries below keyed by your $USER, or
#   2. Set the VBF_OUTPUT_DIR environment variable to a base path.
#      The code will automatically append the channel suffix (e.g. Zte/, Ztm/).

import os

def _user_output_paths(channel_suffix):
    """Return a dict entry from the VBF_OUTPUT_DIR env var if set."""
    env_dir = os.environ.get("VBF_OUTPUT_DIR")
    if env_dir:
        return {os.environ["USER"]: [os.path.join(env_dir, channel_suffix)]}
    return {}

# Z->tautau
Zte_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zte/','/data/dbaronmo/Chicago_VBF_Outputs/Zte/'], # Running remote we give absolute paths. The code will try them all.
}
Zte_outputs_path.update(_user_output_paths("Zte/"))

Ztm_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Ztm/','/data/dbaronmo/Chicago_VBF_Outputs/Ztm/'],
}
Ztm_outputs_path.update(_user_output_paths("Ztm/"))

Zem_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zem/','/data/dbaronmo/Chicago_VBF_Outputs/Zem/'],
}
Zem_outputs_path.update(_user_output_paths("Zem/"))

# Z->ee
Zee_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zee/','/data/dbaronmo/Chicago_VBF_Outputs/Zee/'],
}
Zee_outputs_path.update(_user_output_paths("Zee/"))

# Z->mumu
Zmm_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zmm/','/data/dbaronmo/Chicago_VBF_Outputs/Zmm/'],
}
Zmm_outputs_path.update(_user_output_paths("Zmm/"))

if __name__ == "__main__":
    print("This file is not meant to be executed --- it is a library of paths for the analysis outputs.")