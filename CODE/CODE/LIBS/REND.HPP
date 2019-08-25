#pragma once
#ifndef REND_HPP
#define REND_HPP

#include"../EXTL/HEAD.CPP"
#include"../EXTL/DBUG.CPP"
#include"../LIBS/FKYP.CPP"
#include"../LIBS/READ.CPP"
#include"../LIBS/TYPE.CPP"
#include"../LIBS/IMGS.CPP"
/*----REND------
 * 队列渲染核心模块
 */
  int REND_INIT();
  int REND_CLEN();
  int REND_SHOW();
class REND
{
public:
         int NUMS;        //队列总长
         int NOWN;        //渲染偏移
         int BIRP;        //小鸟偏移
         int MAXL;        //队列长度
         SDP POST[16];    //队列位置
         STP RANK[16];    //队列图像
        IMGS BIRD;        //小鸟图像
        IMGS BGMT[5];     //背景图像
        FKYP MAPS[128];   //关卡地图
        TYPE FKNR[6][4];  //图片存储
        READ TEMP;        //关卡配置
        READ BGMF;        //地图配置
             REND();
         int EXEC();
        void INIT(int);
        void SHOW();
};
#endif
