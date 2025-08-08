#ifndef reweightingTools_h
#define reweightingTools_h
#include <map>
#include "Tools.h"

double zpT_rw_popy(double zpt){
    double z_w = 1.0;
    if(zpt>=40 & zpt<46){
        z_w=0.995;
    }else if(zpt>=46 & zpt<48){
        z_w=0.99;
    }else if(zpt>=48 & zpt<51){
        z_w=0.983;
    }else if(zpt>=51 & zpt<54){
        z_w=0.974;
    }else if(zpt>=54 & zpt<58){
        z_w=0.978;
    }else if(zpt>=58 & zpt<60){
        z_w=0.969;
    }else if(zpt>=60 & zpt<65){
        z_w=0.95;
    }else if(zpt>=65 & zpt<70){
        z_w=0.949;
    }else if(zpt>=70 & zpt<75){
        z_w=0.942;
    }else if(zpt>=75 & zpt<80){
        z_w=0.937;
    }else if(zpt>=80 & zpt<85){
        z_w=0.92;
    }else if(zpt>=85 & zpt<95){
        z_w=0.9;
    }else if(zpt>=95 & zpt<108){
        z_w=0.891;
    }else if(zpt>=108 & zpt<130){
        z_w=0.863;
    }else if(zpt>=130 & zpt<151){
        z_w=0.84;
    }else if(zpt>=151){
        z_w=0.8;
    }
    return z_w;
}

double parabolicMjjRW(double mjj, double a, double b, double c){
    double rw = a*mjj*mjj+b*mjj+c;
    if (rw < 0){
        return 0.0;
    } else {
        return rw;
    }
}

double linearMjjRW(double mjj, double slope, double level){
    double rw = slope*mjj+level;
    if (rw < 0){
        return 0.0;
    } else {
        return rw;
    } 
}

double parabolicCutoffMjjRW(double mjj, double a, double b, double c, double mjjLimit){
    if (mjj < mjjLimit){
        return parabolicMjjRW(mjj,a,b,c);
    } else {
        return parabolicMjjRW(mjjLimit,a,b,c);
    }
}

double exponentialMjjRW(double mjj, double a, double b, double c){
    return c - b * (1 - exp(-a * mjj));
}

enum class MC
{
    PowHegPythia = 1,
    SHERPA,
    MadGraph,
    SHERPANLO,
    MadGraphNLO,
};

enum class Region
{
    DefaultNoRW,
    SR,
    CRa,
    CRb,
    CRc
};

enum class RWType
{
    Linear = 1,
    Parabolic,
    ParabolicCutoff,
    Exponential,
    ParabolicCutoffEWjjPoPy
};

typedef std::pair<RWType, std::vector<double>> RWParameters;
typedef std::map<Region, RWParameters> RegionRWParametersMap;

double mjj_rw(double mjj, const RWParameters& rwParameters) {
    RWType rwType = rwParameters.first;
    const std::vector<double>& params = rwParameters.second;

    switch (rwType) {
        case RWType::Linear:
            g_LOG(LogLevel::DEBUG, "Applying linear reweighting.");
            return linearMjjRW(mjj, params[0], params[1]);
        case RWType::Parabolic:
            g_LOG(LogLevel::DEBUG, "Applying parabolic reweighting.");
            return parabolicMjjRW(mjj, params[0], params[1], params[2]);
        case RWType::ParabolicCutoff:
            g_LOG(LogLevel::DEBUG, "Applying parabolic cutoff reweighting.");
            return parabolicCutoffMjjRW(mjj, params[0], params[1], params[2], params[3]);
        case RWType::Exponential:
            g_LOG(LogLevel::DEBUG, "Applying exponential reweighting.");
            return exponentialMjjRW(mjj, params[0], params[1], params[2]);
        default:
            g_LOG(LogLevel::ERROR, "Invalid RWType provided for mjj_rw function.");
            throw std::runtime_error("Invalid RWType provided for mjj_rw function.");
    }
}





RegionRWParametersMap g_dataDrivenParametersSHERPA = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // Because for the SR, the parabolic cutoff / and exponential functions look ok.
    // We also have the parabolic-only model to study the differences.
    // The parabolic models come from the CRs using parabolic functions WITH cutoff.
    
    // SR
    //{Region::SR,{RWType::Exponential,{8.47307103E-04,1.06314779,1.54110821}}},
    {Region::SR,{RWType::ParabolicCutoff,{8.82838944E-08,-5.75209880E-04,1.43649628,2750.0}}},
    //{Region::SR,{RWType::Parabolic,{8.82838944E-08,-5.75209880E-04,1.43649628}}},
    
    // Why we have this config?
    // Because for the CRs, the parabolic cutoff / and exponential functions look ok.

    // CRa 
    //{Region::CRa,{RWType::Exponential,{5.33258433E-04, 9.82852263E-01, 1.28814778}}},
    {Region::CRa,{RWType::ParabolicCutoff,{5.12425324E-08, -4.08751381E-04, 1.24756826, 2750.0}}},

    // CRb
    //{Region::CRb,{RWType::Exponential,{4.01028249E-04, 1.09084194, 1.11885231}}},
    {Region::CRb,{RWType::ParabolicCutoff,{4.40873552E-08, -3.83261855E-04,  1.10073847, 2750.0}}},
    
    // CRc
    //{Region::CRc,{RWType::Exponential,{6.77111407E-04, 1.06577307, 1.32799518}}},
    {Region::CRc,{RWType::ParabolicCutoff,{9.49859209E-08, -5.73086485E-04,  1.28561923, 2750.0}}}
};

