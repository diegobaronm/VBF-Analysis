#!/bin/bash
# Check that you are in the Scripts directory
current_dir=$(basename "$PWD")
echo $current_dir
if [ ["$current_dir"=="Scripts"] ]; then
    export PYTHONPATH=$PYTHONPATH:$PWD/../
else
    echo "Please run this script from the Scripts directory"
    return 1
fi