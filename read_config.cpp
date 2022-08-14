#include "psoheader.h"
void read_config()
{
    char c;
    int count=0;
    ifstream config("config.conf");
    if(config.is_open()==false)
        cout<<"Unable to read solver configuration"<<endl;
    while(!config.eof())
    {
        config>>c;
        if(c==':')
        {
            count++;
            switch(count)
            {
                case 1:
                {
                    config>>N;
                    break;
                }
                case 2:
                {
                    config>>prob;
                    break;
                }
                case 3:
                {
                    config>>method;
                    break;
                }
                case 4:
                {
                    config>>itr;
                    break;
                }
                case 5:
                {
                    config>>rmax;
                    break;
                }
                case 6:
                {
                    config>>D;
                    break;
                }
                case 7:
                {
                    config>>threads;
                    break;
                }
                default :
                {
                    break;
                }
            }
        }
        if(count>20)
            break;
    }
    config.close();
    cout<<"Optimizer Configured"<<endl;
    cout<<"Problem"<<"\t"<<"Method"<<"\t"<<"Pop"<<"\t"<<"Max itr"<<"\t"<<"Runs"<<"\t"<<"Dim"<<"\t"<<endl;
    cout<<prob<<"\t"<<method<<"\t"<<N<<"\t"<<itr<<"\t"<<rmax<<"\t"<<D<<"\t"<<endl;
    //cout<<"OpenMP using "<<no_of_threads<<" threads"<<endl;
}
