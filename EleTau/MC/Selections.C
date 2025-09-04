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
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt"}; 
    } else if (selName == "NoBDTZpeak"){
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt","ptsym","rvr"};
    } else if (selName == "Zpeak"){
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt","mva","ptsym","rvr"};
    } else if (selName == "HighMass"){
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt","mva","ptsym","rvr"};
    } else if (selName == "FailedMVA"){
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt","failmva"};
    } else if (selName == "MJCR"){
        cutNames = {"basic","dphi","drap","btag","ptl","j1pt","j2pt","ptbal","mjj","zcen","omega","mlt","ebdt","mreco","tpt","mva","ptsym","rvr","mjcr"};
    } else if (selName == "MJValidation"){
        cutNames = {"basic","dphi","drap","btag","iso","rnn","ptl","j1pt","j2pt","ptbal","mjj","nji","zcen","omega","mlt","ebdt","mreco","tpt","ptsym","rvr"};
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
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass < 116 && vars.recoMass > 66 );
        cuts.push_back( vars.taupT >= 25 );

    } else if (selName == "NoBDTZpeak"){
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
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.6 );
        cuts.push_back( vars.massTauLepton <= 80 );
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass < 116 && vars.recoMass > 66 );
        cuts.push_back( vars.taupT >= 25 );
        cuts.push_back( vars.lepPtAssymetry > -0.3 );
        cuts.push_back( vars.recoVisibleMassRatio < 4.0 );

    } else if (selName == "Zpeak"){
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
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.6 );
        cuts.push_back( vars.massTauLepton <= 80 );
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass < 116 && vars.recoMass > 66 );
        cuts.push_back( vars.taupT >= 25 );
        cuts.push_back( vars.vbfBDTScore > 0.3 );
        cuts.push_back( vars.lepPtAssymetry > -0.3 );
        cuts.push_back( vars.recoVisibleMassRatio < 4.0 );

    } else if (selName == "HighMass"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 );

        bool oneProngId = vars.nTauProngs == 1 && vars.tauJetRNNScore >= 0.40; // Medium = shift by 0.15
        bool threeProngId = vars.nTauProngs == 3 && vars.tauJetRNNScore >= 0.55;
        cuts.push_back( oneProngId || threeProngId );

        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.4 );
        cuts.push_back( vars.massTauLepton <= 80 || vars.massTauLepton >= 100);
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass >= 160);
        cuts.push_back( vars.taupT >= 25 );
        cuts.push_back( vars.vbfBDTScore > 0.3 );
        cuts.push_back( vars.lepPtAssymetry > -0.3 );
        cuts.push_back( vars.recoVisibleMassRatio < 4.0 );

    } else if (selName == "FailedMVA"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 );

        bool oneProngId = vars.nTauProngs == 1 && vars.tauJetRNNScore >= 0.25;
        bool threeProngId = vars.nTauProngs == 3 && vars.tauJetRNNScore >= 0.40;
        cuts.push_back( oneProngId || threeProngId );

        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.4 );
        cuts.push_back( vars.massTauLepton <= 80 || vars.massTauLepton >= 100);
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass >= 160);
        cuts.push_back( vars.taupT >= 25 );
        cuts.push_back( vars.vbfBDTScore <= 0.3 || vars.lepPtAssymetry <= -0.3 || vars.recoVisibleMassRatio >= 4.0 || (vars.nTauProngs == 1 && vars.tauJetRNNScore < 0.4) || (vars.nTauProngs == 3 && vars.tauJetRNNScore < 0.55) ) ;
    
    } else if (selName == "MJCR"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 65 );
        cuts.push_back( vars.jet2pT >= 60 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 400 );
        cuts.push_back( vars.centrality <= 1.0 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.4 );
        cuts.push_back( vars.massTauLepton <= 80 || vars.massTauLepton >= 100);
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass >= 160);
        cuts.push_back( vars.taupT >= 25 );
        cuts.push_back( vars.vbfBDTScore > 0.3 );
        cuts.push_back( vars.lepPtAssymetry > -0.3 );
        cuts.push_back( vars.recoVisibleMassRatio < 4.0 );
        cuts.push_back( vars.lep1IsolationTight == 0 || (vars.nTauProngs == 1 && vars.tauJetRNNScore < 0.4) || (vars.nTauProngs == 3 && vars.tauJetRNNScore < 0.55) );

    } else if (selName == "MJValidation"){
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 );

        bool oneProngId = vars.nTauProngs == 1 && vars.tauJetRNNScore < 0.25;
        bool threeProngId = vars.nTauProngs == 3 && vars.tauJetRNNScore < 0.40;
        cuts.push_back( oneProngId || threeProngId );

        cuts.push_back( vars.lep1pT >= 27 );
        cuts.push_back( vars.jet1pT >= 65 );
        cuts.push_back( vars.jet2pT >= 60 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 500 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.omega > -0.2 && vars.omega < 1.4 );
        cuts.push_back( vars.massTauLepton <= 80 || vars.massTauLepton >= 100);
        cuts.push_back( vars.eBDTScore >= 0.05 );
        cuts.push_back( vars.recoMass >= 160);
        cuts.push_back( vars.taupT >= 25 );
        cuts.push_back( vars.lepPtAssymetry > -0.3 );
        cuts.push_back( vars.recoVisibleMassRatio < 4.0 );

    } else {
        g_LOG(LogLevel::ERROR, "Selection name not found!");
        exit(1);
    }
    
    return cuts;
}