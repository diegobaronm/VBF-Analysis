#ifndef rewightingTools_h
#define rewightingTools_h

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

#endif