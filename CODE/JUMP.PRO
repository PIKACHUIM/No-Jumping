TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    MAIN.CPP \
    WIND.CPP \
    REND.CPP \
    HEAD.CPP \
    IMGS.CPP \
    DBUG.CPP \
    MENU.CPP \
    FKYP.CPP \
    HELP.TPP \
    TYPE.CPP \
    GAME.CPP
INCLUDEPATH += ../SDL2/include/
LIBS += -L../SDL2/lib/x86 -lSDL2
LIBS += -L../SDL2/lib/x86 -lSDL2main
LIBS += -L../SDL2/lib/x86 -lSDL2test
LIBS += -L../SDL2/lib/x86 -lSDL2_image

HEADERS += \
    IMGS.HPP \
    FKYP.HPP \
    REND.HPP \
    TYPE.HPP
