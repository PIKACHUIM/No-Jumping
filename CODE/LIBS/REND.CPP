#pragma once
#ifndef REND_CPP
#define REND_CPP
#include"REND.HPP"

int REND_INIT()
{
    WIND_RENDP = SDL_CreateRenderer(WIND_WINDP,     //创建渲染
                                    -1,             //选择显卡
                                    DBUG_GUPMD);    //显卡加速
                          DBUG_OUTP(WIND_RENDP,     //调试输出
                                  " LOAD_RENDER",   //执行内容
                                   "WIND_RENDP");   //执行指针
                    SDL_RenderClear(WIND_RENDP);    //清空渲染
    return 0;
}
int REND_CLEN()
{
    SDL_RenderClear(WIND_RENDP);
    return 0;
}
int REND_SHOW()
{
  SDL_RenderPresent(WIND_RENDP);
    return 0;
}
#endif
