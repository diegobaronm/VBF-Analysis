#ifndef rewightingTools_h
#define rewightingTools_h
#include <map>
#include "Tools.h"

double zptRWMG(double zpt, const std::string& sampleName ){
    // See if VBF and MG is in the sample name
    bool sampleToRW = false;
    if (sampleName.find("VBF") != std::string::npos){
        if (sampleName.find("VBF") != std::string::npos){
            sampleToRW = true;
        }
    }

    if (!sampleToRW) return 1.0;

    // Else, apply the reweighting
    std::vector<double> sfs = { 2.6892858496768355, 2.5110055821523187, 2.3579781297076474, 2.102817516092733, 1.7975550694375322, 1.4859461348139757, 1.1611097400329733, 0.9253160384871805, 0.7370261218516009, 0.6092242119586373, 0.49487504013046574, 0.4098352550419078, 0.34238442118492507, 0.2895616517266261, 0.252852264018192, 0.2168629149309584, 0.18680387308910681, 0.16680337931719608, 0.14246137755941474, 0.1283104071837852, 0.11359030939605967, 0.09979920731765932, 0.08947236971791837, 0.0780999077541964, 0.07230161952853108, 0.06424762235160135, 0.05853347894655636, 0.05418268259919957, 0.047209709917021385, 0.042867258084297456, 0.03832888382536718, 0.03591492892339334, 0.03400879163277656, 0.03033538991501962, 0.02807092689184602, 0.02546697732265072, 0.023966605612821344, 0.02250855348902585, 0.020375537167882412, 0.020235507640728963, 0.01668645662701418, 0.01756175730120895, 0.02090663583754546, 0.02425033617294942, 0.025773581547993887, 0.025714567942700176, 0.031412333976053704, 0.029774146317694858, 0.03316970377062058, 0.03021382170774757, 0.03722725512117241, 0.03694147984769024, 0.033477351603118474 };

    if ( zpt > 1000) return sfs.at(sfs.size()-1);
    if ( zpt > 400 ) {
        return sfs.at( 40 + static_cast<int>((zpt-400)/50) );
    } else {
        return sfs.at( static_cast<int>(zpt/10) );
    }
    return 1.0;
}

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

double mjj_rw_quadratic(double mjj, double a, double b, double c){
    double rw = a*mjj*mjj+b*mjj+c;
    if (rw<0){
        return 0.0;
    } else {
        return rw;
    }
}

double mjj_rw_linear(double mjj, double slope, double level){
    double rw = slope*mjj+level;
    if (rw<0){
        return 0.0;
    } else {
        return rw;
    } 
}

double mjj_rw_quadratic_and_constant(double mjj, double a, double b, double c, double mjjLimit, double constant){
    if (mjj < mjjLimit){
        return mjj_rw_quadratic(mjj,a,b,c);
    } else {
        return constant;
    }
}

double mjj_rw(double mjj, const std::vector<double>& parameters){
    size_t numberOfParameters = parameters.size();
    if (numberOfParameters == 3) {return mjj_rw_quadratic(mjj, parameters[0],parameters[1],parameters[2]);}
    else if (numberOfParameters == 5) {
        return mjj_rw_quadratic_and_constant(mjj, parameters[0],parameters[1],parameters[2],parameters[3],parameters[4]);
    }
    else {
        g_LOG(LogLevel::ERROR, "Wrong number of parameters for mjj_rw function.");
        return 1.0;
    }
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

std::map<Region,std::vector<double>> parametersSHERPA = {
    {Region::DefaultNoRW,{0.0,0.0,1.0}},
    //{Region::SR,{1.40E-07,-7.16E-04,1.51E+00}}, // Default
    {Region::SR,{1.40E-07,-7.16E-04,1.51E+00,2750.0,0.586}}, // Flat tail using Sherpa for EWjj
    //{Region::SR,{1.26E-07,-6.95E-04,1.50E+00,2750.0,0.538}}, // Flat tail using PoPy for EWjj
    {Region::CRa,{5.61E-08,-4.20E-04,1.25E+00}},
    {Region::CRb,{4.12E-08,-3.64E-04,1.08E+00}},
    {Region::CRc,{1.09E-07,-6.10E-04,1.30E+00}}
};

std::map<Region,std::vector<double>> parametersMadGraph = {
    {Region::DefaultNoRW,{0.0,0.0,1.0}},
    //{Region::SR,{1.30E-07,-5.29E-04,9.82E-01}}, // Default
    {Region::SR,{1.30E-07,-5.29E-04,9.82E-01,2750.0,0.503}}, // Flat tail using Sherpa for EWjj
    //{Region::SR,{1.23E-07,-5.24E-04,9.85E-01,2750.0,0.465}}, // Flat tail using PoPy for EWjj
    {Region::CRa,{1.53E-07,-5.42E-04,1.10E+00}},
    {Region::CRb,{6.24E-08,-2.97E-04,9.72E-01}},
    {Region::CRc,{5.95E-08,-3.32E-04,8.78E-01}}
};

std::map<Region,std::vector<double>> parametersSHERPANLO = {
    {Region::DefaultNoRW,{0.0,0.0,1.0}},
    {Region::SR,{9.15E-08,-4.62E-04,1.21E+00}},
    {Region::CRa,{5.81E-08,-2.63E-04,1.21E+00,2750.0,0.827}},
    {Region::CRb,{1.11E-08,-1.41E-04,1.05E+00}},
    {Region::CRc,{4.96E-08,-3.38E-04,1.07E+00}}
};

std::map<Region,std::vector<double>> parametersMadGraphNLO = {
    {Region::DefaultNoRW,{0.0,0.0,1.0}},
    {Region::SR,{1.31E-07,-2.44E-04,1.19E+00,2250.0,1.317}},
    {Region::CRa,{1.69E-07,-2.58E-04,9.68E-01,2750.0,1.34}},
    {Region::CRb,{-3.62E-08,1.19E-04,7.73E-01,2250.0,0.882}},
    {Region::CRc,{-8.28E-08,1.61E-04,9.65E-01,2250.0,0.947}}
};

std::map<Region,std::vector<double>> parametersPowHegPythia = {
    {Region::DefaultNoRW,{0.0,0.0,1.0}},
    {Region::SR,{1.18E-08,-1.19E-04,1.21E+00,2750.0,0.970}},
    {Region::CRa,{-8.97E-08,2.26E-04,2.19E+00,2750.0,2.200}},
    {Region::CRb,{-2.06E-07,5.32E-04,2.41E+00,2750.0,2.400}},
    {Region::CRc,{-3.79E-08,-2.00E-06,1.35E+00,2250.0,1.000}}
};

#endif