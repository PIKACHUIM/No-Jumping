#pragma once
#ifndef TYPE_H
#define TYPE_H

#include"../EXTL/HEAD.CPP"
#include"../LIBS/IMGS.CPP"
/*----TYPE----
 * 存储某个类型的方块的图像和速度
 */
static const int    TYPE_SPEED   [6][4] = { 0, 0, 0, 1,
                                            0, 1, 2, 3,
                                            0, 2, 3, 4,
                                            0, 3, 4, 5,
                                            0, 4, 5, 6,
                                            0, 5, 6, 7};
class TYPE
{
public:
    STP DATA;
    int          SPEE;
    void SETP(int ,int );
         TYPE();
};

TYPE::TYPE(){};
void TYPE::SETP(int TYPE_NUMS,int TYPE_SPEE)
{
    string TYPE_FILE="";
    if(TYPE_NUMS<=9) TYPE_FILE="PNG_FKYP_0"+to_string(TYPE_NUMS)+".PNG";
    else             TYPE_FILE="PNG_FKYP_" +to_string(TYPE_NUMS)+".PNG";
  DATA=IMGS_LOAD(    TYPE_FILE, WIND_RENDP);
  SPEE=TYPE_SPEED[TYPE_SPEE/10][(TYPE_SPEE%10)];
}

#endif