RegionRWParametersMap  g_dataDrivenParametersMadGraph = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},
    
    // Why we have this config?
    // Because for the SR, the parabolic cutoff / and exponential functions look ok.
    // We also have the parabolic-only model to study the differences.
    // The parabolic models come from the CRs using parabolic functions WITH cutoff.

    // SR
    //{Region::SR,{RWType::Exponential,{7.42436292e-04, 7.03633110e-01, 9.64192819e-01}}},
    {Region::SR,{RWType::ParabolicCutoff,{6.54900406e-08,-3.82604146e-04, 9.17664656e-01, 2250.0}}},
    //{Region::SR,{RWType::Parabolic,{6.54900406e-08,-3.82604146e-04, 9.17664656e-01}}},
    
    // Why we have this config?
    // Because for the CRs, the parabolic cutoff / and exponential functions look ok.

    // CRa
    //{Region::CRa,{RWType::Exponential,{0.00204818, 0.63854209, 1.27767397}}},
    {Region::CRa,{RWType::ParabolicCutoff,{1.47363059e-07, -5.30451714e-04, 1.10250952, 2250.0}}},

    // CRb
    //{Region::CRb,{RWType::Exponential,{0.0022636, 0.53336548, 1.22186023}}},
    {Region::CRb,{RWType::ParabolicCutoff,{6.90430166e-08, -3.25760628e-04,  1.01069816, 2250.0}}},

    // CRc
    //{Region::CRc,{RWType::Exponential,{6.06953737e-04, 6.55012117e-01, 9.11280336e-01}}},
    {Region::CRc,{RWType::ParabolicCutoff,{6.36300429e-08, -3.52804325e-04, 9.01219872e-01, 2250.0}}}
};

RegionRWParametersMap  g_dataDrivenParametersSHERPANLO = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},
    
    // Why we have this config?
    // Because for the SR, the parabolic cutoff / and exponential functions look ok.
    // The parabolic model comes from the CRs using parabolic functions WITH cutoff.

    // SR
    //{Region::SR,{RWType::Exponential,{8.96860907e-04, 6.93896459e-01, 1.25625295}}},
    {Region::SR,{RWType::ParabolicCutoff,{5.94966044e-08,-3.76772401e-04, 1.17521036, 2250.0}}},

    // Why we have this config?
    // Because for the CRs, the parabolic cutoff / and exponential functions look ok.

    // CRa
    //{Region::CRa,{RWType::Exponential,{0.00156031, 0.3799225, 1.29891011}}},
    {Region::CRa,{RWType::ParabolicCutoff,{5.71656859e-08,-2.62872334e-04, 1.21131425, 2250.0}}},

    // CRb
    //{Region::CRb,{RWType::Exponential,{3.19256821e-04, 5.54926740e-01, 1.07918955}}},
    {Region::CRb,{RWType::ParabolicCutoff,{1.77317786e-08,-1.65599550e-04, 1.07576462, 2250.0}}},

    // CRc
    //{Region::CRc,{RWType::Exponential,{4.36532955e-04, 8.28953792e-01, 1.07790403}}},
    {Region::CRc,{RWType::ParabolicCutoff,{4.64652042e-08, -3.32330381e-04,  1.07040864, 2250.0}}},
};

RegionRWParametersMap  g_dataDrivenParametersMadGraphNLO = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},
    
    // Why we have this config?
    // Because for the SR, the parabolic cutoff is the only that looks ok.
    // The parabolic model comes from the CRs using parabolic functions WITH cutoff.

    // SR
    {Region::SR,{RWType::ParabolicCutoff,{1.87328269e-08, -1.24610255e-05,  1.09966978, 2250.0}}},

    // Why we have this config?
    // Because for the CRs, the parabolic cutoff is the only that looks ok.

    // CRa
    {Region::CRa,{RWType::ParabolicCutoff,{1.64160212e-07, -2.52862888e-04,  9.72491990e-01, 2250.0}}},

    // CRb
    {Region::CRb,{RWType::ParabolicCutoff,{-2.78717423e-08,  8.63662484e-05,  7.97095128e-01, 2250.0}}},

    // CRc
    {Region::CRc,{RWType::ParabolicCutoff,{-8.92091182e-08,  1.75520985e-04,  9.65630866e-01, 2250.0}}}
};

