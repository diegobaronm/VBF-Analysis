// Header file with common tools used in analysis.
#pragma once
#include <vector>
#include <TMVA/Reader.h>
#include <sstream>
#include <string>
// Error message with colors!
const char* g_ERROR_MESSAGE = "\033[1;31mERROR:\033[0m";

// Function to split a string by a delimiter and return a vector of strings.
// Like Python's split function.
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Run numbers
const int run2015Begin = 276262;
const int run2015End   = 284484;

const int run2016Begin = 297730;
const int run2016End   = 311481;

const int run2017Begin = 323427;
const int run2017End   = 341649;

const int run2018Begin = 341649;
const int run2018End   = 364292;


// Function to calculate delta phi between two angles
// @param phi_1: angle 1
// @param phi_2: angle 2
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

// Function to see if a jet is inside the rapidity gap defined by two jets
// @param test_jet: jet to test
// @param j1: leading jet
// @param j2: subleading jet
int is_inside_jets(TLorentzVector * test_jet,TLorentzVector * j1, TLorentzVector * j2){
  double delta_y_j1j2=abs(j1->Rapidity()-j2->Rapidity());
  double delta_y_j1test=abs(j1->Rapidity()-test_jet->Rapidity());
  double delta_y_j2test=abs(j2->Rapidity()-test_jet->Rapidity());
  if(delta_y_j1test>delta_y_j1j2 || delta_y_j2test>delta_y_j1j2){return 0;}
  else{return 1;}
}

// Function to calculate the minimum delta R between a test particle and a container of particles
// @param test_particle: particle to test
// @param bool_vector_container: container of booleans to select particles
// @param jet_container: container of particles to test against
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

// Class to manage the BDT
class VBFBDT {
  public:
    VBFBDT(const std::string& weightsFilePath) {
        m_reader = new TMVA::Reader("Silent");
        m_reader->AddVariable("mjj",&m_bdt_mjj);
        m_reader->AddVariable("deltaRapidity",&m_bdt_drap);
        m_reader->AddVariable("ptBalance",&m_bdt_ptbal);
        m_reader->AddVariable("zCentrality",&m_bdt_zcen);
        m_reader->AddVariable("omega",&m_bdt_omega);
        //reader->AddVariable("transverseMassLep",&bdt_transmasslep);
        m_reader->AddVariable("transverseRecoMassVariable",&m_bdt_transmasslep); // For transverse-reco mass ratio
        m_reader->AddSpectator("eventNumber", &m_bdt_eventNumber); // For deterministic split
        m_reader->BookMVA("VBF_BDT", weightsFilePath.c_str());
    }

    ~VBFBDT() {
        delete m_reader;
    }

    void update(float mjj, float drap, float ptbal, float zcen, float omega, float transmasslep, float eventNumber) {
        m_bdt_mjj = mjj;
        m_bdt_drap = drap;
        m_bdt_ptbal = ptbal;
        m_bdt_zcen = zcen;
        m_bdt_omega = omega;
        m_bdt_transmasslep = transmasslep;
        m_bdt_eventNumber = eventNumber;
    }

    double evaluate() {
        double bdtScore = m_reader->EvaluateMVA("VBF_BDT");
        reset();
        return bdtScore;
    }

    void reset() {
        m_bdt_mjj = 0;
        m_bdt_drap = 0;
        m_bdt_ptbal = 0;
        m_bdt_zcen = 0;
        m_bdt_omega = 0;
        m_bdt_transmasslep = 0;
        m_bdt_eventNumber = 0;
    }

  private:
    TMVA::Reader* m_reader;
    float m_bdt_mjj;
    float m_bdt_drap;
    float m_bdt_ptbal;
    float m_bdt_zcen;
    float m_bdt_omega;
    float m_bdt_transmasslep;
    float m_bdt_eventNumber;

};