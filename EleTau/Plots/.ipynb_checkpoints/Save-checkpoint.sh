#!/bin/bash 

cat > Description.txt

mkdir $1

mv Description.txt $1/.
mv SR_OS $1/.
mv SR_SS $1/.
mv CR_OS $1/.
mv CR_SS $1/.
mv *.pdf $1/.

cp MJ\ Estimation.ipynb $1/.
cp StackPlot.ipynb $1/.


