# -----------------------------------------------------------
# This file is generated by the Qt Visual Studio Integration.
# -----------------------------------------------------------

TEMPLATE = lib
TARGET = hmathast
DESTDIR = /mmlsoft/run/debug
CONFIG += debug
DEFINES += HMATHAST_LIB
INCLUDEPATH += /mmlsoft/include \
    ./GeneratedFiles \
    ./GeneratedFiles/Debug
LIBPATH += /mmlsoft/run/debug
LIBS += -lhutils \
        -lhmathbs
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += /mmlsoft/int/debug/hmathast
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

#Include file(s)
include(hmathast.pri)