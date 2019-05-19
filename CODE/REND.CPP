#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
#include "REND.HPP"
REND::REND()
{
    for(int LOOP_TMPS=1;LOOP_TMPS<=15;LOOP_TMPS++)
    {
      POST[LOOP_TMPS].x=-100+100*LOOP_TMPS;
      POST[LOOP_TMPS].y= 380+ 20*LOOP_TMPS;
      POST[LOOP_TMPS].w= 81;
      POST[LOOP_TMPS].h= 511;
    }
}
void REND::SHOW()
{
    for(int LOOP_TMPS=1;LOOP_TMPS<=15;LOOP_TMPS++)
    {
       //SDL_RenderCopy(WIND_RENDP, FKYP[(DATA-DATA%10)/10][DATA%10], nullptr, &POST[LOOP_TMPS]);
    }

}
int REND_INIT()
{
    WIND_RENDP = SDL_CreateRenderer(WIND_WINDP,     //创建渲染
                                    -1,
                                    DBUG_GUPMD);    //显卡加速
                          DBUG_OUTP(WIND_RENDP," LOAD_RENDER","WIND_RENDP");
                    SDL_RenderClear(WIND_RENDP);
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
