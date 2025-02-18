#!/bin/bash
# Check that you are in the Scripts directory
current_dir=$(basename "$PWD")
if [[ "$current_dir" == "Scripts" ]]; then
    echo "Setting up the PYTHONPATH and adding $PWD/.. to it."
    export PYTHONPATH=$PYTHONPATH:$PWD/../
else
    echo "Please run this script from the Scripts directory"
    return 1
fi