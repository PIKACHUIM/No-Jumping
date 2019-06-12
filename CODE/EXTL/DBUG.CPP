#pragma once
#ifndef DBUG_CPP
#define DBUG_CPP

#include "HEAD.CPP"
#include "windows.h"
int DBUG_INIT(int DBUG_INIT_ARGC,char* DBUG_INIT_ARGV[])
{   system("mode con:cols=79 lines=60");
    if(DBUG_INIT_ARGC>=2)for (int DBUG_INIT_LOOP=1;DBUG_INIT_LOOP<DBUG_INIT_ARGC;DBUG_INIT_LOOP++)
    {
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='a'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='A')DBUG_ACCED = 0;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='b'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='B')DBUG_SYNCD = 0;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='c'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='C')DBUG_NOKIL = 1;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='d'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='D')DBUG_DEBUG = 1;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='e'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='E')DBUG_EEOOR = 1;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='f'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='F')DBUG_OTFPS = 1;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='g'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='G')DBUG_OTIME = 1;
        if(DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='h'||DBUG_INIT_ARGV[DBUG_INIT_LOOP][1]=='H')DBUG_OTSTP = 1;
    }
    if(DBUG_ACCED ==0 ) DBUG_GUPMD-=2;
    if(DBUG_SYNCD ==0 ) DBUG_GUPMD-=4;
    if(DBUG_DEBUG)cout<<"--------------------------------DEBUG MODE ON--------------------------------"<<endl;
    else          cout<<"--------------------------------DEBUG MODE OFF-------------------------------"<<endl;
    return 0;
}

int DBUG_GTIM()
{
    time_t DBUG_OUTP_TIMP;time(&DBUG_OUTP_TIMP);char DBUG_OUTP_TIME[64];
    strftime(DBUG_OUTP_TIME, sizeof(DBUG_OUTP_TIME),"%Y-%m-%d %H:%M:%S",localtime(&DBUG_OUTP_TIMP) );
    cout<<DBUG_OUTP_TIME<<" ";
    return 0;
}

int DBUG_OUTP(void* DBUG_OUTP_PTRP,string DBUG_OUTP_NAME,string DBUG_OUTP_TEXT)
{
    if(DBUG_DEBUG    ==0       && DBUG_EEOOR==0)
        return 0;
    if(DBUG_OUTP_PTRP!=nullptr && DBUG_DEBUG==0)
        return 0;
    if(DBUG_OUTP_PTRP!=nullptr && DBUG_DEBUG==1)
         cout<<" [OKAY] ";
    else cout<<" [FAIL] ";
    DBUG_GTIM();
    cout<<"0x"<<DBUG_OUTP_PTRP;
    cout<<DBUG_OUTP_NAME<<": ";
    cout<<DBUG_OUTP_TEXT<<endl;
        return 0;
}

int DBUG_TFPS(int DBUG_TFPS_NFPS,const string DBUG_OUTP_NAME,const string DBUG_OUTP_TEXT)
{
    if(DBUG_OTFPS==0)
        return 0;
    if(DBUG_TFPS_NFPS>=30)cout<<" [INFO] ";
    else                  cout<<" [WARN] ";
    DBUG_GTIM();
    cout<<"0x"<<WIND_RENDP<<DBUG_OUTP_NAME<<": "<<DBUG_TFPS_NFPS<<DBUG_OUTP_TEXT<<endl;
        return 0;
}

#endif
