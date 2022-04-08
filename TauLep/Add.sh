#!/bin/bash

tau_e=../EleTau/Plots
tau_mu=../TauMu/Plots

hadd Ztautau_MG.root $tau_e/Ztautau_MG.root $tau_mu/Ztautau_MG.root
hadd Ztautau_Sherpa.root $tau_e/Ztautau_Sherpa.root $tau_mu/Ztautau_Sherpa.root
hadd Ztautau_PoPy.root $tau_e/Ztautau_PoPy.root $tau_mu/Ztautau_PoPy.root
hadd Data.root $tau_e/Data.root $tau_mu/Data.root
hadd VV.root $tau_e/VV.root $tau_mu/VV.root
hadd singletop.root $tau_e/singletop.root $tau_mu/singletop.root
hadd Wjets.root $tau_e/Wjets.root $tau_mu/Wjets.root
hadd Higgs.root $tau_e/Higgs.root $tau_mu/Higgs.root
hadd Signal_PoPy.root $tau_e/Signal_PoPy.root $tau_mu/Signal_PoPy.root
hadd Signal_Sherpa.root $tau_e/Signal_Sherpa.root $tau_mu/Signal_PoPy.root
hadd Zjets.root $tau_e/Zjets.root $tau_mu/Zjet.root
hadd ttbar.root $tau_e/ttbar.root $tau_mu/ttbar.root
