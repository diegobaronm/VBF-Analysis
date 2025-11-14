# This file contains very useful constants for the analysis

###################### RQCD Values ######################

# RQCD = 1.3 +- 0.25 -> Standard used in thesis version of the analysis.
# RQCD = 1.26 +- 0.25 -> ANA v1.0.
RQCD_VALUE = 1.38 # Value from ANA v2.0
RQCD_UNCERTAINTY_VALUE = 0.24 # Value from ANA v2.0

###################### Default Mjj Re-weighting ######################

DEFAULT_MJJ_REWEIGHTING = "RWParabolicCutoffClosure"

###################### Normalization factors for QCDjj and EWjj samples ######################

NORM_FACTORS_DICT = {} # Always QCDjj_EWjj : [qcd, vbf]

NORM_FACTORS_DICT['Zll'] = {
    'Sherpa_RWParabolicCutoffClosure_Sherpa' : [0.974, 0.973],
    'MG_RWParabolicCutoffClosure_Sherpa' : [0.964, 1.040],
    'SherpaNLO_RWParabolicCutoffClosure_Sherpa' : [1.011, 0.923],
    'MGNLO_RWParabolicCutoffClosure_Sherpa' : [1.009, 0.965],

    'Sherpa_RWParabolicCutoffClosure_PoPy' : [0.991, 0.828],
    'MG_RWParabolicCutoffClosure_PoPy' : [0.981, 0.894],
    'SherpaNLO_RWParabolicCutoffClosure_PoPy' : [1.027, 0.793],
    'MGNLO_RWParabolicCutoffClosure_PoPy' : [1.023, 0.849],

    'SherpaNLO_RWParabolicCutoffClosure_MG' : [0.940, 1.465],
    'MGNLO_RWParabolicCutoffClosure_MG' : [0.946, 1.518],

    'SherpaNLO_RWParabolicCutoff_Sherpa' : [1.000, 0.982],
    'MGNLO_RWParabolicCutoff_Sherpa' : [0.953, 1.309],

    'SherpaNLO_RWParabolicCutoff_PoPy' : [1.017, 0.843],
    'MGNLO_RWParabolicCutoff_PoPy' : [0.974, 1.127],

    'Sherpa_RWExponentialClosure_Sherpa' : [0.969, 0.980],
    'SherpaNLO_RWExponentialClosure_Sherpa' : [1.004, 0.948],

    'Sherpa_RWExponentialClosure_PoPy' : [0.987, 0.832],
    'SherpaNLO_RWExponentialClosure_PoPy' : [1.021, 0.812],
}

NORM_FACTORS_DICT['Ztautau'] = {
    'Sherpa_RWParabolicCutoffClosure_Sherpa' : [1.000, 1.101],
    'MG_RWParabolicCutoffClosure_Sherpa' : [1.040,1.010],
    'SherpaNLO_RWParabolicCutoffClosure_Sherpa' : [1.071, 0.870],
    'MGNLO_RWParabolicCutoffClosure_Sherpa' : [1.201, 0.744],

    'SherpaNLO_RWParabolicCutoffClosure_MG' : [1.046, 1.391],
    'MGNLO_RWParabolicCutoffClosure_MG' : [1.281, 0.836],

    'Sherpa_RWParabolicCutoffClosure_PoPy' : [1.050, 0.898],
    'MG_RWParabolicCutoffClosure_PoPy' : [1.083, 0.831],
    'SherpaNLO_RWParabolicCutoffClosure_PoPy' : [1.106, 0.720],
    'MGNLO_RWParabolicCutoffClosure_PoPy' : [1.220,0.652],
}

NORM_FACTORS_DICT['Zee'] = {
    'Sherpa_RWParabolicCutoffClosure_Sherpa' : [0.947, 0.994],
    'MG_RWParabolicCutoffClosure_Sherpa' : [0.964, 1.061],
    'SherpaNLO_RWParabolicCutoffClosure_Sherpa' : [1.027, 0.900],
    'MGNLO_RWParabolicCutoffClosure_Sherpa' : [1.025, 0.922],

    'SherpaNLO_RWParabolicCutoffClosure_MG' : [0.940, 1.465],
    'MGNLO_RWParabolicCutoffClosure_MG' : [0.946, 1.518],

    'Sherpa_RWParabolicCutoffClosure_PoPy' : [0.967, 0.846],
    'MG_RWParabolicCutoffClosure_PoPy' : [0.984, 0.911],
    'SherpaNLO_RWParabolicCutoffClosure_PoPy' : [1.043, 0.775],
    'MGNLO_RWParabolicCutoffClosure_PoPy' : [1.041, 0.806],
}

NORM_FACTORS_DICT['Zmumu'] = {
    'Sherpa_RWParabolicCutoffClosure_Sherpa' : [0.995, 0.956],
    'MG_RWParabolicCutoffClosure_Sherpa' : [0.963, 1.020],
    'SherpaNLO_RWParabolicCutoffClosure_Sherpa' : [1.000, 0.936],
    'MGNLO_RWParabolicCutoffClosure_Sherpa' : [0.994, 1.013],

    'SherpaNLO_RWParabolicCutoffClosure_MG' : [0.940, 1.465],
    'MGNLO_RWParabolicCutoffClosure_MG' : [0.946, 1.518],

    'Sherpa_RWParabolicCutoffClosure_PoPy' : [0.967, 0.846],
    'MG_RWParabolicCutoffClosure_PoPy' : [0.984, 0.911],
    'SherpaNLO_RWParabolicCutoffClosure_PoPy' : [1.043, 0.775],
    'MGNLO_RWParabolicCutoffClosure_PoPy' : [1.041, 0.806],
}