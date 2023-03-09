#include "RooStats/HistFactory/Measurement.h"
#include "RooStats/HistFactory/MakeModelAndMeasurementsFast.h"
#include "TFile.h"
#include "TROOT.h"
 
using namespace RooStats;
using namespace HistFactory;
using namespace RooFit;
 
void Fit() {
 

    std::string InputFile = "histograms.root";


    // Create the measurement
    Measurement meas("meas", "meas");

    meas.SetOutputFilePrefix( "./results/example_UsingPy" );
    meas.SetPOI( "SF-VBF" );
    meas.AddConstantParam("Lumi");
    meas.SetBinLow(9);
    meas.SetBinHigh(11);

    meas.SetLumi( 1 );
    meas.SetLumiRelErr( 0.017 );
    meas.SetExportOnly( false );

    // Create a channel

    Channel chan( "channel1" );
    chan.SetData( "Data", "histograms.root" );
    chan.SetStatErrorConfig( 0.05, "Poisson" );


    // Now, create some samples


    // Create the signal sample
    Sample signal( "Signal", "Signal", "histograms.root" );
    signal.AddNormFactor( "SF-VBF", 100, 0, 5000 );
    signal.ActivateStatError();
    chan.AddSample( signal );

    // Background 1
    Sample background1( "QCDjj", "QCDjj", "histograms.root" );
    background1.ActivateStatError();
    background1.AddNormFactor( "SF-QCD", 1000, 0, 30000);
    chan.AddSample( background1 );


    // Done with this channel
    // Add it to the measurement:
    meas.AddChannel( chan );

    // Collect the histograms from their files,
    // print some output,
    meas.CollectHistograms();
    meas.PrintTree();

    // One can print XML code to an
    // output directory:
    // meas.PrintXML( "xmlFromCCode", meas.GetOutputFilePrefix() );

    // Now, do the measurement
    RooWorkspace* results = MakeModelAndMeasurementFast( meas );

    RooRealVar x("x", "x", 0.0, 5000.0);
    x.setRange("Above250", 250.0, 5000.0);

    RooStats::ModelConfig* mc = (RooStats::ModelConfig*)results->obj("ModelConfig");
    RooAbsData* data = results->data("obsData");
    RooFitResult* fitResult = mc->GetPdf()->fitTo(*data, Range("Above250"), Save(true),RooFit::PrintLevel(-1));

    // set normalisations and errors
    double qcd     = results->var("SF-QCD")->getVal();
    double qcdUncern  = results->var("SF-QCD")->getError();

    double vbf     = results->var("SF-VBF")->getVal();
    double vbfUncern  = results->var("SF-VBF")->getError();

    

    std::cout << "VBF = " << vbf << " +/- " << vbfUncern << std::endl;
    std::cout << "QCD = " << qcd << " +/- " << qcdUncern << std::endl;

}