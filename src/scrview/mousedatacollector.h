#ifndef MOUSEDATACOLLECTOR_H
#define MOUSEDATACOLLECTOR_H
#include <QThread>
#include <QMutex>
#include "mouse.h"

class Server;

class MouseDataCollector : public QThread
{
private:
    QMutex* mutex;
    Server *server;
    bool stoped;
    MouseData* data;
public:
    MouseDataCollector(QMutex* mutex, Server *server);
    void run();
    void stop() { stoped = true; }
    void newData(MouseData* data);
};

#endif // MOUSEDATACOLLECTOR_H
