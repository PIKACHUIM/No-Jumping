#pragma once
#ifndef MENU_CPP
#define MENU_CPP
#include"LIBS/IMGS.CPP"
#include"LIBS/READ.CPP"
#include"LIBS/TYPE.CPP"
#include"LIBS/REND.CPP"
#include"LIBS/TYPE.CPP"
#include"EXTL/WIND.CPP"
#include"EXTL/HEAD.CPP"
#include"YXXY.CPP"
static IMGS      MENU_FKYPS[15];                         //创建主菜单方块
static IMGS      MENU_MENUS[ 8];                         //创建主菜单控件
static READ      MENU_LOADS("MAPS","MAP","MENU",1,5);    //读取主菜单配置
static IMGS      MENU_BIRDS;                             //创建主菜单小鸟
static double    TIME_LAST = SDL_GetTicks();
static double    TIME_LOOP = SDL_GetTicks();
static int       BIRD_POTS = rand()%10+3;
static SDE       MENU_EVEN;
static TYPE      FKTP[6][4];
int MENU_INIT()
{
    for(int LOOP_A=1;LOOP_A<=7 ;LOOP_A++)        //读取菜单控件
        MENU_MENUS[LOOP_A].SETP("MENU",          //种类
                MENU_LOADS.DATA[LOOP_A][1],      //编号
                MENU_LOADS.DATA[LOOP_A][2],      //水平
                MENU_LOADS.DATA[LOOP_A][3],      //垂直
                MENU_LOADS.DATA[LOOP_A][4],      //宽度
                MENU_LOADS.DATA[LOOP_A][5]);     //高度
    for(int LOOP_T=0;LOOP_T<=14;LOOP_T++){       //设置方块状态
        MENU_FKYPS[LOOP_T].IMGS_IMGS_UPDO=1;     //向上
        MENU_FKYPS[LOOP_T].SETP("FKYP",          //种类
                   rand()%3+1+(rand()%5+1)*10,   //颜色
                               000+100*LOOP_T,   //水平
                               400+ 20*LOOP_T,   //垂直
                               81,511);}         //大小
    for(int LOOP_A= 0,LOOP_T=1;
            LOOP_A<=5;LOOP_A++,LOOP_T++)
    for(int LOOP_B=1;LOOP_B<=3;LOOP_B++)
       FKTP[LOOP_A][LOOP_B].SETP(LOOP_A*10+LOOP_B,LOOP_T);
    BIRD_POTS = rand()%10+3;
    MENU_BIRDS.SETP("BIRD",01,440,000,71,57);
    YXXY_INIT();
    return 0;

}
int MENU_UPDA(int count)
{
    if ((SDL_GetTicks() - TIME_LOOP) / 1 > 1)
    {
        for(int LOOP_TMPS=0;LOOP_TMPS<=14;LOOP_TMPS++)
        {
            if(MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_POST.y==700) MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_UPDO=-1;
            if(MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_POST.y==450) MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_UPDO= 1;
               MENU_FKYPS[LOOP_TMPS].SETP(MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_POST.x,
               MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_POST.y+MENU_FKYPS[LOOP_TMPS].IMGS_IMGS_UPDO,81,511);
        }
        TIME_LOOP = SDL_GetTicks();
    }
    if ((SDL_GetTicks() - TIME_LAST) / 1000 > 1)
    {
        DBUG_TFPS(count," RUNT_RENDER"," FPS");
        count = 0;
        TIME_LAST = SDL_GetTicks();
    }
    return 0;
}
int MENU_BIRD(int MENU_BIRD_POTS)
{
    MENU_BIRDS.SETP(
    MENU_FKYPS[MENU_BIRD_POTS].IMGS_IMGS_POST.x+12,
    MENU_FKYPS[MENU_BIRD_POTS].IMGS_IMGS_POST.y+
    MENU_FKYPS[MENU_BIRD_POTS].IMGS_IMGS_UPDO-57,
    71,57);
    return 0;
}
int MENU_PDAN(int MENU_PDAN_X,int MENU_PDAN_Y,int x1,int y1,int x2,int y2)
{
    if(MENU_PDAN_X<x1||MENU_PDAN_X>x1+x2) return 0;
    if(MENU_PDAN_Y<y1||MENU_PDAN_Y>y1+y2) return 0;
    return 1;
}
int MENU_DEAL()
{
    while (SDL_PollEvent(&MENU_EVEN))
    {
        if(MENU_EVEN.type==SDL_QUIT)
                           WIND_EXIT(); //关闭窗口
        if(MENU_EVEN.type==SDL_MOUSEBUTTONUP)
        {
            int MENU_EVENT_X=MENU_EVEN.button.x;
            int MENU_EVENT_Y=MENU_EVEN.button.y;
            if(MENU_PDAN(MENU_EVENT_X,
                         MENU_EVENT_Y,
                         452,300,
                         270,66)==1)
            {
                YXXY_INIT();
                YXXY_INFT();//闯关模式
                break;
            }
            if(MENU_PDAN(MENU_EVENT_X,
                         MENU_EVENT_Y,
                         760,300,
                         270,66)==1)
                 WIND_EXIT();   //生存模式
        }
    }
    return 0;
}
int MENU_SHOW()
{
    for(int count=1;;count++)
    {
        REND_CLEN();                    //清空渲染
        for(int LOOP_A=1;LOOP_A<=7 ;LOOP_A++)
            MENU_MENUS[LOOP_A].SHOW();  //渲染菜单
        for(int LOOP_A=0;LOOP_A<=14;LOOP_A++)
            MENU_FKYPS[LOOP_A].SHOW();  //渲染方块
        MENU_BIRD(BIRD_POTS);           //绑定小鸟
            MENU_BIRDS        .SHOW();  //渲染小鸟
        REND_SHOW();                    //执行渲染
        MENU_DEAL();                    //处理事件
        MENU_UPDA(count);               //输出帧率
    }
}
#endif
