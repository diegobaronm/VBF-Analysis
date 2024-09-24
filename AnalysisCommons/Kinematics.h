#pragma once
#include<TLorentzVector.h>
#include"Tools.h" 
#include"rewightingTools.h"

namespace Kinematics {

struct VariablesForCutflow {
    // Relevant variables for cutflows:
    double deltaPhiLepLep{-1};
    double deltaRapidityTaggingJets{-1};
    int nBJets{-1};
    std::size_t lep1IsolationTight{0};
    std::size_t lep1IsolationLoose{0};
    std::size_t lep2IsolationTight{0};
    std::size_t lep2IsolationLoose{0};
    std::size_t nTauProngs{0};
    float tauJetRNNScore{-1};
    double lep1pT{-1};
    double lep2pT{-1};
    double taupT{-1};
    double jet1pT{-1};
    double jet2pT{-1};
    double mjj{-1};
    double pTBalance{-1};
    int nJetsInGap{-1};
    double centrality{-1};
    double omega{-100};
    double massTauLepton{-1};
    double recoMass{-1};
    double massLeptonLepton{-1};
    float eBDTScore{-1};
    double vbfBDTScore{-10};
    double lepPtAssymetry{-2};
    double recoVisibleMassRatio{-1};
    unsigned long eventNumber{0};
};

/**
 * @brief Function to calculate delta phi between two angles.
 * @param phi_1 angle 1.
 * @param phi_2 angle 2.
 * 
 */
double del_phi(double phi_1, double phi_2){
    double pi=TMath::Pi();
    double phi_1_norm, phi_2_norm;
    if (phi_1<0.0){
        phi_1_norm=phi_1+2*pi;
    }else {
        phi_1_norm=phi_1;
    }

    if (phi_2<0.0){
        phi_2_norm=phi_2+2*pi;
    }else {
        phi_2_norm=phi_2;
    }
    double delta=std::abs(phi_1_norm-phi_2_norm);
    if (delta>pi){
        delta=2*pi-delta;
        delta=std::abs(delta);
    }

    return delta;
}

/**
 * @brief This function calculates the invariant mass of a list of particles
 * @param particles A list of TLorentzVector objects pointers
 * 
 */
double Mass(const std::vector<const TLorentzVector*>& particles)
{
    double sum{0};
    for (const auto& particle1 : particles)
    {
        for (const auto& particle2 : particles)
        {
            if (particle1 == particle2) { continue;} // Skip the same particle
            sum += particle1->Dot(*particle2);
        }
    }
    return sqrt(sum);
}

/**
 * @brief This function returns true if the charge of the particles is consistent with the region name.
 * @param q1
 * @param q2
 * @param regionName
 */
bool isChargeCorrect(const std::string& regionName, float q1, float q2){
    if (regionName.size() < 2){
        g_LOG(LogLevel::ERROR, "Region name is not valid.");
        exit(1);
    }

    bool isOS = regionName.find("OS") != std::string::npos;
    bool isSS = regionName.find("SS") != std::string::npos;

    if (isOS) return q1!=q2;
    if (isSS) return q1==q2;
    else {
        g_LOG(LogLevel::ERROR, "Region name is not valid. The region should end with OS or SS.");
        exit(1);
    }
}

/**
 * @brief This function calculates the transverse mass of a particle.
 * @param particle The particle to calculate the transverse mass for.
 * @param MET The missing transverse energy.
 * @return The transverse mass of the particle.
 */
double TransverseMass(const TLorentzVector* particle, const TLorentzVector* MET)
{
    double mt = sqrt(2*particle->Pt()*MET->Pt() * (1-cos(del_phi(particle->Phi(),MET->Phi()))));
    return mt;
}

/**
 * @brief Function to see if a jet is inside the rapidity gap spanned by two jets.
 * @param test_jet Jet to test.
 * @param j1 leading jet.
 * @param j2: subleading jet.
 */
int is_inside_jets(TLorentzVector* test_jet,TLorentzVector* j1, TLorentzVector* j2){
  double delta_y_j1j2 = abs(j1->Rapidity()-j2->Rapidity());
  double delta_y_j1test = abs(j1->Rapidity()-test_jet->Rapidity());
  double delta_y_j2test = abs(j2->Rapidity()-test_jet->Rapidity());
  if(delta_y_j1test>delta_y_j1j2 || delta_y_j2test>delta_y_j1j2) return 0;
  return 1;
}

/**
 * @brief Function to calculate the minimum delta R between a test particle and a container of particles.
 * @param test_particle: particle to test.
 * @param bool_vector_container: container of booleans to select particles.
 * @param @param jet_container: container of particles to test against.
 */
double min_deltaR(TLorentzVector* test_particle, std::vector<UInt_t>& bool_vector_container,const std::vector<TLorentzVector*>& jet_container){

  std::vector<double> delta_Rs{};

  for (size_t index{0};index<jet_container.size();index++){
    if (bool_vector_container[index]!=0){
      delta_Rs.push_back(jet_container[index]->DeltaR(*test_particle));
    }
    else {break;}
  }

  double min_dR=*std::min_element(delta_Rs.begin(),delta_Rs.end());
  return min_dR;
}

/**
 * @brief Enum to define the different topologies of the tau tau system.
 * 
 */
enum TauTauTopology {
    INSIDE = 1,
    OUTSIDE_LEP = 2,
    OUTSIDE_ELEC = 2,
    OUTSIDE_TAU = 3,
    OUTSIDE_MUON = 3,
    NOT_VALID = 4,
};

/**
 * @brief Get the tau-tau topolgy of the event. This is constructed from the angles between the MET, Tau and Lepton.
 * @param deltaPhiMETLep
 * @param deltaPhiMETTau
 * @param deltaPhiTauLep
 */
TauTauTopology getTauTauTopology(double deltaPhiMETLep, double deltaPhiMETTau, double deltaPhiTauLep){
    
    bool inside = abs(deltaPhiTauLep - (deltaPhiMETLep + deltaPhiMETTau))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
    if (inside) {return TauTauTopology::INSIDE;}

    bool outside_lep = (deltaPhiMETLep < deltaPhiMETTau) && (abs(deltaPhiTauLep - (deltaPhiMETLep+deltaPhiMETTau)) > 0.00001) && (cos(deltaPhiMETLep) > 0);
    if (outside_lep) {return TauTauTopology::OUTSIDE_LEP;}

    bool outside_tau = (deltaPhiMETLep > deltaPhiMETTau) && (abs(deltaPhiTauLep - (deltaPhiMETLep+deltaPhiMETTau)) > 0.00001) && (cos(deltaPhiMETTau) > 0);
    if (outside_tau) {return TauTauTopology::OUTSIDE_TAU;}

    return TauTauTopology::NOT_VALID;
}

/**
 * @brief Get the tau neutrino particle.
 * @param topology
 * @param MET
 * @param Tau
 * @param Lepton
 */
TLorentzVector getTauNeutrino(TauTauTopology topology,const TLorentzVector* MET, const TLorentzVector* Tau, const TLorentzVector* Lepton){
    TLorentzVector neutrino{};
    if (topology == TauTauTopology::NOT_VALID){
        g_LOG(LogLevel::ERROR, "Invalid topology for tau tau system.");
        exit(1);
    } else if (topology == TauTauTopology::INSIDE){
        double cot_lep=1.0/tan(Lepton->Phi());
        double pt_tau_nu=(MET->Pt()*cos(MET->Phi())-MET->Pt()*sin(MET->Phi())*cot_lep)/(cos(Tau->Phi())-sin(Tau->Phi())*cot_lep);
        neutrino.SetPtEtaPhiM(pt_tau_nu, Tau->Eta(), Tau->Phi(), 0.0);
    } else if (topology == TauTauTopology::OUTSIDE_TAU) {
        double neutrino_pt = MET->Pt()*cos(del_phi(Tau->Phi(),MET->Phi()));
        neutrino.SetPtEtaPhiM(neutrino_pt, Tau->Eta(), Tau->Phi(), 0.0);
    }

    return neutrino;
}

/**
 * @brief Get the lep neutrino particle.
 * @param topology
 * @param MET
 * @param Tau
 * @param Lepton
 */
TLorentzVector getLepNeutrino(TauTauTopology topology,const TLorentzVector* MET, const TLorentzVector* Tau, const TLorentzVector* Lepton){
    TLorentzVector neutrino{};
    if (topology == TauTauTopology::NOT_VALID){
        g_LOG(LogLevel::ERROR, "Invalid topology for tau tau system.");
        exit(1);
    } else if (topology == TauTauTopology::INSIDE){
        double cot_tau=1.0/tan(Tau->Phi());
        double pt_lep_nu=(MET->Pt()*cos(MET->Phi())-MET->Pt()*sin(MET->Phi())*cot_tau)/(cos(Lepton->Phi())-sin(Lepton->Phi())*cot_tau);
        neutrino.SetPtEtaPhiM(pt_lep_nu, Lepton->Eta(), Lepton->Phi(), 0.0);
    } else if (topology == TauTauTopology::OUTSIDE_LEP){
        double neutrino_pt = MET->Pt()*cos(del_phi(Lepton->Phi(),MET->Phi()));
        neutrino.SetPtEtaPhiM(neutrino_pt, Lepton->Eta(), Lepton->Phi(), 0.0);
    }

    return neutrino;
}

/**
 * @brief Get the reconstructed mass of the event.
 * @param topology
 * @param Tau
 * @param Lepton
 * @param TauNu
 * @param LeptonNu
 */
double getRecoMass(TauTauTopology topology, const TLorentzVector* Tau, const TLorentzVector* Lepton, const TLorentzVector* TauNu, const TLorentzVector* LeptonNu){
    double mass{0};
    if (topology == TauTauTopology::INSIDE){
        mass = Mass(std::vector{Tau,Lepton,TauNu,LeptonNu});
    } else if (topology == TauTauTopology::OUTSIDE_LEP || topology == TauTauTopology::OUTSIDE_TAU){
        mass = 5 + Mass(std::vector{Tau,Lepton,TauNu,LeptonNu});
    } else {
        g_LOG(LogLevel::ERROR, "Invalid topology for tau tau system.");
        exit(1);
    }
    return mass;
}

/**
 * @brief Get Omega.
 * @param topology
 * @param deltaPhiMETLep
 * @param deltaPhiMETTau
 * @param deltaPhiTauLep
 */
double getOmega(TauTauTopology topology, double deltaPhiMETLep, double deltaPhiMETTau, double deltaPhiTauLep){
    double omega{0};
    if (topology == TauTauTopology::INSIDE && (deltaPhiMETLep < deltaPhiMETTau)) {
      omega = 1.0 - (deltaPhiMETLep)/(deltaPhiTauLep);
    } else if (topology == TauTauTopology::INSIDE && (deltaPhiMETLep > deltaPhiMETTau)) {
      omega = (deltaPhiMETTau)/(deltaPhiTauLep);
    } else if (topology == TauTauTopology::OUTSIDE_LEP) {
      omega = 1.0 + (deltaPhiMETLep)/(deltaPhiTauLep);
    } else if (topology == TauTauTopology::OUTSIDE_TAU) {
      omega = -1.0 * (deltaPhiMETTau)/(deltaPhiTauLep);
    } else {
      g_LOG(LogLevel::ERROR, "Invalid topology for tau tau system.");
      exit(1);
    }
    return omega;
}

/**
 * @brief Get the number of jets in the gap defined by two tagging jets.
 * @param jetsVector The two first jets should be the tagging jets.
 * @param jetsBoolVector The boolean vector indicating if the jet is present in the event or not.
 * @return The number of jets in the gap.
 */
int getNumberOfGapJets(const std::vector<TLorentzVector*>& jetsVector, const std::vector<UInt_t>& jetsBoolVector){
    // First check that the two tagging jets are present in the event.
    if (jetsBoolVector[0] == 0 || jetsBoolVector[1] == 0){
        g_LOG(LogLevel::ERROR, "At least one of the two tagging jets are not present in the event.");
        exit(1);
    }

    // Count the number of jets in the gap.
    int nGapJets{0};
    for (size_t index{2};index<jetsVector.size();index++){
        if (jetsBoolVector[index] == 0) continue;
        nGapJets += is_inside_jets(jetsVector[index], jetsVector[0], jetsVector[1]);
    }
    return nGapJets;
}

/**
 * @brief Construct the pT balance variable.
 * @param particles The particle container.
 * @return The pT balance of the event.
 */
double getPtBalance(const std::vector<TLorentzVector*>& particles){
    double scalarSum{0};
    TLorentzVector vectorSum{};
    for (const auto& particle : particles){
        scalarSum += particle->Pt();
        vectorSum += *particle;
    }

    // Calculate the pT balance.
    double pt_bal= vectorSum.Pt()/scalarSum;
    return pt_bal;
}

/**
 * @brief Construct the signed-centrality variable.
 * @param taggingJet1 The leading tagging jet.
 * @param taggingJet2 The sub-leading tagging jet.
 * @param Tau The tau jet.
 * @param Lepton The lepton.
 * @return The centrality of the event.  
 */
double getSignedCentrality(const TLorentzVector* taggingJet1, const TLorentzVector* taggingJet2, const TLorentzVector* Tau, const TLorentzVector* Lepton){
    double lepton_xi = ((*Tau) + (*Lepton)).Rapidity();
    double dijet_xi = taggingJet1->Rapidity() + taggingJet2->Rapidity();
    double delta_y = (taggingJet1->Rapidity() - taggingJet2->Rapidity());
    double centrality = (lepton_xi - 0.5*dijet_xi)/delta_y;
    return centrality;
}

/** 
 * @brief Get the region (QCDjj or EWKjj) of the event.
 * @param centrality The centrality of the event.
 * @param nJetsInGap The number of jets in the gap.
 * @return The region of the event.
 */
Region getRegion(double centrality, int nJetsInGap){
    Region region = Region::DefaultNoRW;
    if ((centrality<0.5 && centrality<=1) && nJetsInGap==0){region = Region::SR;}
    else if ((centrality<0.5 && centrality<=1) && nJetsInGap==1){region = Region::CRa;}
    else if ((centrality>=0.5 && centrality<=1) && nJetsInGap==1){region = Region::CRb;}
    else if ((centrality>=0.5 && centrality<=1) && nJetsInGap==0){region = Region::CRc;}
    return region;
}

} // namespace Kinematics