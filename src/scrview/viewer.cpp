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
}

void Viewer::run() {
    client->connectToHost();
    scrProcess->start();
    mouseProcess->
}
