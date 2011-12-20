#include "mousedatacollector.h"
#include "server.h"

MouseDataCollector::MouseDataCollector(QMutex* mutex, Server *server) {
    this->mutex = mutex;
    this->server = server;
    stoped = false;
}

void MouseDataCollector::run() {
    stoped = false;
    mutex->lock();
    while(!stoped) {
        mutex->lock();
        //new data
        qDebug() << "Gavom peles: " << (quint32)data->x << " " << data->y;
        mutex->unlock();
        mutex->lock();
    }
    mutex->unlock();
}

void MouseDataCollector::newData(MouseData* data) {

    delete this->data;
    this->data = data;
}
