#include "capturer.h"

Capturer::Capturer(int fpm, QString format, int w, int h)
    : fpm(fpm), format(format), w(w), h(h)
{
    screens = new QList<ScreenList>;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(work()));
}

void Capturer::work()
{
    ScreenList *temp;
    temp = new ScreenList();
    temp->screen = new Screenshot(format, w, h);
    temp->screen->newScreen();
    temp->sent = false;

    screens->append(*temp);

    if (!screens->isEmpty())
    {
        if (screens->first().sent)
        {
            delete screens->takeFirst().screen;
        }
    }
}

void Capturer::start()
{
    if (this->running == false)
    {
        this->running = true;
        timer->start(int((fpm/60)*1000)); // start making screens, and putting them in screens list.
    }
}

void Capturer::stop()
{
    this->running = false;
    timer->stop();
}

QByteArray* Capturer::getScreen()
{
    screens->first().sent = true;
    return screens->first().screen->getScreen();
}

bool Capturer::hasScreen()
{
    if (screens->isEmpty()) { // if list is empty.
//        qDebug() << "$$$$ empty list";
        return false;
    }
    if (screens->first().sent) { // if first item from list is sent (not received yet, etc).
//        qDebug() << "$$$$ sent list";
        return false;
    }

    return true;
}
