#!/bin/bash

# Script to create and activate Python virtual environment for VBF Analysis
# Environment name: vbf_pyenv

ENV_NAME="vbf_pyenv"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ENV_PATH="${SCRIPT_DIR}/${ENV_NAME}"
REQUIREMENTS_FILE="${SCRIPT_DIR}/requirements.txt"

echo "VBF Analysis Environment Setup Script"
echo "====================================="

# Check if ROOT is installed in the system
echo "Checking for ROOT installation..."
if command -v root &> /dev/null; then
    ROOT_PATH=$(which root)
    ROOT_VERSION=$(root --version)
    echo "ROOT found at: $ROOT_PATH"
    
    # Try to get ROOTSYS if available
    if [ -n "$ROOTSYS" ]; then
        echo "ROOTSYS: $ROOTSYS"
    fi
    echo ""
else
    echo "ERROR: ROOT is not installed or not found in PATH"
    echo "ROOT is required for this VBF Analysis environment."
    echo "Please install ROOT and make sure it's available in your PATH."
    echo "Visit https://root.cern.ch/ for installation instructions."
    exit 1
fi

# Check if the virtual environment already exists
if [ -d "$ENV_PATH" ]; then
    echo "Virtual environment '$ENV_NAME' already exists at: $ENV_PATH"
    echo "Activating existing environment..."
    source "$ENV_PATH/bin/activate"
    echo "Environment activated successfully!"
    echo "Python path: $(which python)"
    echo "Python version: $(python --version)"
else
    echo "Creating new virtual environment '$ENV_NAME'..."
    
    # Create the virtual environment
    python3 -m venv "$ENV_PATH" --system-site-packages
    
    if [ $? -eq 0 ]; then
        echo "Virtual environment created successfully!"
        
        # Activate the environment
        source "$ENV_PATH/bin/activate"
        echo "Environment activated!"
        
        # Upgrade pip
        echo "Upgrading pip..."
        pip install --upgrade pip
        
        # Install requirements if requirements.txt exists
        if [ -f "$REQUIREMENTS_FILE" ]; then
            echo "Installing packages from requirements.txt..."
            pip install -r "$REQUIREMENTS_FILE"
            
            if [ $? -eq 0 ]; then
                echo "All packages installed successfully!"
            else
                echo "Warning: Some packages failed to install. Check the output above."
            fi
        else
            echo "Warning: requirements.txt not found at $REQUIREMENTS_FILE"
            echo "You may need to install packages manually."
        fi
        
        echo "Setup complete!"
    else
        echo "Error: Failed to create virtual environment"
        exit 1
    fi
fi

echo ""
echo "Environment Information:"
echo "- Environment name: $ENV_NAME"
echo "- Environment path: $ENV_PATH"
echo "- Python executable: $(which python)"
echo "- Python version: $(python --version)"
echo ""
echo "To activate this environment in the future, run:"
echo "  source $ENV_PATH/bin/activate"
echo ""
echo "To deactivate the environment, run:"
echo "  deactivate"
