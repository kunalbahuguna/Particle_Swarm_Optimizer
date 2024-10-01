#include "psoheader.h"
void print(Particle par)
{
    cout<<"Position-> ";
    print(par.pos);
    cout<<"Current Fitness="<<par.fitness<<" Current Function Value="<<par.fval<<"\n";
    cout<<"Best Position-> ";
    print(par.pbest_pos);
    cout<<"Personal Best Fitness="<<par.pbest_fitness<<"\n";
    cout<<"Velocity-> ";
    print(par.vel);
    cout<<"Voilation Vector->";
    print(par.voilation);
    cout<<"Is feasible->";
    print(par.is_feasible);
    cout<<"XXXXXXXXXXXXXX\n";
}
void print(double a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void print(vector <double> a)
{
    int i;
    for(i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    //cout<<"\n";
}
void print(vector <int> a)
{
    int i;
    for(i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void print(bool v)
{
    if(v==1)
        cout<<"True\n";
    else
        cout<<"False\n";
}
