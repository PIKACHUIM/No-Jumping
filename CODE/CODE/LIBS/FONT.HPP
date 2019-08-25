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

    //红色，绿色，蓝色，水平位置，垂直位置，水平高度，垂直高度,字体大小
    void SETP(Uint8,Uint8,Uint8,int,int,int,int,char*,int);
    void SETP(int,int,int);
    void SETP(char*);
    void SETP(int);
    void SHOW();
};

#endif // FONT_HPP
