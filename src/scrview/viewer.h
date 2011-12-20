#ifndef VIEWER_H
#define VIEWER_H
#include <QMutex>
#include <QThread>
#include "mousedatamaker.h"
#include "scrcollector.h"

class Client;

class Viewer
{
private:
    QMutex* scrMutex;
    QMutex* mouseMutex;
    ScrCollector* scrProcess;
    MouseDataMaker* mouseProcess;
    Client* client;
    bool stoped;
    QString host;
public:
    Viewer(QString host);
    void run();
    void stop() { stopped = true; }

};

#endif // VIEWER_H
