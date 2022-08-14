#include "psoheader.h"
void calc_func(vector <Particle> &swarm)
{
    int i=0,j=0;
    double f=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,m=1;
    double X[D];
    for(i=0;i<N;i++)
    {
        f=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,m=1;
        for(j=0;j<D;j++)
            X[j]=swarm[i].pos[j];
        switch(prob)
        {
            case 0:
            {
                cout<<"No problem selected";
                break;
            }
            case 1:
            {
                for (j = 0; j < D; j++)
                    f=f+X[j]*X[j]; //Spherical Function(UC)
                break;
            }
            case 2:
            {
                for (j = 0; j < D; j++)
                    f=f+pow(X[j],2)-10*cos(2*22*X[j]/7)+10; //Rastrigrin Function(UC)
                break;
            }
            case 3:
            {
                for (j = 0; j < D-1; j++)
                    f=f+100*pow((X[j+1]-pow(X[j],2)),2)+pow((1-X[j]),2); // Rosenbrock Function(UC)
                break;
            }
            case 4:
            {
                f = -20 * exp(-0.2 * sqrt(0.5 * (pow(X[0], 2) + pow(X[1], 2)))) - exp(0.5 * (cos(2 * 22 * X[0] / 7) + cos(2 * 22 * X[1] / 7))) + exp(1) + 20; //Ackley Function (D=2)(UC)
                break;
            }
            case 5:
            {
                f=(1+pow((X[0]+X[1]+1),2)*(19-14*X[0]+3*pow(X[0],2)-14*X[1]+6*X[0]*X[1]+3*pow(X[1],2)))*(30+pow((2*X[0]-3*X[1]),2)*(18-32*X[0]+12*pow(X[0],2)+48*X[1]-36*X[0]*X[1]+3*pow(X[1],2))); //Goldstein price function (UC) (D=2)
                break;
            }
            case 6:
            {
                f=pow((1.5-X[0]+X[0]*X[1]),2)+pow((2.25-X[0]+X[0]*pow(X[1],2)),2)+pow((2.625-X[0]+X[0]*pow(X[1],3)),2); // Beale Function (UC) (D=2)
                break;
            }
            case 7:
            {
                f=pow((X[0]+2*X[1]-7),2)+pow((2*X[0]+X[1]-5),2); //Booth function (UC) (D=2)
                break;
            }
            case 8:
            {
                f=0.26*(X[0]*X[0]+X[1]*X[1])-0.48*X[0]*X[1]; //Matyas Function (UC) (D=2)
                break;
            }
            case 9:
            {
                f=pow((X[0]*X[0]+X[1]-11),2)+pow((X[0]+X[1]*X[1]-7),2); //Himmelblau's function (UC) (D=2)
                break;
            }
            case 10:
            {
                f=100*pow((X[1]-pow(X[0],2)),2)+pow((1-X[1]),2); // Rosenbrock Function(C Linear and Non lineacr constrains) N_iec=2 (D=2)
                break;
            }
            case 11:
            {
                f=100*pow(X[1]-pow(X[0],2),2)+pow(1-X[0],2)+90*pow(X[3]-pow(X[2],2),2)+pow(1-X[2],2)+10.1*(pow(X[1]-1,2)+pow(X[3]-1,2))+19.8*(X[1]-1)*(X[3]-1); //Colvile No.4 (D=4) (UC)
                break;
            }
            case 12: //NW
            {
                if(X[0]>=0&&X[0]<300) //Colville No 6 (D=6) (C) N_ec=4
                    f1=30*X[0];
                else
                    f1=31*X[0];
                if(X[1]<100)
                    f2=28*X[1];
                else if(X[1]<200)
                    f2=29*X[1];
                else
                    f2=30*X[1];
                f=f1+f2;
                break;
            }
            case 13:
            {
                f=pow(X[0]-2,2)+pow(X[1]-1,2); //Himmelblau No 1 (D=2) (C) N_ec=1 N_iec=1
                break;
            }
            case 14:
            {
                f1=-75.196+3.8112*X[0]+0.0020567*pow(X[0],3)-1.0345*pow(10,-5)*pow(X[0],4); //Himmelblau No 3 (D=2) (C) N_ec=0 N_iec=3
                f2=6.8306*X[1]-0.030234*X[0]*X[1]+1.28134*pow(10,-3)*X[1]*pow(X[0],2);
                f3= 2.266*pow(10,-7)*pow(X[0],4)*X[1]-0.25645*pow(X[1],2)+ .0034604*pow(X[1],3)-1.3514*pow(10,-5)*pow(X[1],4);
                f4=28.106/(X[1]+1)+5.2375*pow(10,-6)*pow(X[0],2)*pow(X[1],2)+6.3*pow(10,-8)*pow(X[0],3)*pow(X[1],2);
                f5=-7*pow(10,-10)*pow(X[0],3)*pow(X[1],3)-3.405*pow(10,-4)*X[0]*pow(X[1],2)+1.6638*pow(10,-6)*X[0]*pow(X[1],3);
                f6=2.8673*pow(2.718281828,0.005*X[0]*X[1])-3.5256*pow(10,-5)*pow(X[0],3)*X[1];
                f=f1+f2+f3+f4+f5+f6;
                break;
            }
            case 15:
            {
                f=1000-pow(X[0],2)-2*pow(X[1],2)-pow(X[2],2)-X[0]*X[1]-X[0]*X[2]; //Himmelblau No 5 (D=3) (C) N_ec=2 N_iec=0 X[i]>0
                break;
            }
            case 16:
            {
                f=-.5*(X[0]*X[3]-X[1]*X[2]+X[2]*X[8]-X[4]*X[8]+X[4]*X[7]-X[5]*X[6]); //Himmelblau No 16 (D=9) (C) N_ec=0 N_iec=14
                break;
            }
            case 17:
            {
                for (j = 0; j < D; j++)
                {
                    f1=f1+pow(log(X[j]-2),2)+pow(log(10-X[j]),2);
                    m=m*pow(X[j],0.2);
                }
                f=f1-m; //Himmelblau No 17 (D=10) (UC) N_ec=0 N_iec=0 Limits->2.001-9.999
                break;
            }
            case 18:
            {
                for (j = 1; j < 100; j++)
                    f=f+pow(-0.01*j+exp((-1/X[0])*pow(25+pow(-50*log(0.01*j),2/3)-X[1],X[2])),2);  //Hjmmelblau No 21 (D=3) (UC) N_ec=0 N_iec=0 Boundaries used
                break;
            }
            case 19:
            {
                f=pow(X[0]-2,2)+pow(X[1]-1,2); // Himmelblau No 24 (D=2) (C) N_ec=0 N_iec=2
                break;
            }
            case 20:
            {
                f=9-8*X[0]-6*X[1]-4*X[2]+2*pow(X[0],2)+2*pow(X[1],2)+pow(X[2],2)+2*X[0]*X[1]+2*X[0]*X[2]; //Beale"s Problem 2 (C) (D=3) N_ec=0 N_iec=1 Boundaries->X>0
                break;
            }
            case 21:
            {
                f=pow(X[0],2)+pow(X[1],2)+2*pow(X[2],2)+pow(X[3],2)-5*X[0]-5*X[1]-21*X[2]+7*X[3]; //Rosen-Suzuki (C) (D=4) N_iec=3 N_ec=0
                break;
            }
            case 22:
            {
                f=24.55*X[0]+26.75*X[1]+39*X[2]+40.50*X[3]; //Cattle Feed (C) (D=4) N_ec=1 N_iec=2 Boundaries->X>0
                break;
            }
            case 23:
            {
                f=0.0204*X[0]*X[3]*(X[0]+X[1]+X[2])+0.0187*X[1]*X[2]*(X[0]+1.57*X[1]+X[3])+0.0607*X[0]*X[3]*X[4]*X[4]*(X[0]+X[1]+X[2])+0.0437*X[1]*X[2]*X[5]*X[5]*(X[0]+1.57*X[1]+X[3]);
                break; //Transformer design (C) (D=6) N_ec=0 N_iec=2 Boundaries->X>0
            }
        }
        swarm[i].fval=f;
    }
}
void calc_voilation(vector <Particle> &swarm)
{
    //Exterior Penalty Method-> g(i)<0 h(i)=0
    double g[N_iec],h[N_ec],X[D];
    int i,j;
    double tolerance=pow(10,-5); //Define tolerance to constraint voilations
    for(i=0;i<N;i++)
    {
        for(j=0;j<D;j++)
            X[j]=swarm[i].pos[j];
        switch(prob)
        {
            case 10:
            {
                g[0]=pow(X[0]-1,3)-X[1]+1;
                g[1]=X[0]+X[1]-2;
                break;
            }
            case 12:
            {
                h[0]=300-X[0]-X[2]*X[3]*cos(1.48577-X[5])/131.078+cos(1.47588)*pow(X[2],2)*0.90798/131.078;
                h[1]=-X[1]-X[2]*X[3]*cos(1.48577+X[5])/131.078+cos(1.47588)*pow(X[3],2)*0.90798/131.078;
                h[2]=-X[4]-X[2]*X[3]*cos(1.48577+X[5])/131.078+sin(1.47588)*pow(X[3],2)*0.90798/131.078;
                h[3]=200-X[2]*X[3]*sin(1.48577-X[5])/131.078+sin(1.47588)*pow(X[2],2)*0.90798/131.078;
                break;
            }
            case 13:
            {
                g[0]=.25*X[0]*X[0]+X[1]*X[1]-1;
                h[0]=X[0]-2*X[1]+1;
                break;
            }
            case 14:
            {
                g[0]=-X[0]*X[1]+700;
                g[1]=-X[1]+X[0]*X[0]/125;
                g[2]=-pow(X[1]-50,2)+5*(X[0]-55);
                break;
            }
            case 15:
            {
                h[0]=8*X[0]+14*X[1]+7*X[2]-56;
                h[1]=pow(X[0],2)+pow(X[1],2)+pow(X[2],2)-25;
                break;
            }
            case 16:
            {
                g[0]=-1+pow(X[2],2)+pow(X[3],2);
                g[1]=-1+pow(X[9],2);
                g[2]=-1+pow(X[4],2)+pow(X[5],2);
                g[3]=-1+pow(X[0],2)+pow(X[1]-X[8],2);
                g[4]=-1+pow(X[0]-X[4],2)+pow(X[1]-X[5],2);
                g[5]=-1+pow(X[0]-X[6],2)+pow(X[1]-X[7],2);
                g[6]=-1+pow(X[2]-X[4],2)+pow(X[3]-X[5],2);
                g[7]=-1+pow(X[2]-X[6],2)+pow(X[3]-X[7],2);
                g[8]=-1+pow(X[6],2)+pow(X[7]-X[8],2);
                g[9]=-X[0]*X[3]+X[1]*X[2];
                g[10]=-X[2]*X[8];
                g[11]=X[4]*X[8];
                g[12]=-X[4]*X[7]+X[5]*X[6];
                g[13]=-X[8];
                break;
            }
            case 19:
            {
                g[0]=X[0]+X[1]-2;
                g[1]=pow(X[0],2)-X[1];
                break;
            }
            case 20:
            {
                g[0]=-3+X[0]+X[1]+2*X[2];
                break;
            }
            case 21:
            {
                g[0]=-8+pow(X[0],2)+pow(X[1],2)+pow(X[2],2)+pow(X[3],2)+X[0]-X[1]+X[2]-X[3];
                g[1]=-10+pow(X[0],2)+2*pow(X[1],2)+pow(X[2],2)+2*pow(X[3],2)-X[0]-X[3];
                g[2]=-5+2*pow(X[0],2)+pow(X[1],2)+pow(X[2],2)+2*X[0]-X[1]-X[3];
                break;
            }
            case 22:
            {
                g[0]=-2.3*X[0]-5.6*X[1]-11.1*X[2]-1.3*X[3]+5;
                g[1]=-12*X[0]-11.9*X[1]-41.8*X[2]-52.1*X[3]+21+1.645*pow(.28*pow(X[0],2)+.19*pow(X[1],2)+20.5*pow(X[2],2)+.62*pow(X[3],2),0.5);
                h[0]=X[0]+X[1]+X[2]+X[3]-1;
                break;
            }
            case 23:
            {
                g[0]=-.001*X[0]*X[1]*X[2]*X[3]*X[4]*X[5]+2.07;
                g[1]=-1+0.00062*X[0]*X[3]*X[4]*X[4]*(X[0]+X[1]+X[2])+0.00058*X[1]*X[2]*X[5]*X[5]*(X[0]+1.57*X[1]+X[3]);
                break;
            }
        }
        for(j=0;j<N_iec;j++)
        {
            if(g[j]>tolerance)
                swarm[i].voilation[j]=g[j];
            else
                swarm[i].voilation[j]=0;
        }
        //For equality constraints
        for(j=N_iec;j<N_ec+N_iec;j++)
        {
            if(abs(h[j-N_iec])>tolerance)
                swarm[i].voilation[j]=abs(h[j-N_iec]);
            else
                swarm[i].voilation[j]=0;
        }
    }
}
