#pragma once
#ifndef READ_HPP
#define READ_HPP
#include"../EXTL/HEAD.CPP"
#include"../EXTL/DBUG.CPP"
#include<stdio.h>
class READ
{
public:
     int LENS;
     int DATA[1024][6];
         READ(){}
         READ(string,string,string,int,int);
    void SETP(string,string,string,int,int);
};
READ::READ(string READ_LEVE,string READ_TYPE,string READ_NAME,int READ_NUMS,int READ_LENS)
{
    SETP(READ_LEVE,READ_TYPE,READ_NAME,READ_NUMS,READ_LENS);
}
void READ::SETP(string READ_LEVE,string READ_TYPE,string READ_NAME,int READ_NUMS,int READ_LENS)
{
               FILE* READ_TEMP;
             errno_t READ_ERRO;
              string READ_PATH;
    if(READ_NUMS<=9) READ_PATH ="../"+READ_LEVE+"/"+READ_TYPE+"_"+READ_NAME+"_"+"0"+std::to_string(READ_NUMS)+".INI";
    else             READ_PATH ="../"+READ_LEVE+"/"+READ_TYPE+"_"+READ_NAME+"_"+    std::to_string(READ_NUMS)+".INI";
         const char* READ_OPEN = READ_PATH.c_str();
                     READ_ERRO = fopen_s(&READ_TEMP,READ_OPEN, "r");
                 int READ_LOOP = 0;
            fscanf_s(READ_TEMP,"%d",&READ_LOOP); //读取
                LENS=READ_LOOP;
             for(int READ_LOOP=1;READ_LOOP<=LENS;READ_LOOP++)
             for(int LOOP_TEMP=0;LOOP_TEMP<=READ_LENS;LOOP_TEMP++)
                {
                 fscanf_s(READ_TEMP,"%d",&DATA[READ_LOOP][LOOP_TEMP]);
                    fseek(READ_TEMP, 0, SEEK_CUR);
                }
             DBUG_OUTP(READ_TEMP," LOAD_CONFIG",READ_PATH);
}
#endif // READ_HPP
