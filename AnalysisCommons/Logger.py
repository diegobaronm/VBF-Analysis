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
    # Static variable
    LOGLEVEL = 4
    def __init__(self,level, colour):
        self.m_level = level
        self.m_colour = colour
        self.s_LOG_LEVELS = {"ERROR":1,"WARNING":2, "INFO":3, "DEBUG":4}
    def log(self,message, variable = ""):
        if self.s_LOG_LEVELS[self.m_level] <= Logger.LOGLEVEL:
            message = self.m_colour+self.m_level+': '+bcolors.ENDC+message
            print(message, variable)
    @staticmethod
    def setLogLevel(level):
        if level > 4 or level < 1:
            raise ValueError("Log level must be between 1 and 4.")
        Logger.LOGLEVEL = level

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