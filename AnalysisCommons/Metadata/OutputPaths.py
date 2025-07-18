# Library with paths to the places where outputs should be saved when running in HTCondor
# Running local we always assume the output will go to the current directory under out/
# Or somewhere else if specified by the CLI

# Z->tautau
Zte_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zte/','/data/dbaronmo/Chicago_VBF_Outputs/Zte/'], # Running remote we give absolute paths. The code will try them all.
}

Ztm_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Ztm/','/data/dbaronmo/Chicago_VBF_Outputs/Ztm/'],
}

Zem_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zem/','/data/dbaronmo/Chicago_VBF_Outputs/Zem/'],
}

# Z->ee
Zee_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zee/','/data/dbaronmo/Chicago_VBF_Outputs/Zee/'],
}

# Z->mumu
Zmm_outputs_path = {
"dbaronmo": ['/afs/cern.ch/work/d/dbaronmo/private/Outputs/Zmm/','/data/dbaronmo/Chicago_VBF_Outputs/Zmm/'],
}

if __name__ == "__main__":
    print("This file is not meant to be executed --- it is a library of paths for the analysis outputs.")