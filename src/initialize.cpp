#include "psoheader.h"
void ini_prob()
{
    int j;
    double ul=5,ll=-5; //Default upper and lower limits
    switch(prob)
    {
        case 1:
        {
            N_ec=0,N_iec=0;
            tc_func=spherical;
            break;
        }
        case 2:
        {
            N_ec=0,N_iec=0;
            tc_func=rastrigrin;
            break;
        }
        case 3:
        {
            N_ec=0,N_iec=0;
            tc_func=rosenbrock;
            break;
        }
        case 4:
        {
            D=2,N_ec=0,N_iec=0;
            tc_func=ackley;
            break;
        }
        case 5:
        {
            D=2,N_ec=0,N_iec=0;
            tc_func=goldstein;
            break;
        }
        case 6:
        {
            D=2,N_ec=0,N_iec=0;
            tc_func=beale;
            break;
        }
        case 7:
        {
            D=2,N_ec=0,N_iec=0;
            tc_func=booth;
            break;
        }
        case 8:
        {
            D=2,N_ec=0,N_iec=0;
            tc_func=matyas;
            break;
        }
        case 9:
        {
            D=2,N_ec=0,N_iec=0;
            tc_func=himmelblau_mm;
            break;
        }
        case 10:
        {
            D=2,N_ec=0,N_iec=2;
            tc_func=rosenbrock2;
            pos_ulimit={1.5,2.5};
            pos_llimit={-1.5,-0.5};
            break;
        }
        case 11:
        {
            D=4,N_ec=0,N_iec=0;
            tc_func=colville4;
            break;
        }
        case 12:
        {
            D=6,N_ec=4,N_iec=0;
            tc_func=colville6;
            pos_ulimit={400,1000,420,420,10000,0.5236};
            pos_llimit={0,0,340,340,-1000,0};
            break;
        }
        case 13:
        {
            D=2,N_ec=1,N_iec=1;
            tc_func=himmelblau1;
            break;
        }
        case 14:
        {
            D=2,N_ec=0,N_iec=3;
            tc_func=himmelblau3;
            pos_ulimit={75,65};
            pos_llimit={0,0};
            break;
        }
        case 15:
        {
            D=3,N_ec=2,N_iec=0;
            tc_func=himmelblau5;
            pos_llimit={0,0,0};
            break;
        }
        case 16:
        {
            D=9,N_ec=0,N_iec=14;
            tc_func=himmelblau16;
            break;
        }
        case 17:
        {
            D=10,N_ec=0,N_iec=0;
            tc_func=himmelblau17;
            for(int i=0;i<D;i++)
            {
                pos_ulimit.push_back(9.999);
                pos_llimit.push_back(2.001);
            }
            break;
        }
        case 18:
        {
            D=3,N_ec=0,N_iec=0;
            tc_func=himmelblau21;
            pos_ulimit={100,25.6,5};
            pos_llimit={0.1,0,0};
            break;
        }
        case 19:
        {
            D=2,N_ec=0,N_iec=2;
            tc_func=himmelblau24;
            break;
        }
        case 20:
        {
            D=3,N_ec=0,N_iec=1;
            tc_func=beale2;
            pos_llimit={0,0,0};
            break;
        }
        case 21:
        {
            D=4,N_ec=3,N_iec=0;
            tc_func=rosen_suzuki;
            break;
        }
        case 22:
        {
            D=4,N_ec=1,N_iec=2;
            tc_func=cattle_feed;
            pos_llimit={0,0,0,0};
            break;
        }
        case 23:
        {
            D=6,N_ec=0,N_iec=2;
            tc_func=transformer_design;
            pos_llimit={0,0,0,0,0,0};
            break;
        }
        default :
        {
            cout<<"Problem not avialable"<<endl;
            exit(0);
        }
    }
    //Setting Default Limits if not defined by function
    if(pos_ulimit.size()==0)
    {
        for(j=0;j<D;j++)
            pos_ulimit.push_back(ul);
    }
    if(pos_llimit.size()==0)
    {
        for(j=0;j<D;j++)
            pos_llimit.push_back(ll);
    }
    //Define velocity limits (only used in inertia weight method) (Problem if both pos limit is negative)
    for (j=0;j<D;j++)
    {
        vel_ulimit.push_back((pos_ulimit[j]-pos_llimit[j])/4.0);
        vel_llimit.push_back(-vel_ulimit[j]);
    }
    cout<<"Dimension of Problem="<<D<<"\t Equality Constraints="<<N_ec<<"\t In-equality Constraints="<<N_iec<<endl;
    cout<<"Position limits->"<<endl;
    print(pos_ulimit);
    print(pos_llimit);
}