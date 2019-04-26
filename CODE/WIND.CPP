#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"

int WIND_INIT()
{
    /*------------------------------创建窗口------------------------------*/
    if(SDL_Init(SDL_INIT_VIDEO)<0) return -1;
    WIND_WINDP=SDL_CreateWindow(WIND_TITLE,         //窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//垂直位置
                            SDL_WINDOWPOS_UNDEFINED,//水平位置
                            WIND_WIDTH,             //窗口宽度
                            WIND_HEIGH,             //窗口高度
                            SDL_WINDOW_SHOWN        //显示窗口
                            );
    DBUG_OUTP(WIND_WINDP," LOAD_WINDOW","WIND_WINDP");

    return 0;
}
int WIND_EXIT()
{
    /*------------------------------退出程序------------------------------*/
  SDL_DestroyRenderer(WIND_RENDP);                  //销毁渲染
    SDL_DestroyWindow(WIND_WINDP);                  //销毁窗口
    SDL_Quit();                                     //退出程序
    exit(0);
}

