#include"LIBS/IMGS.CPP"
#include"LIBS/REND.CPP"
#include"LIBS/FONT.CPP"
#include"EXTL/HEAD.CPP"
#include"EXTL/WIND.CPP"
#include"CGMS.CPP"
#include "SDL_ttf.h"

int  YXXY_XZFW[16][5];
int  YXXY_XZXZ[16][5];
SDE  YXXY_EVEN;
IMGS YXXY_BGMP[22];
IMGS YXXY_BGFA[16];
IMGS YXXY_STAR[11][4];
SAVE YXXY_DATA;
READ YXXY_DQFW;
READ YXXY_DQXZ;
READ YXXY_CHIL;
int BOTT_DEAL(int ix,int iy,int FTTL[16][5],int LTNS)  //获取鼠标按钮编号
{
    for(int LOOP=1;LOOP<=LTNS;LOOP++)
    {
        int PDSJ_FLAG=0;
        if(ix<FTTL[LOOP][1]
         ||ix>FTTL[LOOP][2])PDSJ_FLAG=1;
        if(iy<FTTL[LOOP][3]
         ||iy>FTTL[LOOP][4])PDSJ_FLAG=1;
        if(PDSJ_FLAG==0)    return LOOP;
    }
    return 0;
}

int YXXY_INIT()
{
    SDL_PollEvent(&YXXY_EVEN);//初始化事件
//---------------配置复制:一级菜单-------------------------
    for(int i=1;i<=YXXY_CHIL.LENS;i++)
    {
        YXXY_BGFA[i].SETP("INFA",
                YXXY_CHIL.DATA[i][1],
                YXXY_CHIL.DATA[i][2],
                YXXY_CHIL.DATA[i][3],
                YXXY_CHIL.DATA[i][4],
                YXXY_CHIL.DATA[i][5]);
        YXXY_BGFA[i].SHOW();
    }
//-----------------配置复制:按键检测------------------------
    YXXY_DQFW.SETP("CONF","POS","YXXY",01,4);
    YXXY_DQXZ.SETP("CONF","POS","YXXY",02,4);
    for(int LOOP=1;LOOP<=YXXY_DQFW.LENS;LOOP++)
    for(int LTMP=1;LTMP<=4;LTMP++)
        YXXY_XZFW[LOOP][LTMP]=YXXY_DQFW.DATA[LOOP][LTMP];
        YXXY_XZFW[   0][   0]=YXXY_DQFW.LENS;
    for(int LOOP=1;LOOP<=YXXY_DQXZ.LENS;LOOP++)
    for(int LTMP=1;LTMP<=4;LTMP++)
        YXXY_XZXZ[LOOP][LTMP]=YXXY_DQXZ.DATA[LOOP][LTMP];
        YXXY_XZXZ[   0][   0]=YXXY_DQXZ.LENS;
        YXXY_CHIL.SETP("MAPS","MAP","INFA",00,5);
//---------------载入图像:复制星星--------------------------
    for(int LOOP=1;LOOP<=10;LOOP++)
    for(int LTMP=1;LTMP<= 3;LTMP++)
        YXXY_STAR[LOOP][LTMP].SETP("STAR",01,362-87+87*LOOP,572+LTMP*35-35,32,31);
//-------------------------------------------------------

    return 0;
}

int YXXY_CHOC(int order)
{
    YXXY_DATA.INIT();
    SDE  CHOC_EVENT;
    SDL_PollEvent(&CHOC_EVENT);
    REND_CLEN();
    READ CHILD("MAPS","MAP","INFA",order,5);
    for(int i=1;i<=CHILD.LENS;i++)
    {
        YXXY_BGMP[i].SETP("INFA",                  //配置复制
                CHILD.DATA[i][1],
                CHILD.DATA[i][2],
                CHILD.DATA[i][3],
                CHILD.DATA[i][4],
                CHILD.DATA[i][5]);
        YXXY_BGMP[i].SHOW();
    }
    while(CHOC_EVENT.type!=SDL_QUIT)
    {
        for(int i=1;i<=CHILD.LENS;i++)
        YXXY_BGMP[i].SHOW();
        for(int LOOP=1;LOOP<=10;LOOP++)
        {
                for(int LTMP=1;LTMP<=YXXY_DATA.DASX[(order-1)*10+LOOP];LTMP++)
                YXXY_STAR[LOOP][LTMP].SHOW();
        }

        REND_SHOW();
        while (SDL_PollEvent(&CHOC_EVENT))
        {
            if(CHOC_EVENT.type==SDL_QUIT)
                WIND_EXIT();                         //关闭窗口
            if(CHOC_EVENT.type==SDL_MOUSEBUTTONUP)
            {
                CHOC_EVENT.type=SDL_KEYUP;
                int   YXXY_GXIT=
                      BOTT_DEAL(CHOC_EVENT.button.x,
                                CHOC_EVENT.button.y,
                                YXXY_XZXZ,
                                YXXY_XZXZ[0][0]);    //检测按键
                      if(YXXY_GXIT==0)break;
                      if(YXXY_GXIT==1)return 0;
                      else
                      {
                          int CGRT=1;
                          for(;CGRT==1;)
                          {
                              CGMS GAME;
                                   GAME.CGMS_INIT(YXXY_GXIT-2+order*10);
                              CGRT=GAME.CGMS_DEAL();
                              if (CGRT==2)return 2;
                              if (CGRT==3)break;
                          }
                      }


            }
        }
    }
    return 0;
}
int YXXY_INFT()
{
//-------------------------------------------------------
    REND_CLEN();
    while(YXXY_EVEN.type!=SDL_QUIT)
    {
        for(int i=1;i<=YXXY_CHIL.LENS;i++)    //渲染背景
            YXXY_BGFA[i].SHOW();
        REND_SHOW();                          //执行渲染
        while (SDL_PollEvent(&YXXY_EVEN))
        {
            if(YXXY_EVEN.type==SDL_QUIT)
                WIND_EXIT();                   //关闭窗口
            if(YXXY_EVEN.type==SDL_MOUSEBUTTONUP)
            {
                int YXXY_XZGQ=                 //判断点击区域
                BOTT_DEAL(YXXY_EVEN.button.x,
                          YXXY_EVEN.button.y,
                          YXXY_XZFW,
                          YXXY_XZFW[0][0]);    //关卡界面
                if(YXXY_XZGQ==0)break;         //无操作
                if(YXXY_XZGQ==5)return 0;      //返回上一层
                YXXY_EVEN.type=SDL_KEYUP;      //重置事件，防止段错误
                int CGRT=YXXY_CHOC(YXXY_XZGQ); //进入子菜单
                if(CGRT==2) return 2;          //强制返回
            }
        }
    }
    return 0;
}
