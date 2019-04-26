#ifndef IMGS_HPP
#define IMGS_HPP



#include "HEAD.CPP"
#include "DBUG.CPP"
/*---------------------使用说明(图片类型，图片编号，水平位置，垂直位置，水平大小，垂直大小)---------------------*/
 class IMGS
 {
 public:
     SDL_Texture* IMGS_IMGS_TEXT = nullptr;
     SDL_Rect     IMGS_IMGS_POST;
     IMGS(const string ,int ,int ,int ,int ,int );
                   void SHOW(int ,int ,int ,int );
                   void SHOW();
 };
#endif // IMGS_HPP
