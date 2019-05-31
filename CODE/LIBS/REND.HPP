#pragma once
#ifndef REND_HPP
#define REND_HPP

#include"../EXTL/HEAD.CPP"
#include"../EXTL/DBUG.CPP"
int REND_INIT();
int REND_CLEN();
int REND_SHOW();
class REND
{
public:
         int NUMS;
         int NOWN;
         int TYPE[16];
    SDL_Rect POST[16];
             REND ();
        void SHOW ();
};
#endif
