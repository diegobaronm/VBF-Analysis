"""
This script submits Analysis jobs to HTCondor
"""
import os

def menu(question,options):
    incorrect_answer=True
    while incorrect_answer:
        print(question)
        c=0
        for i in options:
            c+=1
            print(str(c)+")"+" "+i)
        answer=input()
        if int(answer)<=len(options):
            incorrect_answer=False
        else :
            print("Select a correct option!")
    return int(answer)

def create_executable(selected_channel):
    with open("run.sh","w") as f:
        f.write("#!/bin/bash\n")
        f.write('cd %s/MC\n' % (selected_channel))
        f.write('python3 RunAnalysis.py ${1} ${2} ${3} ${4}')

def create_submission_file(selected_channel):
    with open("Condor.sub","w") as f:
        f.write('executable              = run.sh\n')
        f.write('output                  = output/$(ClusterId).$(ProcId).out\n')
        f.write('error                   = error/$(ClusterId).$(ProcId).err\n')
        f.write('log                     = log/$(ClusterId).log\n')
        f.write('on_exit_remove   = (ExitBySignal == False) && (ExitCode == 0)\n')
        f.write('max_retries      = 3\n')
        f.write('requirements     = Machine =!= LastRemoteHost\n')
        f.write('preserve_relative_paths = True\n')
        f.write('initialdir = /afs/cern.ch/work/d/dbaronmo/private/VBF-Analysis/\n')
        f.write('transfer_input_files    = AnalysisCommons/,%s/MC/\n' % (selected_channel))
        f.write('+JobFlavour = "microcentury"')

def get_list_of_inputs(selected_channel):
    inputs = []
    for file in os.listdir('../%s/MC/InputDatasets/' % (selected_channel)):
        inputs.append(file)

    return inputs


def main():
    # First get the channel
    valid_channels = ["MuMu","Zee","EleTau","TauMu","MuEle"]
    selected_channel = valid_channels[menu("Please select a channel: ", valid_channels) - 1]

    # Create run.sh file (executable)
    create_executable(selected_channel)

    # Create submission file
    create_submission_file(selected_channel)

    # Ask user which input file to use
    inputs = get_list_of_inputs(selected_channel)
    selected_input = inputs[menu("Please select an input file: ", inputs) - 1]
    selected_input_path = '../%s/MC/InputDatasets/%s' % (selected_channel, selected_input)

    # Submit the jobs
    cmd = 'condor_submit Condor.sub -queue arguments from %s' % (selected_input_path)
    print('Submitting jobs... with command: %s' % (cmd))
    os.system(cmd)  

if __name__ == "__main__":
    main()