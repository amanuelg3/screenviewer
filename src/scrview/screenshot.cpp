#include "screenshot.h"


Screenshot::Screenshot(QString format, int w, int h)
{
    setSize(w, h);
    setFormat(format);
    screen = new QByteArray();
}

Screenshot::Screenshot(QByteArray* scr)
{
    screen = scr;
    QPixmap B;
    B.loadFromData(*screen);
    setSize(B.width(), B.height());
    setFormat("PNG");   //fix this
}


Screenshot::~Screenshot()
{
    delete screen;
}

void Screenshot::setSize(int w, int h)
{
    if (w <= 0)
        w = 800;
    if (h <= 0)
        h = 600;

    this->w = w;
    this->h = h;
}

void Screenshot::newScreen()
{
    if (!screen->isEmpty())
        screen->clear();

    QPixmap pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    pixmap = pixmap.scaled(w, h);
    QBuffer buffer( screen );
    buffer.open( QIODevice::WriteOnly );
    pixmap.save( &buffer, format.toUtf8() ); // writes pixmap into ByteArray.
}

void Screenshot::setFormat(QString format)
{
    if (format != "JPG" && format != "PNG")
        format = "JPG";

    this->format = format;
}
