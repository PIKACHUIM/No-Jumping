#ifndef SGTP_H
#define SGTP_H


class sgtp
{
    public:
    int    sgbg_spd;    //台阶速度
    int    sgbg_max;    //最大高度
    int    sgbg_min;    //最小高度
    int    sgbg_col;    //台阶颜色
    bool   sgbg_flg;    //可否暂停
     sgtp();
    ~sgtp();
};

#endif // SGTP_H
