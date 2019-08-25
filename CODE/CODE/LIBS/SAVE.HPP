#pragma once
#ifndef SAVE_HPP
#define SAVE_HPP

#include<iostream>
#include<cstring>
#include"./READ.CPP"
#include"./CGGQ.CPP"
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
};

#endif
