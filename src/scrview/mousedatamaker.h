#ifndef MOUSEDATAMAKER_H
#define MOUSEDATAMAKER_H
#include <QMutex>
#include <QThread>

class Client;

class MouseDataMaker :  public QThread
{
private:
    QMutex* scrMutex;
    Client* client;
public:
    MouseDataMaker();
};

#endif // MOUSEDATAMAKER_H
