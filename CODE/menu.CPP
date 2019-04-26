#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
#include "IMGS.CPP"
#include "REND.CPP"
int MENU_SHOW()
{
    IMGS MENU1("MENU",00,000,000,1500,750);
    IMGS MENU2("MENU",01,000,320,640,480);
    IMGS MENU3("MENU",01,440,320,640,480);
    IMGS MENU4("MENU",01,880,320,640,480);
    IMGS MENU5("MENU",02,440,120,600,200);
    double lastSec = SDL_GetTicks();
    for(int count=1;;count++)
    {
        REND_CLEN();
        MENU1.SHOW();
        MENU2.SHOW();
        MENU3.SHOW();
        MENU4.SHOW();
        MENU5.SHOW();
        REND_SHOW();
        SDL_Event event;
        SDL_PollEvent(&event);


        if ((SDL_GetTicks() - lastSec) / 1000 > 1)
        {
            if(DBUG_FLAGS==true)
            DBUG_TFPS(count," RUNT_RENDER"," FPS");
            count = 0;
            lastSec = SDL_GetTicks();
        }

    }
}
