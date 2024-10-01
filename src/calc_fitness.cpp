// From ->"Particle Swarm Optimization Method for Constrained Optimization Problems" by Konstantinos E. Parsopoulos and Michael N. Vrahatis
#include "psoheader.h"
void calc_fitness(int k,vector <Particle> &swarm)
{
    int gamma=1,i=0,j=0;
    double theta=0,c,penalty[N_ec+N_iec],total_penalty[N];
    if(k==0)
        k=1;
    c=1.0*pow(k,alpha);
    //Calculating Voilations and Updating is_feasible
    update_fval(swarm);
    if(N_ec+N_iec>0) //Constrained Problem
    {
        for(i=0;i<N;i++)
        {
            total_penalty[i]=0;
            for(j=0;j<N_ec+N_iec;j++)
            {
                if(swarm[i].voilation[j]>0)
                {
                    if(swarm[i].voilation[j]<1)
                        gamma=1;
                    else
                        gamma=2;
                    if(swarm[i].voilation[j]<0.001)
                        theta=10;
                    else if(swarm[i].voilation[j]<0.1)
                        theta=20;
                    else if(swarm[i].voilation[j]<1)
                        theta=100;
                    else if(swarm[i].voilation[j]<10)
                        theta=300;
                    else if(swarm[i].voilation[j]<100)
                        theta=300;
                    else
                        theta=300;
                    theta=theta*pf;
                    penalty[j]=c*theta*pow(swarm[i].voilation[j],gamma);
                }
                else
                    penalty[j]=0;
                total_penalty[i]=total_penalty[i]+penalty[j];
            }
            if(total_penalty[i]>0)
                swarm[i].is_feasible=false;
            else
                swarm[i].is_feasible=true;
        }   
    }
    for(i=0;i<N;i++)
    {
        if(swarm[i].is_feasible==false)
            swarm[i].fitness=swarm[i].fval+total_penalty[i];
        else
            swarm[i].fitness=swarm[i].fval;
    }
}
