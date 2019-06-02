#pragma once
#ifndef CGMS_CPP
#define CGMS_CPP

#include "LIBS/READ.CPP"
#include "LIBS/FKYP.CPP"
#include "LIBS/TYPE.CPP"
#include "LIBS/REND.CPP"
#include "EXTL/WIND.CPP"
class CGMS
{
public:
    REND GAME_REND;
    int CGMS_INIT(int CGMS_NUMS)
    {
        GAME_REND.INIT(CGMS_NUMS);
        return 0;
    }
    int CGMS_SHOW()
    {
        GAME_REND.EXEC();
        GAME_REND.SHOW();

        return 0;
    }
    int CGMS_DEAL()
    {
        SDL_Event CGMS_EVEN;
        bool      CGMS_FLAG=0;
        while(CGMS_EVEN.type!=SDL_QUIT)
        {
            while (SDL_PollEvent(&CGMS_EVEN))
            {
                if(CGMS_EVEN.type==SDL_QUIT)
                 WIND_EXIT(); //关闭窗口
                if(CGMS_EVEN.type==SDL_MOUSEBUTTONUP)
                {
                        GAME_REND.NOWN=GAME_REND.NOWN+1;

                }
            }
            CGMS_SHOW();
            SDL_Delay(16);
        }
        return 0;
    }
};

#endif
