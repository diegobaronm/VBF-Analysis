#ifndef rewightingTools_h
#define rewightingTools_h
#include <map>

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
        std::cout << "ERROR: Wrong number of parameters for mjj_rw" << std::endl;
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
    //{Region::SR,{1.40E-07,-7.16E-04,1.51E+00,2750.0,0.586}}, // Flat tail using Sherpa for EWjj
    {Region::SR,{1.26E-07,-6.95E-04,1.50E+00,2750.0,0.538}}, // Flat tail using PoPy for EWjj
    {Region::CRa,{5.61E-08,-4.20E-04,1.25E+00}},
    {Region::CRb,{4.12E-08,-3.64E-04,1.08E+00}},
    {Region::CRc,{1.09E-07,-6.10E-04,1.30E+00}}
};

std::map<Region,std::vector<double>> parametersMadGraph = {
    {Region::DefaultNoRW,{0.0,0.0,1.0}},
    //{Region::SR,{1.30E-07,-5.29E-04,9.82E-01}}, // Default
    //{Region::SR,{1.30E-07,-5.29E-04,9.82E-01,2750.0,0.503}}, // Flat tail using Sherpa for EWjj
    {Region::SR,{1.23E-07,-5.24E-04,9.85E-01,2750.0,0.465}}, // Flat tail using PoPy for EWjj
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
    {Region::SR,{1.26E-07,-2.35E-04,1.19E+00,2750.0,1.453}},
    {Region::CRa,{1.69E-07,-2.58E-04,9.68E-01}},
    {Region::CRb,{-3.62E-08,1.19E-04,7.73E-01}},
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