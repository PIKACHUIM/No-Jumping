#include "sgbg.h"
sgbg::sgbg(int tp,int id,int oh,int nh,int ud)
{
    sgbg_typ=tp;    //台阶类型
    sgbg_sid=id;    //台阶编号
    sgbg_org=oh;    //初始高度
    sgbg_now=nh;    //当前高度
    sgbg_uod=ud;    //上还是下
    sgbg_rwt=0 ;    //是否保存
}
sgbg::~sgbg(){}
