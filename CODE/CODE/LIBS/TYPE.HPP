#pragma once
#ifndef TYPE_HPP
#define TYPE_HPP

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
    STP DATA;             //存储图形
    int          SPEE;    //变化速率
    void SETP(int ,int ); //重写数值
         TYPE();
};
#endif
