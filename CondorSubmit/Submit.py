"""
This script submits Analysis jobs to HTCondor
"""
import os

from AnalysisCommons.Run import INFO, WARNING, ERROR, CreateOutputsDir

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

def create_executable(selected_channel, output_datasets_path, job_id):
    with open("run_%s.sh" % (job_id),"w") as f:
        f.write("#!/bin/bash\n")
        f.write('echo $PWD\n') # DEBUG 
        f.write('ls\n') # DEBUG
        #### Load ATLAS environment
        f.write("shopt -s expand_aliases\n") # Enable aliases in the remote machine
        f.write("alias setupATLAS='source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh'\n") # Set up the ATLAS environment
        f.write("setupATLAS\n")
        f.write("asetup StatAnalysis,0.6.2\n")
        #####
        f.write('cd %s/MC\n' % (selected_channel))
        # If the output path is not None, we need to modify the run.sh
        if output_datasets_path is None:
            f.write('python3 RunAnalysis.py ${1} ${2} ${3} ${4}')
        else:
            f.write('python3 RunAnalysis.py ${1} ${2} ${3} ${4} --output ${5}')

def create_submission_file(selected_channel, is_chicago, input_datasets_path ,output_datasets_path, job_id):
    with open("Condor_%s.sub" % (job_id),"w") as f:
        f.write('executable              = run_%s.sh\n' % (job_id))
        f.write('transfer_executable     = True\n')
        f.write('output                  = output/$(ClusterId).$(ProcId).out\n')
        f.write('error                   = error/$(ClusterId).$(ProcId).err\n')
        f.write('log                     = log/$(ClusterId).log\n')
        f.write("stream_error            = True\n")
        f.write("stream_output           = True\n")
        f.write('getenv                  = True\n')
        f.write('arguments               = $(arguments)\n')
        f.write('on_exit_remove   = (ExitBySignal == False) && (ExitCode == 0)\n')
        f.write('max_retries      = 3\n')
        if output_datasets_path is not None:
            f.write('arguments               = $(SAMPLE) $(REMOTE) $(TREE) $(REGION) $(OUTDIR)\n')
        else:
            f.write('arguments               = $(SAMPLE) $(REMOTE) $(TREE) $(REGION)\n')
        f.write('requirements     = Machine =!= LastRemoteHost\n')
        f.write('preserve_relative_paths = True\n')
        f.write('initialdir = %s/\n' % (os.path.dirname(os.getcwd()))) # Get the directory above the CWD.
        f.write('transfer_input_files    = AnalysisCommons/,%s/MC/\n' % (selected_channel))
        if is_chicago:
            f.write('+ALLOW_MWT2            = True\n')
            f.write('request_memory = 4096MB\n')
        else:
            f.write('+JobFlavour = "microcentury"')

        f.write('\n')
        if output_datasets_path is not None:
            f.write('queue SAMPLE, REMOTE, TREE, REGION, OUTDIR from %s\n' % (input_datasets_path))
        else:
            f.write('queue SAMPLE, REMOTE, TREE, REGION from %s\n' % (input_datasets_path))

CONDOR_SUBMIT_TXT_POSTFIX = '_ForCondor.txt'

def get_list_of_inputs(selected_channel):
    inputs = []
    for file in os.listdir('../%s/MC/InputDatasets/' % (selected_channel)):
        if file.endswith('.txt') and not file.endswith(CONDOR_SUBMIT_TXT_POSTFIX):
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

    # Finally create the output directory if needed.
    INFO.log('Do you want to create the output directory? (yes/no)')
    create_output_dir = input().strip().lower() == 'yes'
    output_path = None
    if create_output_dir:
        INFO.log('Enter path:')
        output_path = input()
        CreateOutputsDir(output_path, tree)
    
    # Print the selected options and ask for confirmation
    INFO.log('You selected the following options:')
    INFO.log(f'Region: {region}')
    INFO.log(f'Tree: {tree}')
    if create_output_dir:
        INFO.log(f'Output directory: {output_path}')
    else:
        INFO.log('Output directory: OutputPaths.py will be used.')
    INFO.log('Is this correct? (yes/no)')
    confirm = input().strip().lower() == 'yes'
    if not confirm:
        ERROR.log('Exiting...')
        exit(0)
    
    # Now construct the submission file lines
    # Build the lines
    new_lines = []
    for line in lines:
        line = line.replace('\n', '')
        tokens = line.split(' ')
        if output_path is None:
            line = '%s %s %s %s\n' % (line, 'yes', tree, region)
        else:
            line = '%s %s %s %s %s\n' % (line, 'yes', tree, region, output_path)
        new_lines.append(line)

    # Create file with CONDOR_SUBMIT_TXT_POSTFIX suffix
    with open(selected_input_path.replace('.txt', CONDOR_SUBMIT_TXT_POSTFIX), 'w') as f:
        for new_line in new_lines:
            f.write(new_line)

    return selected_input_path.replace('.txt', CONDOR_SUBMIT_TXT_POSTFIX), output_path

# Create JobID with time of the day and date
def create_job_id():
    from datetime import datetime
    now = datetime.now()
    return now.strftime("%Y%m%d_%H%M%S")

def main():
    # Check that log directories exist, if not create them
    if not os.path.exists('../log') or not os.path.exists('../output') or not os.path.exists('../error'):
        INFO.log('Creating log, output and error directories...')
        os.makedirs('../log', exist_ok=True)
        os.makedirs('../output', exist_ok=True)
        os.makedirs('../error', exist_ok=True)

    # Ask the user if they want to clean the logs
    clean = menu("Do you want to clean the logs?", ["no", "yes"]) == 2
    if clean:
        os.system('rm -rf ../log/*')
        os.system('rm -rf ../output/*')
        os.system('rm -rf ../error/*')

    # Ask if submitting in Chicago or Lxplus
    is_chicago = menu("Where do you want to submit the jobs?", ["Chicago", "Lxplus"]) == 1

    # First get the channel
    valid_channels = ["MuMu","Zee","EleTau","TauMu","MuEle"]
    selected_channel = valid_channels[menu("Please select a channel: ", valid_channels) - 1]

    # Ask user which input file to use
    inputs = get_list_of_inputs(selected_channel)
    selected_input = inputs[menu("Please select an input file: ", inputs) - 1]
    selected_input_path = '../%s/MC/InputDatasets/%s' % (selected_channel, selected_input)

    # Read the region from the input file and let the user choose the region name
    input_datasets_path, output_datasets_path = create_input_datasets(selected_input_path)

    # Create the job ID
    job_id = create_job_id()

    # Create run.sh file (executable)
    create_executable(selected_channel, output_datasets_path, job_id)

    # Create submission file
    create_submission_file(selected_channel, is_chicago, input_datasets_path, output_datasets_path, job_id)

    # Submit the jobs
    cmd = 'condor_submit Condor_%s.sub' % (job_id)
    INFO.log('Submitting jobs... with command: %s' % (cmd))
    os.system(cmd)  

if __name__ == "__main__":
    main()