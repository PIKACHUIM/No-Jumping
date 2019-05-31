#undef main
#include "./EXTL/WIND.CPP"
#include "./LIBS/REND.CPP"
#include "MENU.CPP"
int main(int argc,char *argv[])
{
    WIND_INIT(argc,argv);
    REND_INIT();
    MENU_INIT();
    MENU_SHOW();
    WIND_EXIT();
    return 0;
}

