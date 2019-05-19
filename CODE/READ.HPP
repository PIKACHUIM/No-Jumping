#ifndef READ_HPP
#define READ_HPP
#include "DBUG.CPP"
#include "HEAD.CPP"
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
class READ
{
public:
    int LENS;
    int DATA[1024][6];
    READ(string READ_LEVE,string READ_TYPE,string READ_NAME,int READ_NUMS)
    {
                   FILE* READ_TEMP;
                  string READ_PATH;
        if(READ_NUMS<=9) READ_PATH ="../"+READ_LEVE+"/"+READ_TYPE+"_"+READ_NAME+"_"+"0"+std::to_string(READ_NUMS)+".INI";
        else             READ_PATH ="../"+READ_LEVE+"/"+READ_TYPE+"_"+READ_NAME+"_"+    std::to_string(READ_NUMS)+".INI";
             const char* READ_OPEN = READ_PATH.c_str();
                         READ_TEMP = fopen(READ_OPEN, "r");
                     int READ_LOOP = 0;
                  fscanf(READ_TEMP,"%d",&READ_LOOP); //读取
                    LENS=READ_LOOP;
                 for(int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++)
                 for(int LOOP_TEMP=0;LOOP_TEMP<=5;LOOP_TEMP++)
                    {
                        fscanf(READ_TEMP,"%d",&DATA[READ_LOOP][LOOP_TEMP]);
                        fseek(READ_TEMP, 0, SEEK_CUR);
                    }
                 DBUG_OUTP(READ_TEMP," LOAD_CONFIG",READ_PATH);
    }
};

#endif // READ_HPP
