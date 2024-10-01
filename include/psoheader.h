#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <random>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
extern double con_tol,fval_tol;
extern double alpha,pf;
extern int D,N_iec,N_ec,prob; //Must be defined in test cases
extern vector<double> (*tc_func)(vector<double>); //Pointer to test case function
extern int N,rmax,itr; //Variables->>Population of swarm/No of runs of optimizer/Max iteration of optimizer
extern char method; //'w'-Inertial Weight Factor. 'c'-Velocity Constriction. 'f'-FDR/EPSO.
extern vector <double> pos_ulimit,pos_llimit,vel_ulimit,vel_llimit;
class Particle
{
public:
    vector <double> pos;
    vector <double> pbest_pos;
    double fval;
    double grad;
    double fitness;
    double pbest_fitness;
    vector <double> vel;
    vector <double> voilation;
    bool is_feasible;
public:
    void ini_Particle(int D,int N_c)
    {
    	for(int i=0;i<D;i++)
    	{
    		pos.push_back(0.0);
    		pbest_pos.push_back(0.0);
    		vel.push_back(0.0);
    	}
    	for(int i=0;i<N_c;i++)
            voilation.push_back(0.0);
    }
};
//Print Utilities
void print(Particle par);
void print(double a[],int n);
void print(int a[],int n);
void print(vector <double> a);
void print(vector <int> a);
void print(bool v);

//Optimizer Definitions
void ini_swarm(vector <Particle> &swarm);
Particle opti_PSO(int r);
void calc_fitness(int k,vector <Particle> &swarm);
void update_fval(vector <Particle> &swarm);
int find_nbest(vector <Particle> &swarm,int k);
//Problems
void ini_prob();
void calc_func(vector <Particle> &swarm);
vector<double> spherical(vector <double> X); //Spherical Function(UC)
vector<double> rastrigrin(vector <double> X); //Rastrigrin Function(UC)
vector<double> rosenbrock(vector <double> X); //Rosenbrock Function(UC)
vector<double> ackley(vector <double> X); //Ackley Function(UC)
vector<double> goldstein(vector <double> X); //Goldstein Price Function(UC)
vector<double> beale(vector <double> X); //Beale Price Function(UC)
vector<double> booth(vector <double> X); //booth Function(UC)
vector<double> matyas(vector <double> X); //Matyas Function(UC)
vector<double> himmelblau_mm(vector <double> X); //Himmelblau's Multi Modal Function(UC)
vector<double> rosenbrock2(vector <double> X); //Rosenbrock's 2 Function(C)
vector<double> colville4(vector <double> X); //Colvile No.4 Function(UC)
vector<double> colville6(vector <double> X); ////Colville No 6 (C) //NW
vector<double> himmelblau1(vector <double> X); //Himmelblau No 1 Function(C)
vector<double> himmelblau3(vector <double> X); //Himmelblau No 3 Function(C)
vector<double> himmelblau5(vector <double> X); //Himmelblau No 5 Function(C)
vector<double> himmelblau16(vector <double> X); //Himmelblau No 16 Function(C)
vector<double> himmelblau17(vector <double> X); //Himmelblau No 17 Function(UC)
vector<double> himmelblau21(vector <double> X); //Himmelblau No 21 Function(UC)
vector<double> himmelblau24(vector <double> X); //Himmelblau No 24 Function(C)
vector<double> beale2(vector <double> X); //Beale 2 Function(C)
vector<double> rosen_suzuki(vector <double> X); //Rosen-Suzuki Function(C)
vector<double> cattle_feed(vector <double> X); //Cattle Feed Function(C)
vector<double> transformer_design(vector <double> X); //Transformer design Function(C)
//Misc Functions
void read_config();
int give_rn(int u,int l);
double give_rn(double u,double l);