"""Auto-configure sys.path so HandleIO/ scripts can import project packages.

Add ``import _setup_project_path`` at the top of any script in this
directory, *before* importing AnalysisCommons, HandleIO, etc.
This removes the need to manually source SetupPythonScripts.sh.
"""
import sys
import os

_PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if _PROJECT_ROOT not in sys.path:
    sys.path.insert(0, _PROJECT_ROOT)
