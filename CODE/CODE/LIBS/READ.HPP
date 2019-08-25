#pragma once
#ifndef READ_HPP
#define READ_HPP
#include"../EXTL/HEAD.CPP"
#include"../EXTL/DBUG.CPP"
#include<stdio.h>
/*---READ类
 * 负责底层文件调用，读写
 */
class READ
{
public:
     int LENS;
     int DATA[1024][6];
  string DIRN;
  string FILC;
  string FILN;
     int NUMS;
     int DATL;
         READ(){}
         READ(string,string,string,int,int);
    void SETP(string,string,string,int,int);
    void WRIT();
};

#endif // READ_HPP
