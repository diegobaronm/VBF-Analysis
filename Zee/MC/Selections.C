/**  
 * @brief This file contains the code that steers every selection (Region) of the analysis.
 *
*/
#pragma once
#include <vector>
#include <string>
#include"../../AnalysisCommons/Kinematics.h"
#include"../../AnalysisCommons/Tools.h" 

namespace Selections {

std::vector<std::string> InitCutNames(const std::string& selectionName){
    // Always subtract the OS or SS string at the end of the selection name.
    const std::string selName = selectionName.substr(0,selectionName.size()-2);

    // Define the vector to be returned.
    std::vector<std::string> cutNames{};

    if (selName == "Zpeak" || selName == "Inclusive" || selName == "MediumMass" || selName == "HighMass" || selName == "CRa" || selName == "CRb" || selName == "CRc") {
        cutNames = {"basic","dphi","drap","btag","iso","pt1","pt2","j1pt","j2pt","ptbal","mjj","nji","zcen","mass","ptl"};
    } else  if (selName == "HighMassQCD") {
        cutNames = {"basic","dphi","drap","btag","iso","pt1","pt2","j1pt","j2pt","ptbal","mjj","qcdcr","mass","ptl"};
    } else {
        g_LOG(LogLevel::ERROR, "Selection name not found!");
        exit(1);
    }
    return cutNames;
}

std::vector<int> ApplySelection(const std::string& selectionName, const Kinematics::VariablesForCutflow& vars){
    // Always subtract the OS or SS string at the end of the selection name.
    const std::string selName = selectionName.substr(0,selectionName.size()-2);

    // Define the vector to be returned.
    std::vector<int> cuts;

    // Region: Z  peak
    if (selName == "Zpeak"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.massLeptonLepton < 101 && vars.massLeptonLepton > 81 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "Inclusive"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 1 || vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality <= 1.0 );
        cuts.push_back( vars.massLeptonLepton < 101 && vars.massLeptonLepton > 81 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "CRa"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 1 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.massLeptonLepton < 101 && vars.massLeptonLepton > 81 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "CRb"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 1 );
        cuts.push_back( vars.centrality >= 0.5 && vars.centrality <= 1.0);
        cuts.push_back( vars.massLeptonLepton < 101 && vars.massLeptonLepton > 81 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "CRc"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality >= 0.5 && vars.centrality <= 1.0);
        cuts.push_back( vars.massLeptonLepton < 101 && vars.massLeptonLepton > 81 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "MediumMass"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.massLeptonLepton < 160 && vars.massLeptonLepton >= 101 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "HighMass"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( vars.nJetsInGap == 0 );
        cuts.push_back( vars.centrality < 0.5 );
        cuts.push_back( vars.massLeptonLepton >= 160 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else if (selName == "HighMassQCD"){
        double a{50},b{40};
        cuts.push_back( vars.deltaPhiLepLep <= 3.2 );
        cuts.push_back( vars.deltaRapidityTaggingJets >= 2.0 );
        cuts.push_back( vars.nBJets == 0 );
        cuts.push_back( vars.lep1IsolationTight == 1 && vars.lep2IsolationTight == 1 );
        cuts.push_back( vars.lep1pT >= a );
        cuts.push_back( vars.lep2pT >= b );
        cuts.push_back( vars.jet1pT >= 75 );
        cuts.push_back( vars.jet2pT >= 70 );
        cuts.push_back( vars.pTBalance <= 0.15 );
        cuts.push_back( vars.mjj >= 750 );
        cuts.push_back( (vars.nJetsInGap == 0 && vars.centrality >= 0.5 && vars.centrality <= 1.0) || (vars.nJetsInGap == 1 && vars.centrality <= 1.0) );
        cuts.push_back( vars.massLeptonLepton >= 101 ); // Z-peak mass range 81 < inv_mass < 101 GeV. // Mid Range inv_mass < 160 && inv_mass >= 101 
        if (vars.eventNumber %2 == 0) cuts.push_back( vars.lep1pT >= a );
        else cuts.push_back( vars.lep2pT >= b );
    } else {
        g_LOG(LogLevel::ERROR, "Selection name not found!");
        exit(1);
    }
    
    return cuts;
}

}