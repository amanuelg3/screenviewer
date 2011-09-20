#include "screenshot.h"


Screenshot::Screenshot(QString format, int w, int h)
{
    setSize(w, h);
    setFormat(format);
    screen = new QByteArray();
}

void Screenshot::setSize(int w, int h)
{
    this->w = w;
    this->h = h;
}

void Screenshot::newScreen()
{
    //if (screen)
    //    delete screen;

    QPixmap pixmap = QPixmap::grabWindow(QApplication::desktop()->winId(), 0, 0, w, h);
    QBuffer buffer( screen );
    buffer.open( QIODevice::WriteOnly );
    pixmap.save( &buffer, format.toUtf8() ); // writes pixmap into ba in PNG format
}

void Screenshot::setFormat(QString format)
{
    this->format = format;
}
