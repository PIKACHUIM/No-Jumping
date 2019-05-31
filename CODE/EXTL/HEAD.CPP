#pragma once
#ifndef HEAD_CPP
#define HEAD_CPP
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <time.h>
#define STP SDL_Texture*
#define SDP SDL_Rect
using namespace std;

static SDL_Renderer*WIND_RENDP = nullptr;
static SDL_Window*  WIND_WINDP = nullptr;
static const char*  WIND_TITLE = "No Jumping";

static const int    WIND_WIDTH = 1500;
static const int    WIND_HEIGH = 750;
static const int    GAME_MAXHT = 450;
static const int    GAME_MINHT = 750;

static       int    DBUG_GUPMD = 0x00000006;
static       int    DBUG_ACCED = 1;//A显卡加速
static       int    DBUG_SYNCD = 1;//B垂直同步
static       int    DBUG_NOKIL = 1;//C鸟不会死
static       int    DBUG_DEBUG = 1;//D调试模式
static       int    DBUG_EEOOR = 1;//E输出错误
static       int    DBUG_OTFPS = 0;//F输出帧率
#endif
