"""
This script submits Analysis jobs to HTCondor
"""
import os

from AnalysisCommons.Run import INFO, WARNING, ERROR

def menu(question,options):
    incorrect_answer=True
    while incorrect_answer:
        INFO.log(question)
        c=0
        for i in options:
            c+=1
            INFO.log(str(c)+")"+" "+i)
        answer=input()
        if int(answer)<=len(options):
            incorrect_answer=False
        else :
            INFO.log("Select a correct option!")
    return int(answer)

def create_executable(selected_channel):
    with open("run.sh","w") as f:
        f.write("#!/bin/bash\n")
        f.write('echo $PWD\n') # DEBUG 
        f.write('ls\n') # DEBUG
        f.write('cd %s/MC\n' % (selected_channel))
        f.write('python3 RunAnalysis.py ${1} ${2} ${3} ${4}')

def create_submission_file(selected_channel):
    with open("Condor.sub","w") as f:
        f.write('executable              = run.sh\n')
        f.write('output                  = output/$(ClusterId).$(ProcId).out\n')
        f.write('error                   = error/$(ClusterId).$(ProcId).err\n')
        f.write('log                     = log/$(ClusterId).log\n')
        f.write("stream_error            = True\n")
        f.write("stream_output           = True\n")
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

# This function creates the input datasets file for Condor submission and return the path to the new file.
def create_input_datasets(selected_input_path):
    # Read file lines
    with open(selected_input_path, 'r') as f:
        lines = f.readlines()

    # Prevent previous formats (e.g. Samples yes/no NOMINAL blabla)
    # Only let one Sample per line, check all the file
    for line in lines:
        tokens = line.split(' ')
        if len(tokens) > 1:
            ERROR.log('Error: Your input file does not have the correct format. Exiting...')
            ERROR.log('Only Sample name per line is allowed.')
            exit(1)

    # Define region name.
    INFO.log('Input the region name to run over - REMEMBER adding OS, SS at the end!')
    region = input()

    if not region.endswith('OS') and not region.endswith('SS'):
        ERROR.log('Region should end with OS or SS.')
        exit(1)

    # Ask if the user want to change the tree name from NOMINAL to something else
    tree = 'NOMINAL'
    INFO.log('Do you want to change the tree name from NOMINAL to something else? (yes/no)')
    change_tree = input().strip().lower() == 'yes'
    if change_tree:
        INFO.log('Input the new tree name (e.g. NOMINAL, SYSTEMATIC, etc.):')
        tree = input().strip()
        if not tree:
            ERROR.log('Tree name cannot be empty.')
            exit(1)
    
    # Print the selected options and ask for confirmation
    INFO.log('You selected the following options:')
    INFO.log(f'Region: {region}')
    INFO.log(f'Tree: {tree}')
    INFO.log('Is this correct? (yes/no)')
    confirm = input().strip().lower() == 'yes'
    if not confirm:
        ERROR.log('Exiting without changes.')
        exit(0)
    
    # Now construct the submission file lines
    # Build the lines
    new_lines = []
    for line in lines:
        line = line.replace('\n', '')
        tokens = line.split(' ')
        line = '%s %s %s %s\n' % (line, 'yes', tree, region)
        new_lines.append(line)

    # Create file with _ForCondor suffix
    with open(selected_input_path.replace('.txt', '_ForCondor.txt'), 'w') as f:
        for new_line in new_lines:
            f.write(new_line)

    return selected_input_path.replace('.txt', '_ForCondor.txt')

def main():
    # Ask the user if they want to clean the logs
    clean = menu("Do you want to clean the logs?", ["no", "yes"]) == 2
    if clean:
        os.system('rm -rf ../log/*')
        os.system('rm -rf ../output/*')
        os.system('rm -rf ../error/*')

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

    # Read the region from the input file and let the user choose the region name
    input_datasets_path = create_input_datasets(selected_input_path)

    # Submit the jobs
    cmd = 'condor_submit Condor.sub -queue arguments from %s' % (input_datasets_path)
    INFO.log('Submitting jobs... with command: %s' % (cmd))
    os.system(cmd)  

if __name__ == "__main__":
    main()