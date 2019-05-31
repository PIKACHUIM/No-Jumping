TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    MAIN.CPP \
    MENU.CPP \
    EXTL/DBUG.CPP \
    EXTL/HEAD.CPP \
    LIBS/IMGS.CPP \
    LIBS/READ.CPP \
    LIBS/REND.CPP \
    LIBS/FKYP.CPP \
    LIBS/TYPE.CPP \
    CGMS.CPP \
    EXTL/WIND.CPP
INCLUDEPATH += ../SDL2/include/
LIBS += -L../SDL2/lib/x86 -lSDL2
LIBS += -L../SDL2/lib/x86 -lSDL2main
LIBS += -L../SDL2/lib/x86 -lSDL2test
LIBS += -L../SDL2/lib/x86 -lSDL2_image

HEADERS += \
    LIBS/IMGS.HPP \
    LIBS/IMGS.HPP \
    LIBS/READ.HPP \
    LIBS/REND.HPP \
    LIBS/FKYP.HPP \
    LIBS/TYPE.HPP
