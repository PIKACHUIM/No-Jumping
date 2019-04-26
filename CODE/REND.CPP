#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
int REND_INIT()
{
    WIND_RENDP = SDL_CreateRenderer(WIND_WINDP,     //创建渲染
                            -1,
                            SDL_RENDERER_ACCELERATED
                          | SDL_RENDERER_PRESENTVSYNC
                            );
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
