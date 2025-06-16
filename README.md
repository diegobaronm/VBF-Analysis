# VBF-Analysis

To run one of the channels you have two options:

## Local run

Go to the `MC` directory inside the respective channel directory (for example `TauMu/MC`) and run:

`python3 RunAnalysis.py`

If you use the help options you will see

```
usage: RunAnalysis.py [-h] [--j J] sample {yes,no} tree region

Run VBF Analysis!

positional arguments:
  sample      The name of the sample from the ones on the
              metadata. It can also be a file in which case the
              code will check that the path exists and will do
              parallel processing according to the optional --j
              parameter.
  {yes,no}    Is the code running remotely? (yes/no)
  tree        Tree to run over. Usually NOMINAL.
  region      Region to run over. Should contain OS or SS in
              the name.

options:
  -h, --help  show this help message and exit
  --j J       Number of jobs to run in parallel. Default is 1.
```

then, one valid run will look like:

```
python3 RunAnalysis.py InputDatasets/Higgs.txt no NOMINAL NewZpeakOS --j10
```

## Condor run:

Run the `Submit.py` command and choose the desired channel and follow the instructions.

## Additional tricks:

- Use `Scripts/CreateListToRun.py` to create your list of samples.