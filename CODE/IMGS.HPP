#pragma once
#include "HEAD.CPP"
#include "DBUG.CPP"
 class IMGS
 {
 public:
     SDL_Texture* IMGS_IMGS_TEXT = nullptr;
     SDL_Rect     IMGS_IMGS_POST;
     int          IMGS_IMGS_UPDO;
     IMGS(){}
     IMGS(const string ,int ,int ,int ,int ,int );//图片类型，图片编号，水平位置，垂直位置，水平大小，垂直大小
void SETP(const string ,int ,int ,int ,int ,int );//图片类型，图片编号，水平位置，垂直位置，水平大小，垂直大小
void SETP(                   int ,int ,int ,int );//----------------，水平位置，垂直位置，水平大小，垂直大小
                   void SHOW(int ,int ,int ,int );//----------------，水平位置，垂直位置，水平大小，垂直大小
                   void SHOW(               int );//----------------，水平变量--------------------------
                   void SHOW();
 };
