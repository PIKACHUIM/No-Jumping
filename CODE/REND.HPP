#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
#include "IMGS.CPP"
class REND
{
public:
         int TYPE[16];
         int FXCS[16];
    SDL_Rect POST[16];
             REND ();
        void SHOW ();
};
