#pragma once
#ifndef HEAD_CPP
#define HEAD_CPP
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <time.h>
#define STR string
#define STP SDL_Texture*
#define SDP SDL_Rect
#define SDE SDL_Event
#define SDR SDL_Renderer
#define SDS SDL_Surface
#define SDW SDL_Window
#define SDC SDL_Color
#define TFT TTF_Font
#define TFO TTF_OpenFont
using namespace std;

static SDR*         WIND_RENDP = nullptr;      //渲染指针
static SDW*         WIND_WINDP = nullptr;      //窗口指针
static const char*  WIND_TITLE = "No Jumping"; //菜单标题
static const int    WIND_WIDTH = 1500;         //水平大小
static const int    WIND_HEIGH = 750;          //垂直大小
static const int    GAME_MAXHT = 450;          //方块上限
static const int    GAME_MINHT = 750;          //方块下限
static       int    DBUG_GUPMD = 0x00000006;   //渲染模式
static       int    DBUG_ACCED = 1;            //A显卡加速
static       int    DBUG_SYNCD = 1;            //B垂直同步
static       int    DBUG_NOKIL = 0;            //C作弊模式
static       int    DBUG_DEBUG = 0;            //D调试模式
static       int    DBUG_EEOOR = 1;            //E输出错误
static       int    DBUG_OTFPS = 0;            //F输出帧率
static       int    DBUG_OTIME = 0;            //G输出时间
static       int    DBUG_OTSTP = 0;            //H输出步数

#endif
