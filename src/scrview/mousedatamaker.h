#ifndef MOUSEDATAMAKER_H
#define MOUSEDATAMAKER_H
#include <QMutex>
#include <QThread>

class Client;

class MouseDataMaker :  public QThread
{
private:
    QMutex* mutex;
    Client* client;
    bool stoped;
public:
    MouseDataMaker(QMutex* mutex, Client* client);
    void run();
    void stop() { stoped = true; }
};

#endif // MOUSEDATAMAKER_H
