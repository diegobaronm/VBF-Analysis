from infofileZee import infos as infosZee
from infofileZmumu import infos as infosZmumu
from infofileTauTau import infos as infosTauTau


unique_dsids = {}

for key, value in infosZee.items():
    if value['DSID'] not in unique_dsids:
        unique_dsids[value['DSID']] = key

for key, value in infosZmumu.items():
    if value['DSID'] not in unique_dsids:
        unique_dsids[value['DSID']] = key

for key, value in infosTauTau.items():
    if value['DSID'] not in unique_dsids:
        unique_dsids[value['DSID']] = key

for key, value in unique_dsids.items():
    print(key, value)