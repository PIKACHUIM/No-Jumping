#pragma once
#ifndef REND_HPP
#define REND_HPP

#include"../EXTL/HEAD.CPP"
#include"../EXTL/DBUG.CPP"
#include"../LIBS/FKYP.CPP"
#include"../LIBS/READ.CPP"
#include"../LIBS/TYPE.CPP"
#include"../LIBS/IMGS.CPP"
int REND_INIT();
int REND_CLEN();
int REND_SHOW();
class REND
{
public:
         int NUMS;
         int NOWN;
         SDP POST[ 16];
         STP RANK[ 16];
        FKYP MAPS[128];
        TYPE FKNR[6][4];
        READ TEMP;
        IMGS BIRD;
             REND();
        void EXEC()
        {
            for(int LOOP=1;LOOP<=TEMP.LENS;LOOP++)
            {
                if(MAPS[LOOP].NOWH>=750)MAPS[LOOP].FXBZ=-1;
                if(MAPS[LOOP].NOWH<=450)MAPS[LOOP].FXBZ= 1;
                MAPS[LOOP].NOWH+=FKNR[MAPS[LOOP].TYPE/10][MAPS[LOOP].TYPE%10].SPEE*MAPS[LOOP].FXBZ;

            }
            //BIRD.SETP(POST[NOWN].x+12,POST[NOWN].y-57,71,57);
            BIRD.SETP(POST[1].x+12,POST[1].y-57,71,57);
            if(NOWN==TEMP.LENS) exit(0);
        }
        void INIT (int NUMS)
        {
            BIRD.SETP("BIRD",01,440,000,71,57);
            TEMP.SETP("MAPS","MAP","GAME",NUMS,2);
            for(int LOOP_A= 0;
                    LOOP_A<=5;LOOP_A++)
                for(int LOOP_B=1;LOOP_B<=3;LOOP_B++)
                    FKNR[LOOP_A][LOOP_B].SETP(LOOP_A*10+LOOP_B,LOOP_A*10+LOOP_B);
            for(int LOOP=1;LOOP<=TEMP.LENS;LOOP++)
            {
                MAPS[LOOP].FXBZ=1;
                MAPS[LOOP].FKID=LOOP;
                MAPS[LOOP].TYPE=TEMP.DATA[LOOP][1];
                MAPS[LOOP].NOWH=TEMP.DATA[LOOP][2];
            }
            for(int LOOP=1;LOOP<=       15;LOOP++)
            {
                POST[LOOP].x=-100+100*LOOP;                 //水平位置
                POST[LOOP].w= 81;                           //宽度大小
                POST[LOOP].h=511;                           //高度大小
            }
        }
        void SHOW ()
        {
            SDL_RenderClear(WIND_RENDP);
            int SHOW_NUMS;
            if(TEMP.LENS-NOWN+1<=15)SHOW_NUMS=TEMP.LENS-NOWN+1;
            else                    SHOW_NUMS=15;
            cout<<SHOW_NUMS<<"~"<<TEMP.LENS<<"~"<<NOWN<<endl;
            for(int LOOP=1;LOOP<= SHOW_NUMS;LOOP++)
            {
                POST[LOOP].y=MAPS[LOOP+NOWN-1].NOWH;            //垂直位置
                if(TEMP.LENS<=15)
                RANK[LOOP]=FKNR[MAPS[LOOP+NOWN-1].TYPE/10]
                               [MAPS[LOOP+NOWN-1].TYPE%10].DATA;//图像拷贝

            }
            for(int LOOP=1; LOOP<=  SHOW_NUMS;LOOP++)
            {
                SDL_RenderCopy(WIND_RENDP, RANK[LOOP], nullptr, &POST[LOOP]);
            }
            BIRD.SHOW();
            SDL_RenderPresent(WIND_RENDP);
        }
};

REND::REND()
{
    NOWN=1;
}
#endif
