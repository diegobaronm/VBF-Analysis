# Define  colours for the output
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Logger:
    # Static variables
    LOGLEVEL = 4
    LOG_FILE = None       # Set via enableFileLogging() to also write to a file

    def __init__(self,level, colour):
        self.m_level = level
        self.m_colour = colour
        self.s_LOG_LEVELS = {"ERROR":1,"WARNING":2, "INFO":3, "DEBUG":4}

    def log(self,message, variable = None):
        if self.s_LOG_LEVELS[self.m_level] <= Logger.LOGLEVEL:
            coloured = self.m_colour + self.m_level + ': ' + bcolors.ENDC + message
            plain    = self.m_level + ': ' + message
            if variable is not None:
                print(coloured, variable)
                if Logger.LOG_FILE is not None:
                    Logger.LOG_FILE.write(plain + " " + str(variable) + "\n")
                    Logger.LOG_FILE.flush()
            else:
                print(coloured)
                if Logger.LOG_FILE is not None:
                    Logger.LOG_FILE.write(plain + "\n")
                    Logger.LOG_FILE.flush()

    @staticmethod
    def setLogLevel(level):
        if level > 4 or level < 1:
            raise ValueError("Log level must be between 1 and 4.")
        Logger.LOGLEVEL = level

    @staticmethod
    def enableFileLogging(filepath):
        """Enable logging to a file in addition to stdout."""
        try:
            Logger.LOG_FILE = open(filepath, "a")
        except (OSError, IOError) as e:
            print("ERROR: Failed to open log file '%s': %s" % (filepath, e))

    @staticmethod
    def disableFileLogging():
        """Stop logging to a file and close the handle."""
        if Logger.LOG_FILE is not None:
            Logger.LOG_FILE.close()
            Logger.LOG_FILE = None

INFO = Logger("INFO",bcolors.OKGREEN)
WARNING = Logger("WARNING",bcolors.WARNING)
ERROR = Logger("ERROR",bcolors.FAIL)
DEBUG = Logger("DEBUG",bcolors.OKBLUE)

# Create a banner for when starting the code
def BANNER(channel):
    banner_string = "#########################################################\n"
    banner_string += f"#####   Starting VBF Analysis for channel {channel}   #########\n"
    banner_string += "###############################################################\n"
    banner_string = bcolors.HEADER + banner_string + bcolors.ENDC
    return banner_string

def menu(question, options):
    """Reusable interactive menu. Returns the 1-based index chosen by the user."""
    incorrect_answer = True
    while incorrect_answer:
        INFO.log(question)
        for idx, option in enumerate(options, 1):
            INFO.log("%d) %s" % (idx, option))
        answer = input()
        try:
            answer_int = int(answer)
        except ValueError:
            INFO.log("Please enter a number!")
            continue
        if 1 <= answer_int <= len(options):
            incorrect_answer = False
        else:
            INFO.log("Select a correct option!")
    return answer_int