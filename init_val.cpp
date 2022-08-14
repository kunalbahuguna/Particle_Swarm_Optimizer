#include "psoheader.h"
void init_val(vector <double> &pos_ulimit, vector <double> &pos_llimit,vector <double> &vel_ulimit, vector <double> &vel_llimit, vector <Particle> &swarm)
{
    int i, j;
    double ul=5,ll=-5;
    //Definie Position limits
    cout<<"Initializing Problem"<<endl;
    switch(prob)
    {
        case 10:
        {
            pos_ulimit={1.5,2.5};
            pos_llimit={-1.5,-0.5};
            //pos_ulimit[0]=1.5;
            //pos_llimit[0]=-1.5;
            //pos_ulimit[1]=2.5;
            //pos_llimit[1]=-0.5;
            break;
        }
        case 12:
        {
            pos_ulimit={400,1000,420,420,300,0.5236};
            pos_llimit={0,0,340,340,100,0};
            //pos_ulimit[0]=400;
            //pos_llimit[0]=0;
            //pos_ulimit[1]=1000;
            //pos_llimit[1]=0;
            //pos_ulimit[2]=420;
            //pos_llimit[2]=340;
            //pos_ulimit[3]=420;
            //pos_llimit[3]=340;
            //pos_ulimit[4]=300;
            //pos_llimit[4]=100;
            //pos_ulimit[5]=0.5236;
            //pos_llimit[5]=0;
            break;
        }
        case 14:
        {
            pos_ulimit={75,65};
            pos_llimit={0,0};
            //pos_ulimit[0]=75;
            //pos_llimit[0]=0;
            //pos_ulimit[1]=65;
            //pos_llimit[1]=0;
            break;
        }
        case 18:
        {
            pos_ulimit={100,25.6,5};
            pos_llimit={0.1,0,0};
            //pos_ulimit[0]=100;
            //pos_llimit[0]=.1;
            //pos_ulimit[1]=25.6;
            //pos_llimit[1]=0;
            //pos_ulimit[2]=5;
            //pos_llimit[2]=0;
            break;
        }
        default:
        {
            cout<<"Taking Default upper/lower Limits"<<endl;
            for (j = 0; j < D; j++)
            {
                pos_ulimit.push_back(ul);
                pos_llimit.push_back(ll);
            }
        }
    }
    //Define velocity limits (only used in inertia weight method) (Problem if both pos limit is negative)
    for (j = 0; j < D; j++)
    {
        vel_ulimit.push_back((pos_ulimit[j]-pos_llimit[j])/2);
        vel_llimit.push_back(-vel_ulimit[j]);
    }
    cout<<"Limits Calculated"<<endl;
    //Cal random populations
    Particle empty;
    empty.ini_Particle(D,N_iec+N_ec);
    for (i = 0; i < N; i++)
        swarm.push_back(empty);
    cout<<pos_llimit.size()<<pos_ulimit.size()<<swarm.size()<<endl;
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
}
