#pragma once
#ifndef FKYP_HPP
#define FKYP_HPP

class FKYP
{
public:
    int  FKID;
    int  TYPE;
    int  NOWH;
    int  FXBZ;
    FKYP(){}
    FKYP(int FKYP_FKID,int FKYP_TYPE,int FKYP_NOWH)
    {
        FKID=FKYP_FKID;
        TYPE=FKYP_TYPE;
        NOWH=FKYP_NOWH;
    }
};
#endif
