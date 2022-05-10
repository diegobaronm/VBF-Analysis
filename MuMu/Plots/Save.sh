#!/bin/bash 

cat > Description.txt

mkdir $1

mv Description.txt $1/.
mv *.root $1/.
mv *.pdf $1/.

cp StackPlot.ipynb $1/.


