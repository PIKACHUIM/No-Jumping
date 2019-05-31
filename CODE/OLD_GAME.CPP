#pragma once
#ifndef GAME_CPP
#define GAME_CPP

#include "LIBS/READ.CPP"
#include "LIBS/FKYP.CPP"
#include "LIBS/TYPE.CPP"
#include "LIBS/REND.CPP"
READ GAME_READ;
FKYP GAME_FKDX[128];
TYPE GAME_TYPE[6][4];
REND GAME_REND;
int GAME_INIT(int GAME_NUMS)
{
    GAME_READ.SETP("MAPS","MAP","GAME",01,GAME_NUMS);                     //读取方块文件
    for(int LOOP_A= 0,LOOP_T=1;LOOP_A<=5;LOOP_A++,LOOP_T++)               //初始化方块类
        for(int LOOP_B=1;LOOP_B<=3;LOOP_B++)
            GAME_TYPE[LOOP_A][LOOP_B].SETP(LOOP_A*10+LOOP_B,LOOP_T);
    GAME_REND.NUMS=GAME_READ.LENS;
    for(int LOOP_A=1;LOOP_A<=GAME_REND.NUMS;LOOP_A++)
    {
        GAME_FKDX[LOOP_A].FKID=GAME_READ.DATA[LOOP_A][0];
        GAME_FKDX[LOOP_A].TYPE=GAME_READ.DATA[LOOP_A][1];
        GAME_FKDX[LOOP_A].NOWH=GAME_READ.DATA[LOOP_A][2];
    }
    for(int LOOP_A=1;LOOP_A<=15;LOOP_A++)
    {
    }
    return 0;
}

#endif
