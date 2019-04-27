#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
#include "IMGS.CPP"
#include "REND.CPP"

int MENU_SHOW()
{
    IMGS MENU1("MENU",00,000,000,1500,750);
    IMGS MENU2("MENU",01,000,320, 640,480);
    IMGS MENU3("MENU",01,440,320, 640,480);
    IMGS MENU4("MENU",01,880,320, 640,480);
    IMGS MENU5("MENU",02,460,000, 600,200);
    IMGS BIRDS("BIRD",01,460,000,  71, 57);
    IMGS FKYP[15];
    for(int LOOP_TMPS=0;LOOP_TMPS<=14;LOOP_TMPS++)
    {
      FKYP[LOOP_TMPS].IMGS_IMGS_UPDO=1;
      FKYP[LOOP_TMPS].SETP("FKYP",11,000+100*LOOP_TMPS,400+20*LOOP_TMPS, 81,511);
    }

    double TIME_LAST = SDL_GetTicks();
    double TIME_LOOP = SDL_GetTicks();
    for(int count=1;;count++)
    {
        REND_CLEN();
        MENU1.SHOW();
        MENU2.SHOW();
        MENU3.SHOW();
        MENU4.SHOW();
        MENU5.SHOW();
        for(int LOOP_TMPS=0;LOOP_TMPS<=14;LOOP_TMPS++)FKYP[LOOP_TMPS].SHOW();
        BIRDS.SHOW();
        REND_SHOW();
        SDL_Event event;
        SDL_PollEvent(&event);
        BIRDS.SETP(FKYP[5].IMGS_IMGS_POST.x+6,FKYP[5].IMGS_IMGS_POST.y+FKYP[5].IMGS_IMGS_UPDO-57,71,57);
        if ((SDL_GetTicks() - TIME_LOOP) / 1 > 1)
        {
            for(int LOOP_TMPS=0;LOOP_TMPS<=14;LOOP_TMPS++)
            {
                if(FKYP[LOOP_TMPS].IMGS_IMGS_POST.y==700) FKYP[LOOP_TMPS].IMGS_IMGS_UPDO=-1;
                if(FKYP[LOOP_TMPS].IMGS_IMGS_POST.y==450) FKYP[LOOP_TMPS].IMGS_IMGS_UPDO= 1;
                FKYP[LOOP_TMPS].SETP(FKYP[LOOP_TMPS].IMGS_IMGS_POST.x,FKYP[LOOP_TMPS].IMGS_IMGS_POST.y+FKYP[LOOP_TMPS].IMGS_IMGS_UPDO,81,511);
            }
            TIME_LOOP = SDL_GetTicks();
        }
        if ((SDL_GetTicks() - TIME_LAST) / 1000 > 1)
        {
            if(DBUG_FLAGS==true)
            DBUG_TFPS(count," RUNT_RENDER"," FPS");
            count = 0;
            TIME_LAST = SDL_GetTicks();
        }
        //SDL_Delay(15);
    }
}
