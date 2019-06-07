#pragma once
#ifndef HEAD_CPP
#define HEAD_CPP
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <time.h>
#define STP SDL_Texture*
#define SDP SDL_Rect
#define SDE SDL_Event
#define SDR SDL_Renderer
#define SDW SDL_Window
using namespace std;

static SDR*         WIND_RENDP = nullptr;
static SDW*         WIND_WINDP = nullptr;
static const char*  WIND_TITLE = "No Jumping";
static const int    WIND_WIDTH = 1500;
static const int    WIND_HEIGH = 750;
static const int    GAME_MAXHT = 450;
static const int    GAME_MINHT = 750;
static       int    DBUG_GUPMD = 0x00000006;
static       int    DBUG_ACCED = 1;//A显卡加速
static       int    DBUG_SYNCD = 1;//B垂直同步
static       int    DBUG_NOKIL = 0;//C鸟不会死
static       int    DBUG_DEBUG = 0;//D调试模式
static       int    DBUG_EEOOR = 1;//E输出错误
static       int    DBUG_OTFPS = 0;//F输出帧率
static       int    DBUG_OTIME = 0;//G输出时间
static       int    DBUG_OTSTP = 0;//H输出步数
//RZCL-UPDATE-2019/06/06---------------------------------
static const int    TYPE_SPEED   [6][4] = { 0, 0, 0, 1,
                                            0, 1, 2, 3,
                                            0, 2, 3, 4,
                                            0, 3, 4, 5,
                                            0, 4, 5, 6,
                                            0, 5, 6, 7};
#endif
