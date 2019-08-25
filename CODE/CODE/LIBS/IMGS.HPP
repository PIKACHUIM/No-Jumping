#pragma once
#ifndef IMGS_HPP
#define IMGS_HPP
#include"../EXTL/HEAD.CPP"
#include"../EXTL/DBUG.CPP"

/*       IMGS类
 * 读取，管理，渲染 界面图片
 * 以及载入并向TYPE传递纹理
*/

 class IMGS
 {
 public:
     SDL_Texture* IMGS_IMGS_TEXT;                 //存储纹理
     SDL_Rect     IMGS_IMGS_POST;                 //存储位置
     int          IMGS_IMGS_UPDO;                 //存储方向
     IMGS(){}
     IMGS(const string ,int ,int ,int ,int ,int );//图片类型，图片编号，水平位置，垂直位置，水平大小，垂直大小
void SETP(const string ,int ,int ,int ,int ,int );//图片类型，图片编号，水平位置，垂直位置，水平大小，垂直大小
void SETP(                   int ,int ,int ,int );//---------------，水平位置，垂直位置，水平大小，垂直大小
                   void SHOW(int ,int ,int ,int );//---------------，水平位置，垂直位置，水平大小，垂直大小
                   void SHOW(int                );//---------------，水平变量，------------------------
                   void SHOW();
 };
#endif
