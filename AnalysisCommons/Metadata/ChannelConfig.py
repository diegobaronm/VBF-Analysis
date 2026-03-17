# Channel configuration registry.
# Maps channel names to their metadata modules and output paths,
# removing the need for per-channel RunAnalysis.py duplicates.

from .infofileTauTau import infos as infos_tautau
from .datasetsTauTau import dataSets as dataSets_tautau, realList as realList_tautau, dataCombos as dataCombos_tautau, dirs as dirs_tautau
from .infofileZmumu import infos as infos_zmumu
from .datasetsZmumu import dataSets as dataSets_zmumu, realList as realList_zmumu, dataCombos as dataCombos_zmumu, dirs as dirs_zmumu
from .infofileZee import infos as infos_zee
from .datasetsZee import dataSets as dataSets_zee, realList as realList_zee, dataCombos as dataCombos_zee, dirs as dirs_zee
from .OutputPaths import Zte_outputs_path, Ztm_outputs_path, Zem_outputs_path, Zmm_outputs_path, Zee_outputs_path

# Each entry maps a channel name to (dataCombos, dataSets, realList, infos, dirs, output_dict)
CHANNEL_CONFIG = {
    "EleTau": {
        "dataCombos": dataCombos_tautau,
        "dataSets":   dataSets_tautau,
        "realList":   realList_tautau,
        "infos":      infos_tautau,
        "dirs":       dirs_tautau,
        "output_dict": Zte_outputs_path,
        "label":      "Ztaue",
    },
    "TauMu": {
        "dataCombos": dataCombos_tautau,
        "dataSets":   dataSets_tautau,
        "realList":   realList_tautau,
        "infos":      infos_tautau,
        "dirs":       dirs_tautau,
        "output_dict": Ztm_outputs_path,
        "label":      "Ztaumu",
    },
    "MuEle": {
        "dataCombos": dataCombos_tautau,
        "dataSets":   dataSets_tautau,
        "realList":   realList_tautau,
        "infos":      infos_tautau,
        "dirs":       dirs_tautau,
        "output_dict": Zem_outputs_path,
        "label":      "Zemu",
    },
    "MuMu": {
        "dataCombos": dataCombos_zmumu,
        "dataSets":   dataSets_zmumu,
        "realList":   realList_zmumu,
        "infos":      infos_zmumu,
        "dirs":       dirs_zmumu,
        "output_dict": Zmm_outputs_path,
        "label":      "Zmumu",
    },
    "Zee": {
        "dataCombos": dataCombos_zee,
        "dataSets":   dataSets_zee,
        "realList":   realList_zee,
        "infos":      infos_zee,
        "dirs":       dirs_zee,
        "output_dict": Zee_outputs_path,
        "label":      "Zee",
    },
}

VALID_CHANNELS = list(CHANNEL_CONFIG.keys())

def get_channel_config(channel_name):
    """Return the config dict for a given channel name, or exit with an error."""
    if channel_name not in CHANNEL_CONFIG:
        from AnalysisCommons.Logger import ERROR
        ERROR.log("Unknown channel '%s'. Valid channels: %s" % (channel_name, ", ".join(VALID_CHANNELS)))
        exit(1)
    return CHANNEL_CONFIG[channel_name]
