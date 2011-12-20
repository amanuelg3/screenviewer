#ifndef SCRCOLLECTOR_H
#define SCRCOLLECTOR_H
#include <QMutex>
#include <QThread>

class Client;

class ScrCollector : public QThread
{
private:
    QMutex* mutex;
    Client *client;
    bool stoped;
public:
    ScrCollector(QMutex* mutex, Client *client);
    void run();
    void stop() { stoped = true; }
};

#endif // SCRCOLLECTOR_H
