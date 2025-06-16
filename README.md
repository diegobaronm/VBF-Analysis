# VBF-Analysis

To run one of the channels you have two options:

## Local run

Go to the channel directory (for example `TauMu`) and do:
```
./Parallel_executer.sh N_CORES
```

you have to add the name of the region at the end (modify the script) - for example `ZpeakOS`.

## Condor run:

Run the `Submit.py` command and choose the desired channel and follow the instructions.

## Additional tricks:

- Use `Scripts/CreateListToRun.py` to create your list of samples.