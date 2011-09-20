#-------------------------------------------------
#
# Project created by QtCreator 2011-09-19T15:57:50
#
#-------------------------------------------------

QT       += core gui testlib

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        screenview.cpp \
    screenshot.cpp \
    Testscreenshot.cpp

HEADERS  += screenview.h \
    screenshot.h

FORMS    += screenview.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xeadfae89
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}







