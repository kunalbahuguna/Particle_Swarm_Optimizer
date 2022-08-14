#include "psoheader.h"
int D,N,rmax,itr,N_iec,N_ec,prob,threads;
char method;
int main()
{
    int r,j;
    read_config();
    struct run data[rmax];
    double sum=0,avg_fval=0;
    for(r=0;r<rmax;r++)
    {
        cout<<"STARTING RUN="<<r+1<<endl;
        opti_PSO(r,data);
        cout<<"Run Complete->Displaying Run best"<<endl;
        for (j = 0; j < D; j++)
            cout<<data[r].best_pos[j]<<" ";
        cout<<"\t Fitness="<<data[r].corr_fitness<<"\t Best Function Value="<<data[r].best_fval<<"\n";
        sum=sum+data[r].best_fval;
        cout<<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    }
    cout<<"Optimizer Ends"<<endl;
    for(r=0;r<rmax;r++)
    {
        for (j = 0; j < D; j++)
            cout<<data[r].best_pos[j]<<" ";
        cout<<"\t Fitness="<<data[r].corr_fitness<<"\t Best Function Value="<<data[r].best_fval<<"\n";
    }
    avg_fval=sum/rmax;
    cout<<"Average Function Value="<<avg_fval<<"\n";
    return 0;
}
