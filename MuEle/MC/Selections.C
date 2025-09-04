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
    // Always subtract the OS or SS string at the end of the selection name.
    const std::string selName = selectionName.substr(0,selectionName.size()-2);

    // Define the vector to be returned.
    std::vector<std::string> cutNames{};

    if (selName == "BeforeEBZpeak"){
        cutNames = {"basic","dphi","drap","btag","iso","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mreco","tpt"};
    } else if (selName == "Zpeak"){
        cutNames = {"basic","dphi","drap","btag","iso","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mreco","tpt","rvr"};
    } else {
        g_LOG(LogLevel::ERROR, "Selection name not found!");
        exit(1);
    }
    return cutNames;
}

std::vector<int> CLoop::ApplySelection(const std::string& selectionName, const Kinematics::VariablesForCutflow& vars){
    // Always subtract the OS or SS string at the end of the selection name.
    const std::string selName = selectionName.substr(0,selectionName.size()-2);

    // Define the vector to be returned.
    std::vector<int> cuts;

    // Region: Z  peak
    if (selName == "BeforeEBZpeak"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 1000 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.4 && vars.omega < 1.4 );
        cuts.push_back( vars.recoMass < 116 && vars.recoMass > 66 );
        cuts.push_back( vars.lep2pT >= 27 );

    } else if (selName == "Zpeak"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.4 && vars.omega < 1.4 );
        cuts.push_back( vars.recoMass < 116 && vars.recoMass > 66 );
        cuts.push_back( vars.lep2pT >= 27 );
        cuts.push_back( vars.recoVisibleMassRatio < 4.0 );

    } else if (selName == "HighMass"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.4 && vars.omega < 1.4 );
        cuts.push_back( vars.recoMass >= 160 );
        cuts.push_back( vars.lep2pT >= 27 );

    } else {
        g_LOG(LogLevel::ERROR, "Selection name not found!");
        exit(1);
    }
    
    return cuts;
}