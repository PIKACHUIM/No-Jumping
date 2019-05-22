#ifndef SGBG_H
#define SGBG_H
class sgbg
{
public:
    int    sgbg_sid;    //台阶编号
    int    sgbg_typ;    //台阶类型
    int    sgbg_org;    //初始高度
    int    sgbg_now;    //当前高度
    bool   sgbg_uod;    //上还是下
    bool   sgbg_rwt;    //是否保存

     sgbg(int tp,int id,int oh,int nh,int ud);
    ~sgbg();
};

#endif // SGBG_H
