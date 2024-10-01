#include "psoheader.h"
double con_tol=pow(10,-8),fval_tol=pow(10,-8);
double alpha=1.5,pf=1;
int D,N,rmax,itr,N_iec,N_ec,prob,threads;
vector<double> (*tc_func)(vector<double>);
char method;
vector <double> pos_ulimit,pos_llimit,vel_ulimit,vel_llimit;
int main()
{
    int r,j,best_run=0;
    read_config();
    Particle best_overall;
    vector <Particle> best_p;
    double sum=0,avg_fval=0;
    ini_prob();
    for(r=0;r<rmax;r++)
    {
        cout<<"STARTING RUN="<<r+1<<endl;
        best_p.push_back(opti_PSO(r));
        //cout<<"Run Complete->"<<endl;
        cout<<"Run Best-> Function Value="<<best_p[r].fval<<"\tFitness="<<best_p[r].fitness<<"\t";
        for (j = 0; j < D; j++)
            cout<<best_p[r].pos[j]<<" ";
        cout<<"\tFeasibility="<<best_p[r].is_feasible<<"\t";
        for (j = 0; j < N_iec+N_ec; j++)
            cout<<best_p[r].voilation[j]<<" ";
        sum=sum+best_p[r].fval;
        cout<<"\n_________________________________________\n";
    }
    cout<<"Optimizer Ends"<<endl;
    best_overall=best_p[0];
    for(r=0;r<rmax;r++)
    {
        if(best_p[r].fval<best_overall.fval)
        {
            best_overall=best_p[r];
            best_run=r;
        }
    }
    cout<<"Final Best-> Function Value="<<best_overall.fval<<"\tFitness="<<best_overall.fitness<<"\t";
    for (j = 0; j < D; j++)
        cout<<best_overall.pos[j]<<" ";
    if(N_ec+N_iec>0)
    {
        cout<<"\tFeasibility="<<best_overall.is_feasible<<"\t";
        for (j = 0; j < N_iec+N_ec; j++)
            cout<<best_overall.voilation[j]<<" ";
    }
    avg_fval=sum/rmax;
    cout<<"\nAverage Function Value="<<avg_fval<<"\n";
    return 0;
}
