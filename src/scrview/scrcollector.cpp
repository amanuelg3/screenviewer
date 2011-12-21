#include "scrcollector.h"
#include "client.h"
#include "confirmpacket.h"

ScrCollector::ScrCollector(QMutex* mutex, Client *client) {
    this->mutex = mutex;
    this->client = client;
}

void ScrCollector::run() {
    ConfirmPacket* packet = new ConfirmPacket();
    stoped = false;
    mutex->lock();
    while(!stoped) {
        mutex->lock();
        //new data
        qDebug() << "Gavau ekrana size: " << (int)data->getScreen()->size();
        client->sendPacket(*packet->makeAndGetPacket());
        mutex->unlock();
        mutex->lock();
    }
    mutex->unlock();
    delete packet;
}

void ScrCollector::newData(Screenshot* data) {
    delete this->data;
    this->data = data;
}
