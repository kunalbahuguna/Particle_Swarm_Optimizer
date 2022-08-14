#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <random>
#include <vector>
#include <fstream>
using namespace std;
extern int D,N,rmax,itr,N_iec,N_ec,prob,threads; //Variables->>Dimention of problem/Population of swarm/NO of runs of optimizer/Iteration of optimizer/No of inequality constrains
extern char method; //'w'-Weight Factor (Linearly Decreasing) 'c'- Velocity Constriction.
class Particle
{
public:
    vector <double> pos;
    vector <double> pbest_pos;
    double fval;
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
struct run
{
    double best_fval;
    double corr_fitness;
    vector <double> best_pos;
};
//Print Utilities
void print(Particle par);
void print(double a[],int n);
void print(int a[],int n);
void print(vector <double> &a,int n);
void print(vector <int> &a,int n);
void print(bool v);

//Optimizer Definitions
void calc_fitness(int k,vector <Particle> &swarm);
void init_val(vector <double> &pos_ulimit, vector <double> &pos_llimit,vector <double> &vel_ulimit, vector <double> &vel_llimit, vector <Particle> &swarm);
void calc_func(vector <Particle> &swarm);
void solver_call(int ID,int &i);
void calc_voilation(vector <Particle> &swarm);
void opti_PSO(int r,run *data);
//Misc Functions
void read_config();
int give_rn(int u,int l);
double give_rn(double u,double l);
