#ifndef CPP_DBUG
#define CPP_DBUG

#include <time.h>
#include "HEAD.CPP"
static bool DBUG_FLAGS=false;

int DBUG_INIT(bool DBUG_INIT_FLAG,int DBUG_INIT_ARGC,char* DBUG_INIT_ARGV[])
{
    if(DBUG_INIT_ARGC>=2)
    {
        if(DBUG_INIT_ARGV[1][1]=='d'||DBUG_INIT_ARGV[1][1]=='D'){DBUG_INIT_FLAG=true ;}
        else                                                    {DBUG_INIT_FLAG=false;}
    }
    if(DBUG_INIT_FLAG==true)
    {
        DBUG_FLAGS=true ;
        cout<<"--------------------------------DEBUG MODE ON--------------------------------"<<endl;
    }
    else
    {
        DBUG_FLAGS=false;
        cout<<"--------------------------------DEBUG MODE OFF-------------------------------"<<endl;
    }
    return 0;
}

int DBUG_OUTP(void* DBUG_OUTP_PTRP,string DBUG_OUTP_NAME,string DBUG_OUTP_TEXT)
{
    if(DBUG_FLAGS==false)
    return 0;
    if(DBUG_OUTP_PTRP==nullptr) cout<<" [FAIL] ";
    else                        cout<<" [OKAY] ";
    time_t DBUG_OUTP_TIMP;time(&DBUG_OUTP_TIMP);char DBUG_OUTP_TIME[64];
    strftime(DBUG_OUTP_TIME, sizeof(DBUG_OUTP_TIME),"%Y-%m-%d %H:%M:%S",localtime(&DBUG_OUTP_TIMP) );
    cout<<DBUG_OUTP_TIME<<" ";
    cout<<"0x"<<DBUG_OUTP_PTRP<<DBUG_OUTP_NAME<<": "<<DBUG_OUTP_TEXT<<endl;
    return 0;
}


int DBUG_TFPS(int DBUG_TFPS_NFPS,const string DBUG_OUTP_NAME,const string DBUG_OUTP_TEXT)
{
    if(DBUG_TFPS_NFPS>=30)cout<<" [INFO] ";
    else                  cout<<" [WARN] ";
    time_t DBUG_OUTP_TIMP;time(&DBUG_OUTP_TIMP);char DBUG_OUTP_TIME[64];
    strftime(DBUG_OUTP_TIME, sizeof(DBUG_OUTP_TIME),"%Y-%m-%d %H:%M:%S",localtime(&DBUG_OUTP_TIMP) );
    cout<<DBUG_OUTP_TIME<<" ";
    cout<<"0x"<<WIND_RENDP<<DBUG_OUTP_NAME<<": "<<DBUG_TFPS_NFPS<<DBUG_OUTP_TEXT<<endl;
    return 0;
}


#endif
