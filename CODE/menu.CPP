#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
#include "IMGS.CPP"
#include "REND.CPP"
#include "TYPE.CPP"

int MENU_SHOW()
{
    IMGS MENU1("MENU",00,000,000,1500,750);
    IMGS MENU2("MENU",01,000,320, 640,480);
    IMGS MENU3("MENU",01,440,320, 640,480);
    IMGS MENU4("MENU",01,880,320, 640,480);
    IMGS MENU5("MENU",02,440,100, 600,200);
    IMGS MENU6("MENU",03,760,300, 270, 66);
    IMGS MENU7("MENU",04,452,300, 270, 66);
    IMGS BIRDS("BIRD",01,440,000,  71, 57);
    IMGS FKYP[15];
    TYPE FKTP[6][4];
    for(int LOOP_A=0,LOOP_T=1;LOOP_A<=5 ;LOOP_A++,LOOP_T++)
        for(int LOOP_B=1;LOOP_B<=3;LOOP_B++)
            FKTP[LOOP_A][LOOP_B].SETP(LOOP_A*10+LOOP_B,LOOP_T);
    for(int LOOP_T=0;LOOP_T<=14;LOOP_T++)
    {
        FKYP[LOOP_T].IMGS_IMGS_UPDO=1;
        FKYP[LOOP_T].SETP("FKYP",rand()%3+1+(rand()%5+1)*10,000+100*LOOP_T,400+20*LOOP_T, 81,511);
    }
    double TIME_LAST = SDL_GetTicks();
    double TIME_LOOP = SDL_GetTicks();
    int    BIRD_POTS=rand()%10+3;
    for(int count=1;;count++)
    {
        REND_CLEN();
        MENU1.SHOW();
        MENU2.SHOW();
        MENU3.SHOW();
        MENU4.SHOW();
        MENU5.SHOW();
        MENU6.SHOW();
        MENU7.SHOW();
        for(int LOOP_TMPS=0;LOOP_TMPS<=14;LOOP_TMPS++)FKYP[LOOP_TMPS].SHOW();
        BIRDS.SHOW();
        REND_SHOW();
        SDL_Event event;
        SDL_PollEvent(&event);
        BIRDS.SETP(FKYP[BIRD_POTS].IMGS_IMGS_POST.x+12,FKYP[BIRD_POTS].IMGS_IMGS_POST.y+FKYP[BIRD_POTS].IMGS_IMGS_UPDO-57,71,57);
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
            DBUG_TFPS(count," RUNT_RENDER"," FPS");
            count = 0;
            TIME_LAST = SDL_GetTicks();
        }
        //SDL_Delay(15);
    }
}
