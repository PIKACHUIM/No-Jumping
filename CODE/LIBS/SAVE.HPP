#pragma once

#include<iostream>
#include<cstring>
#include"./READ.CPP"
#include"./CGGQ.HPP"
using namespace std;

class SAVE
{
public:
    int DAPX[41];          //存取时间（整数）ms
    int DASX[41];          //存取数据等级部分
    int DARX[41][4];       //判断关卡等级部分
    SAVE();
    CGGQ LOAD(int);
    bool PDDP(int, int);
    void EXPO(int, int);
    void WRIT(void);
    READ SAVE_READ;
};

SAVE::SAVE()
{
    SAVE_READ.SETP("MAPS", "DAT", "SAVE", 00, 05);
    for (int LOOP_A = 1;LOOP_A <= 40;LOOP_A++)
    {
        DARX[LOOP_A][1] = SAVE_READ.DATA[LOOP_A][1];
        DARX[LOOP_A][2] = SAVE_READ.DATA[LOOP_A][2];
        DARX[LOOP_A][3] = SAVE_READ.DATA[LOOP_A][3];
        DASX[LOOP_A] = SAVE_READ.DATA[LOOP_A][4];
        DAPX[LOOP_A] = SAVE_READ.DATA[LOOP_A][5];
    }
}
CGGQ SAVE::LOAD(int NUMS)
{
    CGGQ TEMP;
    TEMP.CGID = NUMS;
    TEMP.CGLV = DASX[NUMS];
    TEMP.CGTM = DAPX[NUMS];
    return TEMP;
}

bool SAVE::PDDP(int NUMS, int TIMES)
{
    return TIMES > DAPX[NUMS];
}

void SAVE::EXPO(int NUMS, int TIMES)    //用户的时间存取
{
    DAPX[NUMS] = TIMES;
    if (DAPX[NUMS] <= DARX[NUMS][3])
    {
        DASX[NUMS] = 3;
    }
    else
    {
        if (DAPX[NUMS] <= DARX[NUMS][2])
        {
            DASX[NUMS] = 2;
        }
        else
        {
            if (DAPX[NUMS] <= DARX[NUMS][1])
            {
                DASX[NUMS] = 1;
            }
            else
            {
                DASX[NUMS] = 0;
            }
        }
    }
}

void SAVE::WRIT(void)
{
    for (int LOOP_A = 1;LOOP_A <= 40;LOOP_A++)
    {
        SAVE_READ.DATA[LOOP_A][1]=DARX[LOOP_A][1];
        SAVE_READ.DATA[LOOP_A][2]=DARX[LOOP_A][2];
        SAVE_READ.DATA[LOOP_A][3]=DARX[LOOP_A][3];
        SAVE_READ.DATA[LOOP_A][4]=DASX[LOOP_A];
        SAVE_READ.DATA[LOOP_A][5]=DAPX[LOOP_A];
    }
    SAVE_READ.WRIT();
}
