#ifndef HOST_H
#define HOST_H
#include <QThread>
#include <QMutex>
#include "server.h"
#include "scrmaker.h"
#include "mouse.h"
#include "mousedatacollector.h"


class Host : public QThread
{
private:
    bool isClient;
    QString format;
    int w;
    int h;
    QMutex* scrMutex;
    QMutex* mouseMutex;
    ScrMaker* scrProcess;
    MouseDataCollector* mouseProcess;
    Server* serv;
public:
    Host(int w, int h,  QString format);
    void run();
    void takeClient() { isClient = false; }
    bool hasClient() { return isClient; }
    void setW(int w) { this->w = w; }
    int getW() { return w; }
    void setH(int h) { this->h = h; }
    int getH() { return h; }
    void setFormat(QString format) { this->format = format; }
    QString getFormat() { return format; }
    void takeMouseData(MouseData* data) { mouseProcess->newData(data); }

};

#endif // HOST_H
