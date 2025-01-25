import yaml
import os
import ROOT
from AnalysisCommons.Run import INFO, WARNING, ERROR, DEBUG, Logger
Logger.LOGLEVEL = 3

from histogramHelpers import stackPlot, templatesDict

def get_template(dict_name : str):
    if dict_name not in templatesDict:
        ERROR.log('Dictionary %s not found... do you need to define it in histogramHelpers.py ? ' % dict_name)
        exit(1)
    return templatesDict[dict_name]

def check_file_and_move_dir(file : str):
    if not os.path.isfile(file):
        print('File %s not found' % file)
        exit(1)
    os.chdir(os.path.dirname(file) if os.path.dirname(file) != '' else '.')

def load_config(config_file : str):
    check_file_and_move_dir(config_file)
    with open(config_file) as file:
        INFO.log('Loading configuration file ----> %s' % config_file)
        config = yaml.load(file, Loader=yaml.FullLoader)
    return config

def print_config(config):
    for key, value in config.items():
        if type(value) == list:
            INFO.log(key+' ----> ')
            for i in value:
                print_config(i)
                INFO.log('-------------------')
        else:
            INFO.log(str(key) + '  ----> ' + str(value))

def verify():
    print('')
    INFO.log('Run this configuration? [y/n]')
    answer = input().lower()

    while answer != 'y' and answer != 'n':
        WARNING.log('Please enter y or n')
        answer = input().lower()

    return answer == 'y'

def calculate_color_operations(color_operations : str):
    operators = []
    numbers = []
    for i in color_operations:
        if i in ['+','-']:
            operators.append(i)
        elif i.isdigit():
            numbers.append(int(i))
        else:
            ERROR.log('Invalid string %s in color.' % i)
            exit(1)

    # Validate before doing calculation.
    if len(operators) != len(numbers):
        ERROR.log('Different number of operators and numbers. Make sure %s is a valid operation.' % color_operations)
        exit(1)

    # Calculate the number to add to the color.
    number_to_add = 0
    for i in range(len(operators)):
        if operators[i] == '+':
            number_to_add += numbers[i]
        elif operators[i] == '-':
            number_to_add -= numbers[i]

    return number_to_add


def color_to_ROOT(color_input : str):
    color_dict = { 'kAzure' : ROOT.kAzure,
                  'kGreen' : ROOT.kGreen,
                    'kRed' : ROOT.kRed,
                    'kYellow' : ROOT.kYellow,
                    'kCyan' : ROOT.kCyan,
                    'kViolet' : ROOT.kViolet,
                    'kTeal' : ROOT.kTeal,}
    color_found = False
    for predef_color in color_dict:
        if predef_color in color_input:
            root_color = color_dict[predef_color]
            color_found = True
            break
    if not color_found:
        ERROR.log('Color %s not found in predefined dict! Add it!' % color_input)
        exit(1)
    
    color_operations = color_input.replace(predef_color,'')

    # Just a color inputed, return it.
    if color_operations == '':
        return root_color
    
    # Calculate the color.
    return root_color + calculate_color_operations(color_operations)

def build_background(background_samples : list, qcd_sample : str):
    background = {}
    for sample_dict in background_samples:
        try:
            sample_name = sample_dict['name']
            sample_file = sample_dict['file']
            sample_color = color_to_ROOT(sample_dict['color'])
        except KeyError as e:
            if e == 'name':
                ERROR.log('Name not given to one of the background samples. Check!')
            else:
                ERROR.log('Key % s not found in background sample: %s' % (e, sample_name))
            exit(1)
        if sample_name == 'QCDjj':
            background[sample_name] = [qcd_sample, sample_color, 1]
        else:
            background[sample_name] = [sample_file, sample_color, 0]

    return background

def generate_watermark():
    return 'ATLAS Preliminary'

def Plot():
    config = load_config('configExamplePlot.yml')
    print_config(config)
    run = verify()
    if not run:
        INFO.log('Exiting... without running!')
        exit(0)
    INFO.log('Running...')
    print(config)
    # Set the configuration.
    try:
        DATA = {"Data":["Data.root",ROOT.kBlack,0]}
        SIGNAL = {"Signal":[config['signal_sample'],ROOT.kOrange+1,0]} 
        BACKGROUND = build_background(config['background'], config['qcd_sample'])
        HISTOGRAMS = get_template(config['histograms'])
        WATERMARK = generate_watermark()
        EWjjSF = 1.0
        QCDjjSF = 1.0
        if bool(config['is_post_fit']):
            EWjjSF = config['vbf_scale']
            QCDjjSF = config['qcd_scale']
        FINAL_STATE = config['final_state']
        REGION = config['region']
        
    except KeyError as e:
        ERROR.log('Key %s not found in configuration file.' % e)
        exit(1)
    # Run the plotting.
    '''
    stackPlot(data = DATA,
              signal = SIGNAL,
              background = BACKGROUND,
              histograms = HISTOGRAMS,
              watermark = WATERMARK,
              Zprime_pack = None,
              additionalSignal = [],
              signalMu = EWjjSF,
              backgroundMu = QCDjjSF,
              average = False,
              final_state = FINAL_STATE,
              regionLabel = REGION,
              blind = True,
              blindMass = True,
              unblindPurityLimit = 0.0,
              printVersion = False,
              printOverflows = False,
              purityMultiplier = 1.0
              )
    '''

if __name__ == '__main__':
    Plot()