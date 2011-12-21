#ifndef SCRCOLLECTOR_H
#define SCRCOLLECTOR_H
#include <QMutex>
#include <QThread>
#include "screenshot.h"

class Client;

class ScrCollector : public QThread
{
private:
    QMutex* mutex;
    Client *client;
    bool stoped;
    Screenshot* data;
public:
    ScrCollector(QMutex* mutex, Client *client);
    void run();
    void newData(Screenshot* data);
    void stop() { stoped = true; }
};

#endif // SCRCOLLECTOR_H
