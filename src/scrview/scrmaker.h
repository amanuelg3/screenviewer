#ifndef SCRMAKER_H
#define SCRMAKER_H
#include <QThread>
#include <QMutex>
//#include "server.h"

class Server;


class ScrMaker: public QThread
{
private:
    QMutex* scrMutex;
    QString format;
    int w;
    int h;
    bool stoped;
    Server *serv;
public:
    ScrMaker(QMutex* mutex, Server *serv, int w, int h, QString format);
    void run();
    void stop() { stoped = true; }
};

#endif // SCRMAKER_H
