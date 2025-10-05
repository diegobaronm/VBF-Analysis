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
    'Sherpa_RWParabolicCutoffClosure_Sherpa' : [0.974, 0.973],
    'MG_RWParabolicCutoffClosure_Sherpa' : [0.964, 1.040],
    'SherpaNLO_RWParabolicCutoffClosure_Sherpa' : [1.011, 0.923],
    'MGNLO_RWParabolicCutoffClosure_Sherpa' : [1.009, 0.965],

    'Sherpa_RWParabolicCutoffClosure_PoPy' : [0.991, 0.828],
    'MG_RWParabolicCutoffClosure_PoPy' : [0.981, 0.894],
    'SherpaNLO_RWParabolicCutoffClosure_PoPy' : [1.027, 0.793],
    'MGNLO_RWParabolicCutoffClosure_PoPy' : [1.023, 0.849],

    'SherpaNLO_RWParabolicCutoff_Sherpa' : [1.000, 0.982],
    'MGNLO_RWParabolicCutoff_Sherpa' : [0.953, 1.309],

    'SherpaNLO_RWParabolicCutoff_PoPy' : [1.017, 0.843],
    'MGNLO_RWParabolicCutoff_PoPy' : [0.974, 1.127],

    'Sherpa_RWExponentialClosure_Sherpa' : [0.969, 0.980],
    'SherpaNLO_RWExponentialClosure_Sherpa' : [1.004, 0.948],

    'Sherpa_RWExponentialClosure_PoPy' : [0.987, 0.832],
    'SherpaNLO_RWExponentialClosure_PoPy' : [1.021, 0.812],
}