# This file contains very useful constants for the analysis

###################### RQCD Values ######################

# RQCD = 1.3 +- 0.25 -> Standard used in thesis version of the analysis.
# RQCD = 1.26 +- 0.25 -> ANA v1.0.
RQCD_VALUE = 1.38 # Value from ANA v2.0
RQCD_UNCERTAINTY_VALUE = 0.24 # Value from ANA v2.0

###################### Default Mjj Re-weighting ######################

DEFAULT_MJJ_REWEIGHTING = "RWParabolicCutoffClosure"

###################### Normalization factors for QCDjj and EWjj samples ######################

NORM_FACTORS_DICT = { # Always QCDjj_EWjj : [qcd, vbf]
    'Sherpa_RWParabolicCutoffClosure_Sherpa' : [0.942, 1.170],
    'MG_RWParabolicCutoffClosure_Sherpa' : [0.943, 1.102],
    'SherpaNLO_RWParabolicCutoffClosure_Sherpa' : [1.000, 0.982],
    'MGNLO_RWParabolicCutoffClosure_Sherpa' : [0.953, 1.309],

    'Sherpa_RWParabolicCutoff_Sherpa' : [0.942, 1.170],
    'MG_RWParabolicCutoff_Sherpa' : [0.943, 1.102],
    'SherpaNLO_RWParabolicCutoff_Sherpa' : [1.000, 0.982],
    'MGNLO_RWParabolicCutoff_Sherpa' : [0.953, 1.309],

    'Sherpa_RWExponential_Sherpa' : [0.937, 1.182],
    'MG_RWExponential_Sherpa' : [0.935, 1.130],
    'SherpaNLO_RWExponential_Sherpa' : [0.993, 1.006],

    'Sherpa_RWParabolic_Sherpa' : [0.942, 1.170],
    'MG_RWParabolic_Sherpa' : [0.943, 1.104],

    'Sherpa_RWParabolicCutoff_PoPy' : [0.962, 0.999],
    'MG_RWParabolicCutoff_PoPy' : [0.961, 0.947],
    'SherpaNLO_RWParabolicCutoff_PoPy' : [1.017, 0.843],
    'MGNLO_RWParabolicCutoff_PoPy' : [0.974, 1.127],

    'Sherpa_RWParabolicCutoffClosure_PoPy' : [0.962, 0.999],
    'MG_RWParabolicCutoffClosure_PoPy' : [0.961, 0.947],
    'SherpaNLO_RWParabolicCutoffClosure_PoPy' : [1.017, 0.843],
    'MGNLO_RWParabolicCutoffClosure_PoPy' : [0.974, 1.127],

    'Sherpa_RWExponential_PoPy' : [0.962, 0.999],
    'MG_RWExponential_PoPy' : [0.961, 0.947],
    'SherpaNLO_RWExponential_PoPy' : [1.017, 0.843],

    'Sherpa_RWParabolic_PoPy' : [0.962, 0.999],
    'MG_RWParabolic_PoPy' : [0.961, 0.947],
}