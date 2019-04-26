TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    wind.cpp \
    menu.cpp \
    sgtp.cpp \
    sgbg.cpp \
    maps.cpp \
    bird.cpp
INCLUDEPATH += ../SDL2/include/
LIBS += -L../SDL2/lib/x86 -lSDL2
LIBS += -L../SDL2/lib/x86 -lSDL2main
LIBS += -L../SDL2/lib/x86 -lSDL2test
LIBS += -L../SDL2/lib/x86 -lSDL2_image

HEADERS += \
    sgbg.h \
    bird.h \
    sgtp.h \
    maps.h \
    head.h
