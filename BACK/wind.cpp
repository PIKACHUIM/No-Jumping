#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;

static const int    wind_widt = 1024;               //窗口宽度
static const int    wind_high = 768;                //窗口高度
static const char*  wind_title;                     //窗口标题
static SDL_Window*  wind_main;                      //中心窗口
static SDL_Surface* wind_sure;                      //初始渲染

int wind_init()
{
     /*------------------------------创建窗口------------------------------*/
    wind_title="No Jumping";

    if(SDL_Init(SDL_INIT_VIDEO)<0) return false;    //创建失败
    wind_main=SDL_CreateWindow(wind_title,          //窗口标题
                            SDL_WINDOWPOS_UNDEFINED,//垂直位置
                            SDL_WINDOWPOS_UNDEFINED,//水平位置
                            wind_widt,              //窗口宽度
                            wind_high,              //窗口高度
                            SDL_WINDOW_SHOWN      );//显示窗口
    if(wind_main==nullptr)          return false;   //创建失败
    wind_sure=SDL_GetWindowSurface(wind_main);      //获取界面
                                    return true;
}

void wind_exit()
{
    /*------------------------------退出程序------------------------------*/
    SDL_FreeSurface(wind_sure);                     //释放空间
    SDL_DestroyWindow(wind_main);                   //销毁窗口
    SDL_Quit();                                     //退出SDL
    wind_main = nullptr;
    wind_sure = nullptr;
}

int wind_test()
{
                                                    //获取窗口
    wind_sure=SDL_GetWindowSurface(wind_main);      //加载图片
    SDL_Texture *load_picture(const std::string &filename);
    SDL_UpdateWindowSurface(wind_main);              //更新显示
    SDL_Delay(2000);                                 //延时关闭
    return true;
}



