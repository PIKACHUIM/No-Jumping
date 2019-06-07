#pragma once
#ifndef CGMS_CPP
#define CGMS_CPP

#include "LIBS/READ.CPP"
#include "LIBS/FKYP.CPP"
#include "LIBS/TYPE.CPP"
#include "LIBS/REND.CPP"
#include "EXTL/WIND.CPP"
#include "EXTL/DBUG.CPP"
class CGMS
{
public:
   REND GAME_REND;
   READ GAME_PACN;
   READ GAME_FACN;
   READ CGMS_PASS_RDMG;
    int LAST_TIME;
    int NOWN_TIME;
    int TOTA_TIME;
    int GAME_NUMS;
    int CGMS_PART;
    int CGMS_GMPA[16][5];
    int CGMS_GMFA[16][5];
int CGMS_PDAN(int ix,int iy,int FTTL[16][5],int LTNS)
{
    for(int LOOP=1;LOOP<=LTNS;LOOP++)
        {
            int PDSJ_FLAG=0;
            if(ix<FTTL[LOOP][1]||ix>FTTL[LOOP][2])
                PDSJ_FLAG=1;
            if(iy<FTTL[LOOP][3]||iy>FTTL[LOOP][4])
                PDSJ_FLAG=1;
            if(PDSJ_FLAG==0)
                return LOOP;
        }
        return 0;
}
int CGMS_INIT(int CGMS_NUMS)
    {
        //------------------配置复制:按键检测------------------------
            GAME_PACN.SETP("CONF","POS","CGMS",01,4);
            GAME_FACN.SETP("CONF","POS","CGMS",02,4);
            CGMS_PASS_RDMG.SETP("MAPS","MAP","PASS",00,05);
            for(int LOOP=1;LOOP<=GAME_PACN.LENS;LOOP++)
            for(int LTMP=1;LTMP<=4;LTMP++)
                CGMS_GMPA[LOOP][LTMP]=GAME_PACN.DATA[LOOP][LTMP];
                CGMS_GMPA[   0][   0]=GAME_PACN.LENS;
            for(int LOOP=1;LOOP<=GAME_FACN.LENS;LOOP++)
            for(int LTMP=1;LTMP<=4;LTMP++)
                CGMS_GMFA[LOOP][LTMP]=GAME_FACN.DATA[LOOP][LTMP];
                CGMS_GMFA[   0][   0]=GAME_FACN.LENS;
        //---------------------------------------------------------
        GAME_REND.INIT(CGMS_NUMS);
        LAST_TIME=(int)SDL_GetTicks();
        NOWN_TIME=(int)SDL_GetTicks();
        GAME_NUMS=CGMS_NUMS;
        TOTA_TIME=0;
        return 0;
    }

int CGMS_PASS()
{
    SDE  CGMA_PASS_EVEN;
         CGMA_PASS_EVEN.type=SDL_KEYDOWN;
    int  CGMS_PASS_FLAG=1;
    IMGS CGMS_PASS_IGPA[9];
    for (int LOOP=1;LOOP<=CGMS_PASS_RDMG.LENS;LOOP++)
             CGMS_PASS_IGPA[LOOP].SETP("MENU",
                 CGMS_PASS_RDMG.DATA[LOOP][1],
                 CGMS_PASS_RDMG.DATA[LOOP][2],
                 CGMS_PASS_RDMG.DATA[LOOP][3],
                 CGMS_PASS_RDMG.DATA[LOOP][4],
                 CGMS_PASS_RDMG.DATA[LOOP][5]);
    while(CGMS_PASS_FLAG)
    {
        REND_CLEN();
        for (int LOOP=1;LOOP<=CGMS_PASS_RDMG.LENS;LOOP++)
            CGMS_PASS_IGPA[LOOP].SHOW();
        REND_SHOW();
        while (SDL_PollEvent(&CGMA_PASS_EVEN))
        {
            if(CGMA_PASS_EVEN.type==SDL_QUIT)
            {
                CGMS_PASS_FLAG=0;
                WIND_EXIT();                               //关闭窗口
                return -2;
            }
            if(CGMA_PASS_EVEN.type==SDL_MOUSEBUTTONUP)
            {
            int CGMS_ANPA=
                CGMS_PDAN(CGMA_PASS_EVEN.button.x,
                          CGMA_PASS_EVEN.button.y,
                          CGMS_GMPA,
                          CGMS_GMPA[0][0]);                //关卡界面
                if(CGMS_ANPA==0)
                {
                        CGMS_ANPA=-1;
                        break;
                }
                else
                {
                        CGMS_PART=CGMS_ANPA;
                        return CGMS_ANPA;
                }
              }
          }
     }
     return 0;
}

int CGMS_FAIL(int DQJD)
    {
        SDE  CGMS_FAIL_EVEN;
        while (SDL_PollEvent(&CGMS_FAIL_EVEN))
        CGMS_FAIL_EVEN.type=SDL_KEYUP;
        IMGS FAIM[6];
        FAIM[1].SETP("FAIL",01,560,580,457,175);
        FAIM[2].SETP("FAIL",02,780,650,197, 85);
        FAIM[3].SETP("FAIL",03,575+DQJD,590, 23, 22);
        FAIM[4].SETP("MENU",12,590,650, 85, 85);
        FAIM[5].SETP("MENU",13,685,650, 85, 85);
        while(CGMS_FAIL_EVEN.type!=SDL_QUIT)
       {

            for(int LOOP=1;LOOP<=5;LOOP++) FAIM[LOOP].SHOW();
            REND_SHOW();
            while (SDL_PollEvent(&CGMS_FAIL_EVEN))
            {
                if(CGMS_FAIL_EVEN.type==SDL_QUIT)
                {
                    WIND_EXIT();                                 //关闭窗口
                    break;
                }
                if(CGMS_FAIL_EVEN.type==SDL_MOUSEBUTTONUP)
                {
                CGMS_FAIL_EVEN.type=SDL_KEYUP;
                int CGMS_ANPA=
                    CGMS_PDAN(CGMS_FAIL_EVEN.button.x,
                              CGMS_FAIL_EVEN.button.y,
                              CGMS_GMFA,
                              CGMS_GMFA[0][0]);                //关卡界面
                    if(CGMS_ANPA==0)
                    {
                            CGMS_ANPA=-1;
                            break;
                    }
                    else
                    {
                            CGMS_PART=CGMS_ANPA;
                            return CGMS_ANPA;
                    }
                  }

            }
       }
        return 0;
    }

int CGMS_SHOW()
    {
       int SHOW_TEMP;
       int RTEN=GAME_REND.EXEC();
                GAME_REND.SHOW();
        if(RTEN== 0)//过关
        {
            SHOW_TEMP=CGMS_PASS();
            return SHOW_TEMP;

        }
        if(RTEN== 1)//计时
        {
            NOWN_TIME =SDL_GetTicks();

            if(NOWN_TIME-LAST_TIME>10)
            {
                TOTA_TIME+=NOWN_TIME-LAST_TIME;
                LAST_TIME =NOWN_TIME;
            }
            if(DBUG_OTIME==1)
            {
                cout<<" [CGMS] ";
                DBUG_GTIM();
                cout<<"0x"<<WIND_RENDP<<" "<<"GAME_PROEXE: "<<"~~|GAME|NOW_TIME_IS:";
                printf("%6.2f\n",(float)TOTA_TIME/1000);
            }
        }
        if(RTEN==-1)//暂停
        {
            NOWN_TIME =SDL_GetTicks();
            LAST_TIME =NOWN_TIME;
        }
        return 0;
}
int CGMS_NEXT()
    {
    if(DBUG_OTIME==1)
    {
        cout<<" [NEXT] ";
        DBUG_GTIM();
        cout<<"0x"<<WIND_RENDP
            <<" "<<"NEXT_BIRDNS: "
            <<"~~|BIRD|NOW_BIRD_AT:"
            <<GAME_REND.NOWN+GAME_REND.BIRP
            <<endl;
    }

        if(
           GAME_REND.MAPS[GAME_REND.NOWN+GAME_REND.BIRP-1].NOWH>
           GAME_REND.MAPS[GAME_REND.NOWN+GAME_REND.BIRP  ].NOWH+10)
            return 1;
        if(  GAME_REND.BIRP<=7
           ||GAME_REND.TEMP.LENS-
            (GAME_REND.NOWN+
             GAME_REND.BIRP)<=6)
             GAME_REND.BIRP++;
        else GAME_REND.NOWN=GAME_REND.NOWN+1;
        return 0;
    }
int CGMS_DEAL()
{
        int CGRT;
        SDE CGMS_EVEN;
        int DEAL_EXIT=1;
        while(DEAL_EXIT)
        {
            while (SDL_PollEvent(&CGMS_EVEN))
            {
                if(CGMS_EVEN.type==SDL_QUIT)
                    WIND_EXIT();                                 //关闭窗口
                if(CGMS_EVEN.type==SDL_MOUSEBUTTONDOWN
                 ||CGMS_EVEN.type==SDL_KEYDOWN)
                {
                    if(CGMS_NEXT()==1&&DBUG_NOKIL == 0)
                    {
                        CGRT =  CGMS_FAIL((int)
                                          (GAME_REND.NOWN+
                                           GAME_REND.BIRP)
                                          /GAME_REND.TEMP.LENS*350);  //小鸟相撞
                        if(CGRT==3)
                        {
                            int LOOP=GAME_REND.NOWN+GAME_REND.BIRP-1;
                            for(;LOOP>=2&&GAME_REND.MAPS[LOOP].TYPE>10;LOOP--);
                            GAME_REND.BIRP=1;
                            GAME_REND.NOWN=LOOP;
                        }
                        else
                            return CGRT;
                    }




                }
            }
            CGRT =  CGMS_SHOW();
            if (CGRT!=0)return CGRT;
            SDL_Delay(16);
        }
        return 0;
    }
};

#endif
