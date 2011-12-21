#include "scrmaker.h"
#include "screenshot.h"
#include "sspacket.h"
#include "server.h"

ScrMaker::ScrMaker(QMutex* mutex, Server* server, int w, int h, QString format) {
    this->scrMutex = mutex;
    this->serv = server;
    this->w = w;
    this->h = h;
    this->format = format;
    stoped = false;
}


void ScrMaker::run()
{   Screenshot* screen = new Screenshot(format, w, h);
    SsPacket* packet = new SsPacket();
    stoped = false;
    screen->newScreen();
    packet->setNewContent(screen);
    serv->sendPacket(*packet->makeAndGetPacket());
    while (!stoped) {
        scrMutex->lock();
        scrMutex->lock();
        if (stoped)
            break;
        screen->newScreen();
        packet->setNewContent(screen);
        serv->sendPacket(*packet->makeAndGetPacket());
        scrMutex->unlock();
    }
    scrMutex->unlock();
    delete packet;
    delete screen;
}
