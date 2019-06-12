#pragma once
#ifndef FKYP_HPP
#define FKYP_HPP
/*---FKYP类
 * 存储某一个方块的参数
 */
class FKYP
{
public:
    int  FKID;//方块编号
    int  TYPE;//方块类型
    int  NOWH;//方块高度
    int  FXBZ;//方块方向
    FKYP(){}
    FKYP(int FKYP_FKID,int FKYP_TYPE,int FKYP_NOWH)
    {
        FKID=FKYP_FKID;
        TYPE=FKYP_TYPE;
        NOWH=FKYP_NOWH;
    }
};
#endif
