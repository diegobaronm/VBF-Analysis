import os
from AnalysisCommons.Logger import WARNING, ERROR

# Library with paths to the analysis datasets

username = os.environ.get('USER') or os.environ.get('LOGNAME', 'ci')

def get_samples_and_dirs(paths_dict):
  pathsToSamplesList = paths_dict[username]
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

# Z->mumu
v26_mm_Paths = {
"dbaronmo": ['/data/dbaronmo/VBF-Analysis/v26-mm/','/eos/user/d/dbaronmo/v26-mm/','/eos/user/t/twyatt/data/diego/v26-mm/'], # Remote
"b78499db": ['/Volumes/T7/v26-mm/', '/Volumes/T7/v26-mm-SYS/','/Volumes/T7/v26-mm-theory-SYS/']
}

# Z->ee
v26_ee_Paths = {
"dbaronmo": ['/data/dbaronmo/VBF-Analysis/v26-ee/','/eos/user/d/dbaronmo/v26-ee/','/eos/user/t/twyatt/data/diego/v26-ee/'], # Remote
"b78499db": ['/Volumes/T7/v26-ee/', '/Volumes/T7/v26-ee-SYS/','/Volumes/T7/v26-ee-theory-SYS/']
}

# CI / Test support: set VBF_TEST_DATA to the test data directory to override paths.
_test_data = os.environ.get('VBF_TEST_DATA')
if _test_data:
    v26Paths[username] = [os.path.join(_test_data, 'tautau/')]
    v26_mm_Paths[username] = [os.path.join(_test_data, 'zmumu/')]
    v26_ee_Paths[username] = [os.path.join(_test_data, 'zee/')]

if __name__ == "__main__":
    print("This file is not meant to be executed --- it is a library of paths for the analysis datasets.")