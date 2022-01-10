import os
import sys

os.chdir(sys.argv[1])

sys.path.append('backend')

from dataSets import dataCombos

samples=[]
for i in dataCombos:
    samples=samples+dataCombos[i]

with open("samples.txt","w") as file:
    for j in samples:
        file.write(j)
        file.write('\n')

os.chdir('..')

