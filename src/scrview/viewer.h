#ifndef VIEWER_H
#define VIEWER_H
#include <QMutex>
#include <QThread>
#include "mousedatamaker.h"
#include "scrcollector.h"

class Client;

class Viewer: public QThread
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
    void stop() { stoped = true; }
    void takeScreenshot(Screenshot* data) { scrProcess->newData(data); }

};

#endif // VIEWER_H
