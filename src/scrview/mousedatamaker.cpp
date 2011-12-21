#include "mousedatamaker.h"
#include "client.h"
#include "mousepacket.h"
#include "screenview.h"

MouseDataMaker::MouseDataMaker(QMutex* mutex, Client* client) {
    this->mutex = mutex;
    this->client = client;
}

void MouseDataMaker::run() {
    MousePacket* packet = new MousePacket();
    stoped = false;
    while(!stoped) {
        QThread::msleep(100);
        packet->setNewContent(ScreenView::getMouseData());
        client->sendPacket(*packet->makeAndGetPacket());
    }
    delete packet;
}
