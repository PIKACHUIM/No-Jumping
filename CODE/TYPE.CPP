#include "TYPE.HPP"

void TYPE::SETP(int TYPE_NUMS,int TYPE_SPEE)
{
    string TYPE_FILE="";
    if(TYPE_NUMS<=9) TYPE_FILE="PNG_FKYP_0"+to_string(TYPE_NUMS)+".PNG";
    else             TYPE_FILE="PNG_FKYP_" +to_string(TYPE_NUMS)+".PNG";
  DATA=IMGS_LOAD(    TYPE_FILE, WIND_RENDP);
  SPEE=TYPE_SPEE;
}
TYPE::TYPE(){};
