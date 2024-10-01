#include "psoheader.h"
void ini_swarm(vector <Particle> &swarm)
{
    int i, j;
    cout<<"Initializing Problem"<<endl;
    //Cal random populations
    Particle empty;
    empty.ini_Particle(D,N_iec+N_ec);
    for (i = 0; i < N; i++)
        swarm.push_back(empty);
    //cout<<pos_llimit.size()<<pos_ulimit.size()<<swarm.size()<<endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < D; j++)
        {
            swarm[i].pos[j] = give_rn(pos_llimit[j],pos_ulimit[j]);
            swarm[i].pbest_pos[j] = swarm[i].pos[j];
            swarm[i].vel[j]=give_rn(vel_llimit[j],vel_ulimit[j]);
        }
    }
    cout<<"Population Initialized"<<endl;
    calc_fitness(0,swarm);
    for(i=0;i<N;i++)
        swarm[i].pbest_fitness=swarm[i].fitness;
    if(N_ec+N_iec==0)
        swarm[i].is_feasible=true;
}
