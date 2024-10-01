#include "psoheader.h"
namespace MyRand
{
    std::mt19937 gen(time(nullptr));
}
int give_rn(int l,int u)
{
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double r = dis(MyRand::gen);
    r=l+(u-l+1)*r;
    return((int)r);
    
}
double give_rn(double l,double u)
{
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double r = dis(MyRand::gen);
    r=l+(u-l)*r;
    return(r);
}
