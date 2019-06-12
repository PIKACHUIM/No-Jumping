#ifndef FONT_HPP
#define FONT_HPP
#include"../EXTL/HEAD.CPP"
/*------FONT类
 * 存储与选择字体
 */
class FONT
{
public:
    SDP FONT_POST; //位置，大小
    SDC FONT_COLO; //颜色，深度
   char*FONT_TEXT; //文本
    STP FONT_IMGS; //图像
    SDS*FONT_SURE; //界面
    TFT*FONT_FONT; //字体
    int FONT_NUMS; //数值
    int FONT_SIZE; //数值
    FONT(){};
    void SHOW()
    {
        FONT_FONT = TTF_OpenFont  ("../ASSE/TTF_FONT_00.TTF",FONT_SIZE);
        FONT_SURE = TTF_RenderUTF8_Solid(FONT_FONT,FONT_TEXT,FONT_COLO);
        FONT_IMGS = SDL_CreateTextureFromSurface (WIND_RENDP,FONT_SURE);
             SDL_RenderCopy(WIND_RENDP, FONT_IMGS, nullptr, &FONT_POST);
    }
    //红色，绿色，蓝色，水平位置，垂直位置，水平高度，垂直高度,字体大小
    void SETP(Uint8,Uint8,Uint8,int,int,int,int,char*,int);
    void SETP(int,int,int);
    void SETP(char*);
    void SETP(int);
};
void FONT::SETP(Uint8 T1,Uint8 T2,Uint8 T3,int T4,int T5,int T6,int T7,char* T8,int T9)
{
      FONT_COLO={T1,T2,T3};
      FONT_TEXT=T8;
      FONT_SIZE=T9;
    FONT_POST.x=T4;
    FONT_POST.y=T5;
    FONT_POST.w=T6;
    FONT_POST.h=T7;
}
void FONT::SETP(char*T8){FONT_TEXT=T8;}//改变图像文本
void FONT::SETP(int  T9){FONT_SIZE=T9;}//改变字体大小
void FONT::SETP(int FG,int TA,int TB)
{
    if(FG==0)//改变图像位置
    {
        FONT_POST.x=TA;
        FONT_POST.y=TB;
    }
    if(FG==1)//改变图像大小
    {
        FONT_POST.w=TA;
        FONT_POST.h=TB;
    }
}
#endif // FONT_HPP
