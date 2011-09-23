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
    int fpm; // frames per minute.
    QString format; // PNG or JPG
    int w, h;
    QList<ScreenList> *screens; // list of captured screens.
    bool running;
    QTimer *timer;
public:
    Capturer(int fpm, QString format, int w, int h);
    void start(); // start capturing
    void stop(); // stop capturing
    bool isRunning() { return running; } // check if capturing
    bool hasScreen(); // check if we have screen which is ready to be sent
    QByteArray* getScreen(); // send last unsent screen
public slots:
    void work(); // do screen, put it in screens list.
};

#endif // CAPTURER_H
