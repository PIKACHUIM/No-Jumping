#pragma once
#ifndef CGMS_CPP
#define CGMS_CPP

#include "LIBS/READ.CPP"
#include "LIBS/FKYP.CPP"
#include "LIBS/TYPE.CPP"
#include "LIBS/REND.CPP"
#include "LIBS/FONT.CPP"
#include "LIBS/SAVE.CPP"
#include "EXTL/WIND.CPP"
#include "EXTL/DBUG.CPP"
class CGMS
{
public:
   REND GAME_REND;       //渲染队列
   READ CGMS_PACN;       //过关背景
   READ CGMS_FACN;       //失败背景
   READ CGMS_PAMG;       //过关按钮
   FONT CGMS_TIME;       //时间文字
   FONT CGMS_OUTT;       //星级文字
   SAVE CGMS_SAVE;       //数据存档
    int LAST_TIME;       //上次时间
    int NOWN_TIME;       //当前时间
    int TOTA_TIME;       //总共时间
    int GAME_NUMS;       //游戏编号
    int CGMS_PART;       //回调参数
    int CGMS_GMPA[16][5];//通关图像
    int CGMS_GMFA[16][5];//失败图像
int CGMS_PDAN(int ix,int iy,int FTTL[16][5],int LTNS)//-----------------判断鼠标点击范围-----------------
{
    for(int LOOP=1;LOOP<=LTNS;LOOP++){              //如果在范围内，返回对应数组偏移量，对应CONF配置序列中的ID
            int PDSJ_FLAG=0;
            if(ix<FTTL[LOOP][1]||ix>FTTL[LOOP][2])  //横坐标
                PDSJ_FLAG=1;
            if(iy<FTTL[LOOP][3]||iy>FTTL[LOOP][4])  //纵坐标
                PDSJ_FLAG=1;
            if(PDSJ_FLAG==0)
                return LOOP;}
    return 0;
}
int CGMS_INIT(int CGMS_NUMS)                         //------------------初始化游戏内容------------------
    {
        //------------------配置复制:按键检测------------------------
            CGMS_PACN.SETP("CONF","POS","CGMS",01,4);
            CGMS_FACN.SETP("CONF","POS","CGMS",02,4);
            CGMS_PAMG.SETP("MAPS","MAP","PASS",00,05);
            for(int LOOP=1;LOOP<=CGMS_PACN.LENS;LOOP++)
            for(int LTMP=1;LTMP<=4;LTMP++)
                CGMS_GMPA[LOOP][LTMP]=CGMS_PACN.DATA[LOOP][LTMP];
                CGMS_GMPA[   0][   0]=CGMS_PACN.LENS;
            for(int LOOP=1;LOOP<=CGMS_FACN.LENS;LOOP++)
            for(int LTMP=1;LTMP<=4;LTMP++)
                CGMS_GMFA[LOOP][LTMP]=CGMS_FACN.DATA[LOOP][LTMP];
                CGMS_GMFA[   0][   0]=CGMS_FACN.LENS;
        //---------------------------------------------------------
        GAME_REND.INIT(CGMS_NUMS);
        LAST_TIME=(int)SDL_GetTicks();
        NOWN_TIME=(int)SDL_GetTicks();
        GAME_NUMS=CGMS_NUMS;
        TOTA_TIME=0;
        CGMS_TIME.SETP(255,255,255, 80, 50,100,50,(char*)"0.00"  ,72);
        CGMS_OUTT.SETP(255,255,255,750,350, 80,40,(char*)"9.99\"",72);
        return 0;
    }
//----------------------------闯关成功界面实现----------------------------
int CGMS_PASS()
{
    SDE  CGMA_PASS_EVEN;                             //创建事件
    int  CGMS_PASS_FLAG=1;                           //循环标识符
         IMGS CGMS_PASS_IGPA[16];                    //菜单图像
         IMGS CGMS_PASS_STAR[4];                     //三颗星图像
         CGMA_PASS_EVEN.type=SDL_KEYDOWN;            //初始化事件
         CGMS_TIME.SETP(1,200,100);                  //显示时间TTF大小重写
         CGMS_TIME.SETP(0,650,150);                  //显示时间TTF位置重写
    int  CGMS_PASS_SNUM=                             //获取等级
         CGMS_SAVE.EXPO(GAME_NUMS-9,TOTA_TIME);
    if(CGMS_PASS_SNUM>CGMS_SAVE.DASX[GAME_NUMS-9]){  //等级打破纪录
        CGMS_SAVE.DASX[GAME_NUMS-9]=CGMS_PASS_SNUM;  //更新等级
        CGMS_SAVE.WRIT();}                           //数据存盘
    if(CGMS_SAVE.PDDP(GAME_NUMS-9,TOTA_TIME)==true){ //时间打破纪录
        CGMS_SAVE.DAPX[GAME_NUMS-9]=TOTA_TIME;       //更新时间
        CGMS_SAVE.WRIT();}                           //数据存盘
    for (int LOOP=1;LOOP<=             3;LOOP++)     //载入星星
             CGMS_PASS_STAR[LOOP].SETP("STAR",
                 00,548+LOOP*73,279,57,54);
    for (int LOOP=1;LOOP<=CGMS_PAMG.LENS;LOOP++)     //载入背景
             CGMS_PASS_IGPA[LOOP].SETP("MENU",       //编号
                 CGMS_PAMG.DATA[LOOP][1],            //类型
                 CGMS_PAMG.DATA[LOOP][2],            //水平
                 CGMS_PAMG.DATA[LOOP][3],            //垂直
                 CGMS_PAMG.DATA[LOOP][4],            //宽度
                 CGMS_PAMG.DATA[LOOP][5]);           //高度
    while(CGMS_PASS_FLAG)//--------------------CGMS_PASS主体循环---------------------
    {
    STR STRS_TEMP;                                                         //三星时间
    STR STTM_TEMP;                                                         //实际时间
        REND_CLEN();                                                       //清空渲染
        for (int LOOP=1;LOOP<=CGMS_PAMG.LENS;LOOP++)                       //显示背景
              CGMS_PASS_IGPA[LOOP].SHOW();
        if(CGMS_PASS_SNUM>0)
        for (int LOOP=1;LOOP<=CGMS_PASS_SNUM;LOOP++)                       //显示星级
              CGMS_PASS_STAR[LOOP].SHOW();
        STRS_TEMP =to_string(TOTA_TIME/1000)+                              //时间字体
        STTM_TEMP =to_string(CGMS_SAVE.DARX[GAME_NUMS-9][3]/1000)          //三星字体
              +"."+to_string(CGMS_SAVE.DARX[GAME_NUMS-9][3]%1000/10)+"\"";
        CGMS_TIME.SETP((char*)STRS_TEMP.c_str());                          //设置时间
        CGMS_OUTT.SETP((char*)STTM_TEMP.c_str());                          //设置三星
        CGMS_OUTT.SHOW();                                                  //显示三星
        CGMS_TIME.SHOW();                                                  //显示时间
        REND_SHOW();
        while (SDL_PollEvent(&CGMA_PASS_EVEN))//------------事件处理循环--------------
        {
            if(CGMA_PASS_EVEN.type==SDL_QUIT){
                CGMS_PASS_FLAG=0;
                WIND_EXIT();}                              //退出程序
            if(CGMA_PASS_EVEN.type==SDL_MOUSEBUTTONUP){    //按下鼠标
            int CGMS_ANPA=
                CGMS_PDAN(CGMA_PASS_EVEN.button.x,         //鼠标-Y轴
                          CGMA_PASS_EVEN.button.y,         //鼠标-X轴
                          CGMS_GMPA,                       //传入数组
                          CGMS_GMPA[0][0]);                //区域长度
                if(CGMS_ANPA==0){CGMS_ANPA=-1;break;}      //无效点击
                else{
                    CGMS_PART=CGMS_ANPA;                   //回传参数
                    return CGMS_ANPA;}}
          }
     }//-----------------------------------------------------------------------------
     return 0;
}

int CGMS_FAIL(int DQJD)
    {
        SDE  CGMS_FAIL_EVEN;
        while (SDL_PollEvent(&CGMS_FAIL_EVEN))
        CGMS_FAIL_EVEN.type=SDL_KEYUP;
        IMGS FAIM[7];
        FAIM[1].SETP("FAIL",01,560,580,457,175);
        FAIM[2].SETP("FAIL",02,780,650,197, 85);
        FAIM[3].SETP("FAIL",03,575+DQJD,590, 23, 22);
        FAIM[4].SETP("MENU",12,590,650, 85, 85);
        FAIM[5].SETP("MENU",13,685,650, 85, 85);
        FAIM[6].SETP("MENU",21,640,150,300,150);
        while(CGMS_FAIL_EVEN.type!=SDL_QUIT)
       {

            for(int LOOP=1;LOOP<=6;LOOP++) FAIM[LOOP].SHOW();
            REND_SHOW();
            while (SDL_PollEvent(&CGMS_FAIL_EVEN))
            {
                if(CGMS_FAIL_EVEN.type==SDL_QUIT)
                {
                    WIND_EXIT();                                 //关闭窗口
                    break;
                }
                if(CGMS_FAIL_EVEN.type==SDL_MOUSEBUTTONUP)
                {
                CGMS_FAIL_EVEN.type=SDL_KEYUP;
                int CGMS_ANPA=
                    CGMS_PDAN(CGMS_FAIL_EVEN.button.x,
                              CGMS_FAIL_EVEN.button.y,
                              CGMS_GMFA,
                              CGMS_GMFA[0][0]);                  //关卡界面
                    if(CGMS_ANPA==0)
                    {
                            CGMS_ANPA=-1;
                            break;
                    }
                    else
                    {
                            CGMS_PART=CGMS_ANPA;
                            return CGMS_ANPA;
                    }
                  }

            }
       }
        return 0;
    }

int CGMS_SHOW()
    {
       int SHOW_TEMP;
       STR STRS_TEMP;
       int RTEN=GAME_REND.EXEC();
                GAME_REND.SHOW();
                CGMS_TIME.SHOW();

        if(RTEN== 0)//过关
        {
            SHOW_TEMP=CGMS_PASS();
            return SHOW_TEMP;
        }
        if(RTEN== 1)//计时
        {
            NOWN_TIME =SDL_GetTicks();
            if(NOWN_TIME-LAST_TIME>10)
            {
                TOTA_TIME+=NOWN_TIME-LAST_TIME;
                LAST_TIME =NOWN_TIME;
            }
            if(DBUG_OTIME==1)
            {
                cout<<" [CGMS] ";
                DBUG_GTIM();
                cout<<"0x"<<WIND_RENDP<<" "<<"GAME_PROEXE: "<<"~~|GAME|NOW_TIME_IS:";
                printf("%6.2f\n",(float)TOTA_TIME/1000);
            }
        }
        if(RTEN==-1)//暂停
        {
            NOWN_TIME =SDL_GetTicks();
            LAST_TIME =NOWN_TIME;
        }
        STRS_TEMP =to_string(TOTA_TIME/1000)+"."+to_string(TOTA_TIME%1000/10);
        CGMS_TIME.SETP((char*)STRS_TEMP.c_str());
        CGMS_TIME.SHOW();
        REND_SHOW();
        return 0;
}
int CGMS_NEXT()
    {
    if(DBUG_OTSTP==1)
    {
        cout<<" [NEXT] ";
        DBUG_GTIM();
        cout<<"0x"<<WIND_RENDP
            <<" "<<"NEXT_BIRDNS: "
            <<"~~|BIRD|NOW_BIRD_AT:"
            <<GAME_REND.NOWN+GAME_REND.BIRP
            <<endl;
    }

        if(
           GAME_REND.MAPS[GAME_REND.NOWN+GAME_REND.BIRP-1].NOWH>
           GAME_REND.MAPS[GAME_REND.NOWN+GAME_REND.BIRP  ].NOWH+10)
            return 1;
        if(  GAME_REND.BIRP<=7
           ||GAME_REND.TEMP.LENS-
            (GAME_REND.NOWN+
             GAME_REND.BIRP)<=6)
             GAME_REND.BIRP++;
        else GAME_REND.NOWN=GAME_REND.NOWN+1;
        return 0;
    }
int CGMS_DEAL()
{
    int DEAL_EXIT=1;
    int DEAL_CGRT;
    SDE DEAL_EVEN;
    while(DEAL_EXIT)
    {
        while (SDL_PollEvent(&DEAL_EVEN))
        {
            if(DEAL_EVEN.type==SDL_QUIT)WIND_EXIT();            //关闭窗口
            if(DEAL_EVEN.type==SDL_MOUSEBUTTONDOWN
             ||DEAL_EVEN.type==SDL_KEYDOWN)
                {
                if(CGMS_NEXT()==1&&DBUG_NOKIL == 0){
                        DEAL_CGRT = CGMS_FAIL((int)
                                    (GAME_REND.NOWN+
                                     GAME_REND.BIRP)
                                    /GAME_REND.TEMP.LENS*350);  //小鸟相撞
                    if(DEAL_CGRT==3){
                        TOTA_TIME=0;
                        int LOOP=GAME_REND.NOWN+GAME_REND.BIRP-1;
                        for(;LOOP>=2&&GAME_REND.MAPS[LOOP].TYPE>10;LOOP--);
                        GAME_REND.BIRP=1;
                        GAME_REND.NOWN=LOOP;}
                        else return DEAL_CGRT;}
                }
            }
            DEAL_CGRT =  CGMS_SHOW();
            if (DEAL_CGRT!=0)return DEAL_CGRT;
            SDL_Delay(16);
        }
        return 0;
    }
};

#endif
