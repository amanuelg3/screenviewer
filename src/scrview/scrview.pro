# -------------------------------------------------
# Project created by QtCreator 2011-09-19T15:57:50
# -------------------------------------------------
QT += core \
    gui \
    testlib \
    network
TARGET = untitled
TEMPLATE = app
SOURCES += main.cpp \
    screenview.cpp \
    abstractpacket.cpp \
    screenshot.cpp \
    capturer.cpp \
    server.cpp \
    client.cpp \
    mouse.cpp \
    sspacket.cpp \
    mousepacket.cpp \
    testmousepacket.cpp \
    testcapturer.cpp \
    testscreenshot.cpp \
    testsspacket.cpp \
    IPdatabase.cpp \
    testscreenshot.cpp
HEADERS += screenview.h \
    abstractpacket.h \
    screenshot.h \
    capturer.h \
    server.h \
    client.h \
    mouse.h \
    sspacket.h \
    mousepacket.h \
    testmousepacket.h \
    testcapturer.h \
    testscreenshot.h \
    testsspacket.h \
    IPdatabase.h \
    testscreenshot.h
FORMS += screenview.ui
CONFIG += mobility
MOBILITY = 
symbian { 
    TARGET.UID3 = 0xeadfae89
    
    # TARGET.CAPABILITY +=
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 \
        0x800000
}
