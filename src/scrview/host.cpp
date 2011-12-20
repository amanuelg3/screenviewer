#include "host.h"
#include "server.h"

Host::Host(int w, int h, QString format) {
    this->w = w;
    this->h = h;
    this->format = format;
    scrMutex = new QMutex();
    mouseMutex = new QMutex();
    serv = new Server(scrMutex, mouseMutex, this);
    scrProcess = new ScrMaker(scrMutex, serv, w, h, format);
    mouseProcess = new MouseDataCollector(mouseMutex, serv);
    serv->listen(QHostAddress::Any, 4200);
}

void Host::run() {
    scrProcess->start();
    mouseProcess->start();
    while (isClient) {
        //cheeck if connection  is not dropped
    }
    mouseProcess->stop();
    scrProcess->stop();
    scrMutex->unlock();
    mouseMutex->unlock();
    mouseProcess->wait();
    scrProcess->wait();
}
