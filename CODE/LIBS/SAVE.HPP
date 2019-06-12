#pragma once

#include<iostream>
#include<cstring>
#include"./READ.CPP"
#include"./CGGQ.HPP"
using namespace std;
/*----SAVE----
 * 负责调用READ进行玩家数据存储
 */
class SAVE
{
public:
    int DAPX[41];          //存取时间
    int DASX[41];          //存取等级
    int DARX[41][4];       //判断等级
    int DATX[6];
    READ SAVE_READ;
    int  EXPO(int, int);
	bool PDDP(int, int);
    void WRIT();
    CGGQ LOAD(int);
    void INIT();
         SAVE();
    //SAVE_READ.DATA[41]:1三星，2三星，3三星，4三星，总三星
};
void SAVE::INIT()
{
    SAVE_READ.SETP("CONF", "DAT", "SAVE", 00, 05);
    for (int LOOP_A = 1;LOOP_A <= 40;LOOP_A++)
    {
        DARX[LOOP_A][1] = SAVE_READ.DATA[LOOP_A][1];
        DARX[LOOP_A][2] = SAVE_READ.DATA[LOOP_A][2];
        DARX[LOOP_A][3] = SAVE_READ.DATA[LOOP_A][3];
        DASX[LOOP_A]    = SAVE_READ.DATA[LOOP_A][4];
        DAPX[LOOP_A]    = SAVE_READ.DATA[LOOP_A][5];
    }
    for (int LOOP_A = 1;LOOP_A <= 5;LOOP_A++)
        DATX[LOOP_A]=SAVE_READ.DATA[41][LOOP_A];
}
SAVE::SAVE()
{
    this->INIT();
}
CGGQ SAVE::LOAD(int NUMS)
{
	CGGQ TEMP;
	TEMP.CGID = NUMS;
	TEMP.CGLV = DASX[NUMS];
	TEMP.CGTM = DAPX[NUMS];
	return TEMP;
}

bool SAVE::PDDP(int NUMS, int TIMES)    //打破记录判定
{
    return TIMES < DAPX[NUMS];
}
int  SAVE::EXPO(int NUMS, int TIMES)    //游戏星级评定
{
    int EXPO_TEMP;
    if (TIMES <= DARX[NUMS][3])
                 EXPO_TEMP = 3;
	else
    {
        if (TIMES <= DARX[NUMS][2])
                 EXPO_TEMP = 2;
		else
        {
            if (TIMES <= DARX[NUMS][1])
                 EXPO_TEMP = 1;
            else EXPO_TEMP = 0;
        }
    }
    return EXPO_TEMP;
}

void SAVE::WRIT()
{
	for (int LOOP_A = 1;LOOP_A <= 40;LOOP_A++)
	{
        for(int LOOP_B = 1;LOOP_B <= 3;LOOP_B++)
        SAVE_READ.DATA[LOOP_A][LOOP_B]=DARX[LOOP_A][LOOP_B];
        SAVE_READ.DATA[LOOP_A][     4]=DASX[LOOP_A];
        SAVE_READ.DATA[LOOP_A][     5]=DAPX[LOOP_A];
	}
    for (int LOOP_A = 1;LOOP_A <= 4;LOOP_A++)
    {
            SAVE_READ.DATA[41][LOOP_A] = 3;
    for (int LOOP_B = 1;LOOP_B <=40;LOOP_B++)
            SAVE_READ.DATA[41][LOOP_A]+=DASX[LOOP_B];
        cout<<SAVE_READ.DATA[41][1];
    }
    SAVE_READ.WRIT();
    this->INIT();
}
