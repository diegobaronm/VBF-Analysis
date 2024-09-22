/**  
 * @brief This file contains the code that steers every selection (Region) of the analysis.
 *
*/
#pragma once
#include <vector>
#include <string>
#include"../../AnalysisCommons/Kinematics.h"
#include"../../AnalysisCommons/Tools.h" 


std::vector<std::string> CLoop::InitCutNames(const std::string& selectionName){
    std::vector<std::string> cutNames{};

    if (selectionName == "Zpeak"){
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt"}; 
    } else {
        g_LOG(LogLevel::ERROR, "Selection name not found!");
        exit(1);
    }
    return cutNames;
}

std::vector<int> CLoop::ApplySelection(const std::string& selectionName, const Kinematics::VariablesForCutflow& vars){
    
    std::vector<int> cuts;

    // Region: Z  peak
    if (selectionName == "Zpeak"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 );

        bool oneProngId = vars.nTauProngs == 1 && vars.tauJetRNNScore >= 0.25; // Medium = shift by 0.15
        bool threeProngId = vars.nTauProngs == 3 && vars.tauJetRNNScore >= 0.40;
        cuts.push_back( oneProngId || threeProngId );

        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 1000 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.6 );
        cuts.push_back( vars.massTauLepton <= 80 );
        cuts.push_back( vars.eBDTScore >= 0.5 );
        cuts.push_back( vars.recoMass < 116 && vars.recoMass > 66 );
        cuts.push_back( vars.taupT >= 25 );
    }


    if ((m_cutNames.size() - 1) != cuts.size()){
        g_LOG(LogLevel::ERROR, "The number of cuts is not consistent with the number of cut names.");
        exit(1);
    }

    return cuts;
}