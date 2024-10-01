#include "psoheader.h"
Particle opti_PSO(int r)
{
    int i = 0, j = 0, k = 1, nbest,tem=0;
    float r1,r2,r3,a1=0,a2=2.05,a3=2.05,v=1,w=0,b2=2,b3=2,b4=2;
    a1 = 2.0 * v / (fabs(2.0 - (a2 + a3) - sqrt((a2 + a3) * (a2 + a3) - 4.0 * (a2 + a3))));
    cout<<a1<<endl;
    vector<Particle> swarm;
    vector <Particle> best; //Best particle in every iteration
    Particle best_overall; //Overall Best Particle of the run
    // Initializing first population and X,Vel limits
    ini_swarm(swarm);
    cout << "Initial Population Generated" << endl;
    // Initializing gbest and overall_gbest with valure of first particle
    best.push_back(swarm[0]);
    // Finding 1st gbest value and also taking it as gbest _overall
    for (i = 0; i < N; i++)
    {
        if (swarm[i].fitness < best[0].fitness)
            best[0]=swarm[i];
    }
    best_overall=best[0];
    /*
    cout<<"Printing Starting population->"<<endl;
    for(i=0;i<N;i++)
        print(swarm[i]);
    */
    ofstream run_data("data/run_data" + to_string(r) + ".txt", ios::trunc);
    if (run_data.is_open() == false)
        cout << "Err opening file" << endl;
    run_data << "itr\tx0\tx1\tgfval\tgfit\tlfval\tlfit\n";
    run_data << 0 << "\t";
    for (j=0;j<D;j++)
        run_data<<best_overall.pos[j] << "\t";
    run_data<<best_overall.fval<<"\t"<<best_overall.fitness<<"\t"<<best[0].fval<<"\t"<<best[0].fitness<<endl;
    // Starting optimiser
    while (k < itr)
    {
        cout << "Starting iteration no=" << k << "\t";
        // Calculating Velocities
        w = 1.2 - 1.1 * ((float)k / (float)itr); // inertia weight factor
        for (i = 0; i < N; i++)
        {
            r1 = give_rn(0.0, 1.0);
            r2 = give_rn(0.0, 1.0);
            r3 = give_rn(0.0, 1.0);
            if (method == 'c') // Velocity constriction method
            {
                for (j = 0; j < D; j++)
                    swarm[i].vel[j] = a1 * (swarm[i].vel[j] + a2 * r1 * (swarm[i].pbest_pos[j] - swarm[i].pos[j]) + a3 * r2 * (best[k-1].pos[j] - swarm[i].pos[j]));
            }
            else if (method == 'w') // Inertial weight factor method
            {
                for (j = 0; j < D; j++)
                {
                    swarm[i].vel[j] = w * swarm[i].vel[j] + b2 * r1 * (swarm[i].pbest_pos[j] - swarm[i].pos[j]) + b3 * r2 * (best[k-1].pos[j] - swarm[i].pos[j]);
                    if (swarm[i].vel[j] > vel_ulimit[j])
                        swarm[i].vel[j] = vel_ulimit[j];
                    if (swarm[i].vel[j] < vel_llimit[j])
                        swarm[i].vel[j] = vel_llimit[j];
                }
            }
            else if (method == 'f') // FDR/EPSO
            {
                nbest = find_nbest(swarm, i);
                for (j = 0; j < D; j++)
                {
                    swarm[i].vel[j] = w * swarm[i].vel[j] + b2 * r1 * (swarm[i].pbest_pos[j] - swarm[i].pos[j]) + b3 * r2 * (best[k-1].pos[j] - swarm[i].pos[j]) + b4 * r3 * (swarm[nbest].pos[j] - swarm[i].pos[j]);
                    if (swarm[i].vel[j] > vel_ulimit[j])
                        swarm[i].vel[j] = vel_ulimit[j];
                    if (swarm[i].vel[j] < vel_llimit[j])
                        swarm[i].vel[j] = vel_llimit[j];
                }
            }
            else
            {
                printf("err in method");
                exit(0);
            }
        }
        // Updating new position
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < D; j++)
            {
                swarm[i].pos[j] = swarm[i].pos[j] + swarm[i].vel[j];
                // position constraints
                if (swarm[i].pos[j] > pos_ulimit[j])
                    swarm[i].pos[j] = pos_ulimit[j];
                if (swarm[i].pos[j] < pos_llimit[j])
                    swarm[i].pos[j] = pos_llimit[j];
            }
        }
        calc_fitness(k, swarm); // New fitness claculated
        // Updating pbest
        for (i = 0; i < N; i++)
        {
            if (swarm[i].fitness < swarm[i].pbest_fitness)
            {
                swarm[i].pbest_fitness = swarm[i].fitness;
                for (j = 0; j < D; j++)
                    swarm[i].pbest_pos[j] = swarm[i].pos[j];
            }
        }
        // Updating gbest values for current population
        best.push_back(swarm[0]);
        for (i = 1; i < N; i++)
        {
            if (swarm[i].fitness < best[k].fitness)
                best[k]=swarm[i];
        }
        if (best[k].fitness<best_overall.fitness)
            best_overall=best[k];
        /*
        cout<<"Current Population->"<<endl;
        for (i = 0; i < N; i++)
        {
            cout<<"Printing Population No="<<i<<endl;
            print(pop[i]);
        }
        */
        cout << "Current gbest fitness=" << best_overall.fitness << "\t";
        cout << "Position->";
        print(best_overall.pos);
        if(N_ec+N_iec>0)
        {
            cout<<"\tFeasibility="<<best_overall.is_feasible<<"\t";
            for (j = 0; j < N_iec+N_ec; j++)
                cout<<best_overall.voilation[j]<<" ";
        }
        cout<<endl;
        //cout << "Writing data to file for current run->run_data" << r << ".txt" << endl;
        // Writing run_data and gbest values
        run_data << k << "\t";
        for (j=0;j<D;j++)
            run_data<<best_overall.pos[j]<<"\t";
        run_data<<best_overall.fval<<"\t"<<best_overall.fitness<<"\t"<<best[k].fval<<"\t"<<best[k].fitness<<endl;
        //cout << "File Written" << endl;
        //cout << "-------------------------------------------\n";
        k++;
    }
    run_data.close();
    return(best_overall);
}
int find_nbest(vector<Particle> &swarm, int k)
{
    int i, j, l = 0;
    double max = 0, max1 = 0, d = 0;
    for (i = 0; i < N; i++)
    {
        d = 0;
        for (j = 0; j < D; j++)
            d = d + pow(swarm[i].pos[j] - swarm[k].pos[j], 2);
        d = sqrt(d);
        max1 = swarm[i].fitness - swarm[k].fitness / fabs(d);
        if (max1 > max)
            l = i;
    }
    return (l);
}