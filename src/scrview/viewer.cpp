#include "viewer.h"
#include "client.h"

Viewer::Viewer(QString host) {
    scrMutex = new QMutex();
    mouseMutex = new QMutex();
    client = new Client();
    scrProcess = new ScrCollector(scrMutex, client);
    mouseProcess = new MouseDataMaker(mouseMutex, client);
    this->host = host;
    client->setHost(host);
    client->connectToHost();
}

void Viewer::run() {
    stoped = false;
    scrProcess->start();
    mouseProcess->start();
    while (!stoped) {
        //cheeck if connection  is not dropped
    }
    mouseProcess->stop();
    scrProcess->stop();
    scrMutex->unlock();
    mouseMutex->unlock();
    mouseProcess->wait();
    scrProcess->wait();
}
