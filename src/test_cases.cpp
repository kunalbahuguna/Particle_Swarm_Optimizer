#include "psoheader.h"
void update_fval(vector <Particle> &swarm)
{
    int i,j;
    vector <double> ans;
    for(i=0;i<N;i++)
    {
        ans=tc_func(swarm[i].pos);
        swarm[i].fval=ans[0];
        for(j=0;j<ans.size()-1;j++)
        {
            if(j+1<=N_iec)
                swarm[i].voilation[j]=ans[j+1]>con_tol?ans[j+1]:0;
            else
                swarm[i].voilation[j]=fabs(ans[j+1])>con_tol?fabs(ans[j+1]):0;
        }
        ans.clear();
    }
}
//Test Cases From->"Test Examples for Nonlinear Programming Codes" Willi Hock and Klaus Schittkowski 
// And https://en.wikipedia.org/wiki/Test_functions_for_optimization page
vector<double> spherical(vector <double> X) //Spherical Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0); //This vector containing function value and constraints
    for (int j=0;j<D;j++)
        f[0]=f[0]+X[j]*X[j]; //First element must be function value
    //First Add in-equality constraints f[j]<0 (N_iec)
    //Then add subsequent equality constraints f[j]=0 (N_eq)
    return(f);
}
vector<double> rastrigrin(vector <double> X) //Rastrigrin Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    for (int j=0;j<D;j++)
        f[0]=f[0]+pow(X[j],2)-D*10*cos(2.0*M_PI*X[j])+D*10.0; 
    return(f);
}
vector<double> rosenbrock(vector <double> X) //Rosenbrock Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    for (int j=0;j<D-1;j++)
        f[0]=f[0]+100.0*pow(X[j+1]-pow(X[j],2),2)+pow(1.0-X[j],2);
    return(f);
}
vector<double> ackley(vector <double> X) //Ackley Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=-20.0*exp(-0.2*sqrt(0.5*(pow(X[0],2)+pow(X[1],2))))-exp(0.5*(cos(2.0*M_PI*X[0])+cos(2.0*M_PI*X[1])))+exp(1)+20.0;
    return(f);
}
vector<double> goldstein(vector <double> X) //Goldstein Price Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=(1.0+pow((X[0]+X[1]+1.0),2)*(19.0-14.0*X[0]+3.0*pow(X[0],2)-14.0*X[1]+6.0*X[0]*X[1]+3.0*pow(X[1],2)))*(30.0+pow((2.0*X[0]-3.0*X[1]),2)*(18.0-32.0*X[0]+12.0*pow(X[0],2)+48.0*X[1]-36.0*X[0]*X[1]+27.0*pow(X[1],2)));
    return(f);
}
vector<double> beale(vector <double> X) //Beale Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=pow((1.5-X[0]+X[0]*X[1]),2)+pow((2.25-X[0]+X[0]*pow(X[1],2)),2)+pow((2.625-X[0]+X[0]*pow(X[1],3)),2);
    return(f);
}
vector<double> booth(vector <double> X) //Booth Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=pow((X[0]+2*X[1]-7),2)+pow((2*X[0]+X[1]-5),2);
    return(f);
}
vector<double> matyas(vector <double> X) //Matyas Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=0.26*(X[0]*X[0]+X[1]*X[1])-0.48*X[0]*X[1];
    return(f);
}
vector<double> himmelblau_mm(vector <double> X) //Himmelblau's Multi Modal Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=pow((X[0]*X[0]+X[1]-11),2)+pow((X[0]+X[1]*X[1]-7),2);
    return(f);
}
vector<double> rosenbrock2(vector <double> X) //Rosenbrock's 2 Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=100*pow((X[1]-pow(X[0],2)),2)+pow((1-X[0]),2);
    f[1]=pow(X[0]-1,3)-X[1]+1.0;
    f[2]=X[0]+X[1]-2.0;
    return(f);
}
vector<double> colville4(vector <double> X) //Colville No.4 Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=100*pow(X[1]-pow(X[0],2),2)+pow(1-X[0],2)+90*pow(X[3]-pow(X[2],2),2)+pow(1-X[2],2)+10.1*(pow(X[1]-1,2)+pow(X[3]-1,2))+19.8*(X[1]-1)*(X[3]-1);
    return(f);
}
vector<double> colville6(vector <double> X) //Colville No 6 (C) //Not Working
{
    double f1=0,f2=0;
    vector <double> f(1+N_ec+N_iec,0);
    if(X[0]<300) 
        f1=30.0*X[0];
    else
        f1=31.0*X[0];
    if(X[1]<100)
        f2=28.0*X[1];
    else if(X[1]<200)
        f2=29.0*X[1];
    else
        f2=30.0*X[1];
    f[0]=f1+f2;
    f[1]=300.0-X[0]-X[2]*X[3]*cos(1.48577-X[5])/131.078+cos(1.47588)*pow(X[2],2)*0.90798/131.078;
    f[2]=-X[1]-X[2]*X[3]*cos(1.48577+X[5])/131.078+cos(1.47588)*pow(X[3],2)*0.90798/131.078;
    f[3]=-X[4]-X[2]*X[3]*sin(1.48577+X[5])/131.078+sin(1.47588)*pow(X[3],2)*0.90798/131.078;
    f[4]=200.0-X[2]*X[3]*sin(1.48577-X[5])/131.078+sin(1.47588)*pow(X[2],2)*0.90798/131.078;
    return(f);
}
vector<double> himmelblau1(vector <double> X) //Himmelblau No 1 Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=pow(X[0]-2.0,2)+pow(X[1]-1,2.0);
    f[1]=.25*X[0]*X[0]+X[1]*X[1]-1.0;
    f[2]=X[0]-2.0*X[1]+1.0;
    return(f);
}
vector<double> himmelblau3(vector <double> X) //Himmelblau No 3 Function(C)
{
    double f1,f2,f3,f4,f5,f6;
    vector <double> f(1+N_ec+N_iec,0);
    f1=-75.196+3.8112*X[0]+0.0020567*pow(X[0],3)-1.0345*pow(10,-5)*pow(X[0],4); 
    f2=6.8306*X[1]-0.030234*X[0]*X[1]+1.28134*pow(10,-3)*X[1]*pow(X[0],2);
    f3=2.266*pow(10,-7)*pow(X[0],4)*X[1]-0.25645*pow(X[1],2)+0.0034604*pow(X[1],3)-1.3514*pow(10,-5)*pow(X[1],4);
    f4=28.106/(X[1]+1.0)+5.2375*pow(10,-6)*pow(X[0],2)*pow(X[1],2)+6.3*pow(10,-8)*pow(X[0],3)*pow(X[1],2);
    f5=-7*pow(10,-10)*pow(X[0],3)*pow(X[1],3)-3.405*pow(10,-4)*X[0]*pow(X[1],2)+1.6638*pow(10,-6)*X[0]*pow(X[1],3);
    f6=2.8673*exp(0.0005*X[0]*X[1])-3.5256*pow(10,-5)*pow(X[0],3)*X[1];
    f[0]=f1+f2+f3+f4+f5+f6;
    f[1]=-X[0]*X[1]+700;
    f[2]=-X[1]+X[0]*X[0]/125.0;
    f[3]=-pow(X[1]-50.0,2)+5.0*(X[0]-55.0);
    return(f);
}
vector<double> himmelblau5(vector <double> X) //Himmelblau No 5 Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=1000.0-pow(X[0],2)-2.0*pow(X[1],2)-pow(X[2],2)-X[0]*X[1]-X[0]*X[2];
    f[1]=8.0*X[0]+14.0*X[1]+7.0*X[2]-56.0;
    f[2]=pow(X[0],2)+pow(X[1],2)+pow(X[2],2)-25;
    return(f);
}
vector<double> himmelblau16(vector <double> X) //Himmelblau No 16 Function(C) (NW)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=-.5*(X[0]*X[3]-X[1]*X[2]+X[2]*X[8]-X[4]*X[8]+X[4]*X[7]-X[5]*X[6]);
    f[1]=-1+pow(X[2],2)+pow(X[3],2);
    f[2]=-1+pow(X[8],2);
    f[3]=-1+pow(X[4],2)+pow(X[5],2);
    f[4]=-1+pow(X[0],2)+pow(X[1]-X[8],2);
    f[5]=-1+pow(X[0]-X[4],2)+pow(X[1]-X[5],2);
    f[6]=-1+pow(X[0]-X[6],2)+pow(X[1]-X[7],2);
    f[7]=-1+pow(X[2]-X[4],2)+pow(X[3]-X[5],2);
    f[8]=-1+pow(X[2]-X[6],2)+pow(X[3]-X[7],2);
    f[9]=-1+pow(X[6],2)+pow(X[7]-X[8],2);
    f[10]=-X[0]*X[3]+X[1]*X[2];
    f[11]=-X[2]*X[8];
    f[12]=X[4]*X[8];
    f[13]=-X[4]*X[7]+X[5]*X[6];
    f[14]=-X[8];
    return(f);
}
vector<double> himmelblau17(vector <double> X) //Himmelblau No 17 Function(UC)
{
    double f1=0,m=1;
    vector <double> f(1+N_ec+N_iec,0);
    for (int j=0;j<D;j++)
    {
        f1=f1+pow(log(X[j]-2),2)+pow(log(10-X[j]),2);
        m=m*pow(X[j],0.2);
    }
    f[0]=f1-m;
    return(f);
}
vector<double> himmelblau21(vector <double> X) //Himmelblau No 21 Function(UC)
{
    vector <double> f(1+N_ec+N_iec,0);
    for (int j=1;j<100;j++)
        f[0]=f[0]+pow(-0.01*j+exp((-1.0/X[0])*pow(25.0+pow(-50.0*log(0.01*j),2.0/3.0)-X[1],X[2])),2.0);
    return(f);
}
vector<double> himmelblau24(vector <double> X) //Himmelblau No 24 Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=pow(X[0]-2,2)+pow(X[1]-1,2);
    f[1]=X[0]+X[1]-2;
    f[2]=pow(X[0],2)-X[1];
    return(f);
}
vector<double> beale2(vector <double> X) //Beale 2 Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=9.0-8.0*X[0]-6.0*X[1]-4.0*X[2]+2.0*pow(X[0],2)+2.0*pow(X[1],2)+pow(X[2],2)+2.0*X[0]*X[1]+2.0*X[0]*X[2];
    f[1]=-3.0+X[0]+X[1]+2.0*X[2];
    return(f);
}
vector<double> rosen_suzuki(vector <double> X) //Rosen-Suzuki Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=pow(X[0],2)+pow(X[1],2)+2.0*pow(X[2],2)+pow(X[3],2)-5.0*X[0]-5.0*X[1]-21.0*X[2]+7.0*X[3];
    f[1]=-8.0+pow(X[0],2)+pow(X[1],2)+pow(X[2],2)+pow(X[3],2)+X[0]-X[1]+X[2]-X[3];
    f[2]=-10.0+pow(X[0],2)+2.0*pow(X[1],2)+pow(X[2],2)+2.0*pow(X[3],2)-X[0]-X[3];
    f[3]=-5.0+2.0*pow(X[0],2)+pow(X[1],2)+pow(X[2],2)+2.0*X[0]-X[1]-X[3];
    return(f);
}
vector<double> cattle_feed(vector <double> X) //Cattle Feed Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=24.55*X[0]+26.75*X[1]+39.0*X[2]+40.50*X[3];
    f[1]=-2.3*X[0]-5.6*X[1]-11.1*X[2]-1.3*X[3]+5;
    f[2]=-12.0*X[0]-11.9*X[1]-41.8*X[2]-52.1*X[3]+21.0+1.645*pow(.28*pow(X[0],2)+.19*pow(X[1],2)+20.5*pow(X[2],2)+.62*pow(X[3],2),0.5);
    f[3]=X[0]+X[1]+X[2]+X[3]-1.0;
    return(f);
}
vector<double> transformer_design(vector <double> X) //Transformer design Function(C)
{
    vector <double> f(1+N_ec+N_iec,0);
    f[0]=0.0204*X[0]*X[3]*(X[0]+X[1]+X[2])+0.0187*X[1]*X[2]*(X[0]+1.57*X[1]+X[3])+0.0607*X[0]*X[3]*X[4]*X[4]*(X[0]+X[1]+X[2])+0.0437*X[1]*X[2]*X[5]*X[5]*(X[0]+1.57*X[1]+X[3]);
    f[1]=-.001*X[0]*X[1]*X[2]*X[3]*X[4]*X[5]+2.07;
    f[2]=-1.0+0.00062*X[0]*X[3]*X[4]*X[4]*(X[0]+X[1]+X[2])+0.00058*X[1]*X[2]*X[5]*X[5]*(X[0]+1.57*X[1]+X[3]);
    return(f);
}