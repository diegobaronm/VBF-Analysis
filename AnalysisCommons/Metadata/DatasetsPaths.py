# Library with paths to the analysis datasets

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

if __name__ == "__main__":
    print("This file is not meant to be executed --- it is a library of paths for the analysis datasets.")