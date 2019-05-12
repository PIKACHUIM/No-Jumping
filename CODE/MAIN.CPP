#include"WIND.CPP"
#include"REND.CPP"
#include"IMGS.CPP"
#include"DBUG.CPP"
#include"MENU.CPP"
#undef main


int main(int argc,char *argv[])
{
    DBUG_INIT(argc,argv);
    WIND_INIT();
    REND_INIT();
    MENU_SHOW();
    WIND_EXIT();
    return 0;
}
