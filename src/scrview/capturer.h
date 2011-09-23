#ifndef CAPTURER_H
#define CAPTURER_H
#include "screenshot.h"
#include <QList>
#include <QTimer>

struct ScreenList
{
    Screenshot *screen;
    bool sent;
};

class Capturer : public QObject
{
    Q_OBJECT
private:
    int fpm;
    QString format;
    int w, h;
    QList<ScreenList> *screens;
    bool running;
    QTimer *timer;
public:
    Capturer(int fpm, QString format, int w, int h);
    void start();
    void stop();
    bool isRunning() { return running; }
    bool hasScreen();
    QByteArray* getScreen();
public slots:
    void work();
};

#endif // CAPTURER_H
