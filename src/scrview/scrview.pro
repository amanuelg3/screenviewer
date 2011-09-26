#-------------------------------------------------
#
# Project created by QtCreator 2011-09-19T15:57:50
#
#-------------------------------------------------

QT       += core gui testlib network

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        screenview.cpp \
    screenshot.cpp \
    TestCapturer.cpp  \
    capturer.cpp \
    server.cpp \
    client.cpp

HEADERS  += screenview.h \
    screenshot.h \
    capturer.h \
    server.h \
    client.h
    TestCapturer.h \
    TestScreenshot.h

FORMS    += screenview.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xeadfae89
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}



















