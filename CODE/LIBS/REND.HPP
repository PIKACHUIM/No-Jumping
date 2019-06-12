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
        REND()
        {
            NOWN=1;       //初始化队列偏移量
            BIRP=1;       //初始化小鸟偏移量
        }
       int EXEC()
        {
            for(int LOOP=1;LOOP<=TEMP.LENS;LOOP++)
            {
                if(MAPS[LOOP].NOWH>=750)MAPS[LOOP].FXBZ=-1;   //方向向上
                if(MAPS[LOOP].NOWH<=450)MAPS[LOOP].FXBZ= 1;   //方向向下
                   MAPS[LOOP].NOWH+=
                           FKNR[MAPS[LOOP].TYPE/10]
                               [MAPS[LOOP].TYPE%10]
                          .SPEE*MAPS[LOOP].FXBZ;              //计算位移
            }
            BIRD.SETP(POST[BIRP].x+12,POST[BIRP].y-57,71,57); //绑定小鸟
            if(NOWN+BIRP-1==TEMP.LENS)                        //游戏结束
                return  0;
            if(MAPS[NOWN+BIRP-1].TYPE<=10)                    //暂停方块
                return -1;
           else return  1;                                    //正常计时
        }
        void INIT (int NUMS)
        {
            BIRD.SETP("BIRD",01,440,000,71,57);               //读取小鸟图像
            TEMP.SETP("MAPS","MAP","GAME",NUMS,2);            //读取队列配置
            BGMF.SETP("MAPS","MAP","GMRT",  00,5);            //读取背景配置
            for(int LOOP_A=0;LOOP_A<=5;LOOP_A++)              //生成图像类型
            for(int LOOP_B=1;LOOP_B<=3;LOOP_B++)
                    FKNR[LOOP_A][LOOP_B]
                   .SETP(LOOP_A*10+LOOP_B,
                         LOOP_A*10+LOOP_B);
            for(int LOOP=1;LOOP<=TEMP.LENS;LOOP++){           //读取地图数据
                MAPS[LOOP].FXBZ=1;                            //方向
                MAPS[LOOP].FKID=LOOP;                         //编号
                MAPS[LOOP].TYPE=TEMP.DATA[LOOP][1];           //类型
                MAPS[LOOP].NOWH=TEMP.DATA[LOOP][2];}          //位置
            for(int LOOP=1;LOOP<=       15;LOOP++){           //写入队列位置
                POST[LOOP].x=-100+100*LOOP;                   //水平位置
                POST[LOOP].w= 81;                             //宽度大小
                POST[LOOP].h=511;}                            //高度大小
            for(int LOOP=1;LOOP<=        4;LOOP++){           //写入背景图像
                BGMT[LOOP].SETP("MENU",                       //图片名称
                                BGMF.DATA[LOOP][1],           //图片编号
                                BGMF.DATA[LOOP][2],           //水平位置
                                BGMF.DATA[LOOP][3],           //垂直位置
                                BGMF.DATA[LOOP][4],           //水平大小
                                BGMF.DATA[LOOP][5]);}         //垂直大小
        }
        void SHOW ()
        {
            SDL_RenderClear(WIND_RENDP);                    //清空上次渲染
            if(TEMP.LENS-NOWN+1<=15)MAXL=TEMP.LENS-NOWN+1;  //设置队列长度
            else                    MAXL=15;                //最大长度为15
            for(int LOOP=1;LOOP<=4;LOOP++)BGMT[LOOP].SHOW();//执行背景渲染
            for(int LOOP=1;LOOP<= MAXL;LOOP++){             //更新渲染队列
                POST[LOOP].y=MAPS[LOOP+NOWN-1].NOWH;        //拷贝垂直位置
                RANK[LOOP]  =FKNR                           //拷贝队列图像
                        [MAPS[LOOP+NOWN-1].TYPE/10]         //大关卡
                        [MAPS[LOOP+NOWN-1].TYPE%10].DATA;}  //小关卡
            for(int LOOP=1; LOOP<=  MAXL;LOOP++){           //执行队列渲染
                SDL_RenderCopy(WIND_RENDP,                  //设置指针
                               RANK[LOOP],                  //图像数据
                                  nullptr,                  //缩放大小
                              &POST[LOOP]);}                //图像位置
            BIRD.SHOW();                                    //渲染小鸟
        }
};
#endif
