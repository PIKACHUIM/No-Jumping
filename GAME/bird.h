#ifndef BIRD_H
#define BIRD_H

class bird
{
public:
    int  bird_tim;   //当前时间
    int  bird_sid;   //当前位置
    int  bird_sav;   //存档位置
    bool bird_hit;   //是否冲撞
    bird();
   ~bird();
};

#endif // BIRD_H