RegionRWParametersMap  g_dataDrivenParametersPowHegPythia = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // Because no RW can recover this sample.

    {Region::SR,{RWType::Linear,{0.0,1.0}}},
    {Region::CRa,{RWType::Linear,{0.0,1.0}}},
    {Region::CRb,{RWType::Linear,{0.0,1.0}}},
    {Region::CRc,{RWType::Linear,{0.0,1.0}}}
};

RegionRWParametersMap  g_mcDrivenParametersSHERPA = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // We only apply the MC QCDjj closure RW to the SR

    {Region::SR,{RWType::Linear,{1.32414517e-04, 9.15044268e-01}}},
};

RegionRWParametersMap  g_mcDrivenParametersSHERPANLO = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // We only apply the MC QCDjj closure RW to the SR

    {Region::SR,{RWType::Linear,{3.63250659e-05, 9.74936749e-01}}},
};

RegionRWParametersMap  g_mcDrivenParametersMadGraph = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // We only apply the MC QCDjj closure RW to the SR

    {Region::SR,{RWType::Linear,{4.21819894e-05 , 9.60973106e-01}}},
};

RegionRWParametersMap  g_mcDrivenParametersMadGraphNLO = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // We only apply the MC QCDjj closure RW to the SR

    {Region::SR,{RWType::Linear,{2.52428835e-04, 8.42915241e-01}}},
};

RegionRWParametersMap  g_mcDrivenParametersPowHegPythia = {
    {Region::DefaultNoRW,{RWType::Linear,{0.0,1.0}}},
    {Region::SR,{RWType::Linear,{0.0,1.0}}},

    // Why we have this config?
    // We do not apply the MC QCDjj closure RW to this sample.

    
};

double calculateMjjWeight(bool doDataDrivenRW, bool doMCDrivenRW, double mjj, Region region, int sample_id) {
    double mjj_w = 1.0;

    // If no reweighting is requested, return the original mjj value
    if (!doDataDrivenRW && !doMCDrivenRW) {
        g_LOG(LogLevel::DEBUG, "No reweighting applied.");
        return mjj_w;
    }

    // Convert sample_id to MC enum
    MC mcSample = static_cast<MC>(sample_id);

    // Do the data-driven reweighting if requested
    if (doDataDrivenRW) {
        g_LOG(LogLevel::DEBUG, "Applying data-driven reweighting.");
        if(mcSample == MC::PowHegPythia){
            mjj_w = mjj_rw(mjj,g_dataDrivenParametersPowHegPythia[region]);
        } else if (mcSample == MC::SHERPA){
            mjj_w = mjj_rw(mjj,g_dataDrivenParametersSHERPA[region]); 
        } else if (mcSample == MC::MadGraph){ 
            mjj_w = mjj_rw(mjj,g_dataDrivenParametersMadGraph[region]);
        } else if (mcSample == MC::SHERPANLO){ 
            mjj_w = mjj_rw(mjj,g_dataDrivenParametersSHERPANLO[region]);
        } else if (mcSample == MC::MadGraphNLO){ 
            mjj_w = mjj_rw(mjj,g_dataDrivenParametersMadGraphNLO[region]);
        } else {
            g_LOG(LogLevel::ERROR, "Invalid MC sample for data-driven reweighting.");
            throw std::runtime_error("Invalid MC sample for data-driven reweighting.");
        }
    }

    // Do the MC-driven reweighting if requested
    if (doMCDrivenRW) {
        g_LOG(LogLevel::DEBUG, "Applying MC-driven reweighting.");
        if (region != Region::SR) return mjj_w; // No MC-driven reweighting for CRs

        // Multiply the previous weight by the MC-driven reweighting factor
        if(mcSample == MC::SHERPA){
            mjj_w *= mjj_rw(mjj,g_mcDrivenParametersSHERPA[Region::SR]);
        } else if (mcSample == MC::SHERPANLO){
            mjj_w *= mjj_rw(mjj,g_mcDrivenParametersSHERPANLO[Region::SR]);
        } else if (mcSample == MC::MadGraph){
            mjj_w *= mjj_rw(mjj,g_mcDrivenParametersMadGraph[Region::SR]);
        } else if (mcSample == MC::MadGraphNLO){
            mjj_w *= mjj_rw(mjj,g_mcDrivenParametersMadGraphNLO[Region::SR]);
        } else if (mcSample == MC::PowHegPythia){
            mjj_w *= mjj_rw(mjj,g_mcDrivenParametersPowHegPythia[Region::SR]);
        } else {
            g_LOG(LogLevel::ERROR, "Invalid MC sample for MC-driven reweighting.");
            throw std::runtime_error("Invalid MC sample for MC-driven reweighting.");
        }
    }
    
    g_LOG(LogLevel::DEBUG, "Final mjj weight = ", mjj_w);
    return mjj_w;
}

#endif