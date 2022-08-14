#include "psoheader.h"
void opti_PSO(int r,run *data)
{
    int i=0,j=0,k=1;
    float r1, r2, a1=0, a2=2.05, a3=2.05,v=1,w=0,b2=2,b3=2;
    string s;
    s=to_string(r);
    a1=2*v/(abs(2-(a2+a3)-sqrt((a2+a3)*(a2+a3)-4*(a2+a3))));
    vector <double>  pos_ulimit, pos_llimit, vel_ulimit, vel_llimit;
    vector <Particle> swarm;
    double gbest_pos[itr][D],gbest_fval[itr],gbest_fitness[itr];
    double gbest_pos_overall[D],gbest_fval_overall,gbest_fitness_overall;
    //Initializing first population and X,Vel limits
    init_val(pos_ulimit, pos_llimit,vel_ulimit, vel_llimit, swarm);
    cout<<"Initial Population Generated"<<endl;
    //Initializing gbest and overall_gbest with valure of first particle
    gbest_fitness[0]=swarm[0].fitness;
    gbest_fval[0]=swarm[0].fval;
    gbest_fitness_overall=swarm[0].fitness;
    gbest_fval_overall=swarm[0].fval;
    for(j = 0; j < D; j++)
    { 
        gbest_pos[0][j]=swarm[0].pos[j];
        gbest_pos_overall[j]=swarm[0].pos[j];
    }
    //Finding 1st gbest value and also taking it as gbest _overall
    for (i = 0; i < N; i++)
    {
        if(swarm[i].fitness<gbest_fitness[0])
        {
            gbest_fitness[0]=swarm[i].fitness;
            gbest_fval[0]=swarm[i].fval;
            gbest_fitness_overall=swarm[i].fitness;
            gbest_fval_overall=swarm[i].fval;
            for (j = 0; j < D; j++)
            {
                gbest_pos[0][j]=swarm[i].pos[j];
                gbest_pos_overall[j]=swarm[i].pos[j];
            }
        }
    }
    /*
    cout<<"Printing Starting population->"<<endl;
    for(i=0;i<N;i++)
        print(swarm[i]);
    */
    ofstream run_data("data/run_data"+s+".txt",ios::trunc);
    if(run_data.is_open()==false)
        cout<<"Err opening file"<<endl;
    run_data<<"itr\tx0\tx1\tgfval\tgfit\tlfval\tlfit\n";
    run_data<<0<<"\t";
    for(j=0;j<D;j++)
        run_data<<gbest_pos_overall[j]<<"\t";
    run_data<<gbest_fval_overall<<"\t"<<gbest_fitness_overall<<"\t"<<gbest_fval[0]<<"\t"<<gbest_fitness[0]<<endl;
    //Starting optimiser
    while (k < itr)
    {
        cout<<"Starting iteration no="<<k<<endl;        
        //Calculating Velocities
        w = 0.9 - 0.5 * ((float)k / (float)itr); //inertia weight factor
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < D; j++)
            {
                r1 = give_rn(0.0,1.0);
                r2 = give_rn(0.0,1.0);
                if(method=='c')
                {
                    swarm[i].vel[j] = a1 * (swarm[i].vel[j] + a2 * r1 * (swarm[i].pbest_pos[j] - swarm[i].pos[j]) + a3 * r2 * (gbest_pos_overall[j] - swarm[i].pos[j]));
                }
                else if(method=='w')
                {
                    swarm[i].vel[j]=w*swarm[i].vel[j]+b2*r1*(swarm[i].pbest_pos[j]-swarm[i].pos[j])+b3*r2*(gbest_pos_overall[j]-swarm[i].pos[j]);
                    if(swarm[i].vel[j]>vel_ulimit[j])
                        swarm[i].vel[j]=vel_ulimit[j];
                    if(swarm[i].vel[j]<vel_llimit[j])
                        swarm[i].vel[j]=vel_llimit[j];
                }
                else
                {
                    printf("err in method");
                    exit(0);
                }
            }
        }
        //Updating new position
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < D; j++)
            {
                swarm[i].pos[j] = swarm[i].pos[j] + swarm[i].vel[j];
                //position constraints
                if (swarm[i].pos[j] > pos_ulimit[j])
                    swarm[i].pos[j] = pos_ulimit[j];
                if (swarm[i].pos[j] < pos_llimit[j])
                    swarm[i].pos[j] = pos_llimit[j];
            }
        }
        calc_fitness(k,swarm); //New fitness claculated
        
        //Updating pbest
        for (i = 0; i < N; i++)
        {
            if (swarm[i].fitness < swarm[i].pbest_fitness)
            {
                swarm[i].pbest_fitness = swarm[i].fitness;
                for (j = 0; j < D; j++)
                    swarm[i].pbest_pos[j] = swarm[i].pos[j];
            }
        }
        //Updating gbest values for current population
        gbest_fitness[k]=swarm[0].fitness;
        gbest_fval[k]=swarm[0].fval;
        for(j = 0; j < D; j++)
            gbest_pos[k][j]=swarm[0].pos[j];
        for (i = 1; i < N; i++)
        {
            if (swarm[i].fitness < gbest_fitness[k])
            {
                gbest_fitness[k] = swarm[i].fitness;
                gbest_fval[k]=swarm[i].fval;
                for (j = 0; j < D; j++)
                    gbest_pos[k][j] = swarm[i].pos[j];
            }
        }
        //Updating overall_gbest values
        for (i = 1; i < N; i++)
        {
            if (gbest_fitness[k] <gbest_fitness_overall )
            {
                gbest_fitness_overall =gbest_fitness[k];
                gbest_fval_overall=gbest_fval[k];
                for (j = 0; j < D; j++)
                    gbest_pos_overall[j] =gbest_pos[k][j];
            }
        }
        cout<<"\nITERATION ENDED\n";
        /*
        cout<<"Current Population->"<<endl;
        for (i = 0; i < N; i++)
        {
            cout<<"Printing Population No="<<i<<endl;
            print(pop[i]);
        }
        */
        cout<<"Current gbest values->"<<endl;
        cout<<"Fitness="<<gbest_fitness_overall<<"\n";
        cout<<"Position->"<<endl;
        print(gbest_pos_overall,D);
        cout<<"Writing data to file for current run->run_data"<<r<<".txt"<<endl;
        //Writing run_data and gbest values
        run_data<<k<<"\t";
        for(j=0;j<D;j++)
            run_data<<gbest_pos_overall[j]<<"\t";
        run_data<<gbest_fval_overall<<"\t"<<gbest_fitness_overall<<"\t"<<gbest_fval[k]<<"\t"<<gbest_fitness[k]<<endl;
        cout<<"File Written"<<endl;
        cout<<"-------------------------------------------\n";
        k++;
    }
    run_data.close();
    //Copying overall_gbest final value to data structure
    data[r].corr_fitness=gbest_fitness_overall;
    data[r].best_fval=gbest_fval_overall;
    for (j = 0; j < D; j++)
        data[r].best_pos.push_back(gbest_pos_overall[j]);
}
