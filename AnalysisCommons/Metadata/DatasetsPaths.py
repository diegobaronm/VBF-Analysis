import os
from AnalysisCommons.Logger import WARNING, ERROR, INFO

# Library with paths to the analysis datasets
#
# To add paths for a new user, either:
#   1. Add entries to the path dictionaries below keyed by your $USER, or
#   2. Set the VBF_DATASETS_DIR environment variable to a comma-separated list of
#      base directories containing your ntuples. The code will scan them automatically.

username = os.environ['USER']

def _env_paths():
    """Build a paths dict entry from VBF_DATASETS_DIR if set."""
    env = os.environ.get("VBF_DATASETS_DIR")
    if env:
        return {username: [p.strip() for p in env.split(",") if p.strip()]}
    return {}

def get_samples_and_dirs(paths_dict):
  pathsToSamplesList = paths_dict.get(username, [])
  if not pathsToSamplesList:
    ERROR.log("No dataset paths configured for user '%s'." % username)
    ERROR.log("Set VBF_DATASETS_DIR or add your paths to DatasetsPaths.py.")
    exit(1)
  samples = []
  dirs = []
  for path in pathsToSamplesList:
    try:
      samples += os.listdir(path)
      dirs += [path+i+'/' for i in os.listdir(path) if ('mc' in i or 'data' in i)]
    except FileNotFoundError:
      WARNING.log("Path %s not found in this machine, skipping..." % path)
    except PermissionError:
      WARNING.log("No permission to access %s in this machine, skipping..." % path)
  
  if len(dirs) == 0:
    ERROR.log("No valid paths found for user %s, exiting..." % username)
    exit(1)
  return samples, dirs

# Z->tautau
v26Paths = {
# LEGACY SYS: "dbaronmo": ['/eos/user/w/wyatt/data/v26-sys-vbf/'], # Remote
"b78499db": ['/Volumes/T7/v26/','/Volumes/T7/v26-truth/','/Volumes/T7/v26-SYS/','/Volumes/T7/v26-theory-SYS/']
}
v26Paths.update(_env_paths())

# Z->mumu
v26_mm_Paths = {
"dbaronmo": ['/data/dbaronmo/VBF-Analysis/v26-mm/','/eos/user/d/dbaronmo/v26-mm/','/eos/user/t/twyatt/data/diego/v26-mm/'], # Remote
"b78499db": ['/Volumes/T7/v26-mm/', '/Volumes/T7/v26-mm-SYS/','/Volumes/T7/v26-mm-theory-SYS/']
}
v26_mm_Paths.update(_env_paths())

# Z->ee
v26_ee_Paths = {
"dbaronmo": ['/data/dbaronmo/VBF-Analysis/v26-ee/','/eos/user/d/dbaronmo/v26-ee/','/eos/user/t/twyatt/data/diego/v26-ee/'], # Remote
"b78499db": ['/Volumes/T7/v26-ee/', '/Volumes/T7/v26-ee-SYS/','/Volumes/T7/v26-ee-theory-SYS/']
}
v26_ee_Paths.update(_env_paths())

if __name__ == "__main__":
    print("This file is not meant to be executed --- it is a library of paths for the analysis datasets.")