import sys
import os
# Get the directory holding all the code which is one level above the current directory
project_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
print("Adding the following directory to the PYTHONPATH: ",project_dir,"\n")
sys.path.append(project_dir)

# Run this script to configure the project
if __name__ == '__main__':
    with open("SetupPythonScripts.sh","w") as file:
        file.write("#!/bin/bash\n")
        file.write("export PYTHONPATH=$PYTHONPATH:"+project_dir)