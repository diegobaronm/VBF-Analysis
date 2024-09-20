import sys
import os
# Get the directory holding all the code which is one level above the current directory
project_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
print("Adding the following directory to the PYTHONPATH: ",project_dir,"\n")
sys.path.append(project_dir)