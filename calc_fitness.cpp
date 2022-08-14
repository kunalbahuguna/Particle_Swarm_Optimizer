#include "psoheader.h"
void calc_fitness(int k,vector <Particle> &swarm)
{
    double pf=10; //Defin penalty factor
    double c,penalty[N_ec+N_iec],total_penalty[N];
    int theta=0,gamma=0,i=0,j=0;
    if(k==0)
        k=1;
    c=1*pow(k,1);
    //Calculating Voilations and Updating is_feasible
    if(N_ec!=0||N_iec!=0) //Constrained Problem
    {
        calc_voilation(swarm);
        for(i=0;i<N;i++)
        {
                for(j=0;j<N_ec+N_iec;j++)
                {
                    if(swarm[i].voilation[j]>0)
                    {
                        if(swarm[i].voilation[j]<1)
                            gamma=1;
                        else
                            gamma=2;
                        if(swarm[i].voilation[j]<0.001)
                            theta=.5;
                        else if(swarm[i].voilation[j]<0.1)
                            theta=1;
                        else if(swarm[i].voilation[j]<1)
                            theta=2;
                        else if(swarm[i].voilation[j]<10)
                            theta=10;
                        else if(swarm[i].voilation[j]<100)
                            theta=20;
                        else
                            theta=50;
                        theta=theta*pf;
                        penalty[j]=c*theta*pow(swarm[i].voilation[j],gamma);
                    }
                    else
                        penalty[j]=0;
                }
                total_penalty[i]=0;
                for(j=0;j<N_ec+N_iec;j++)
                    total_penalty[i]=total_penalty[i]+penalty[j];
                if(total_penalty[i]>0)
                    swarm[i].is_feasible=false;
                else
                    swarm[i].is_feasible=true;
        }
    }
    else //Unconstrained problem
    {
        for(i=0;i<N;i++)
                swarm[i].is_feasible=true;
    }
    calc_func(swarm);
    for(i=0;i<N;i++)
    {
        if(swarm[i].is_feasible==false)
            swarm[i].fitness=swarm[i].fval+total_penalty[i];
        else
            swarm[i].fitness=swarm[i].fval;
    }
}
