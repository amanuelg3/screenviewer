#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QString>
#include <QByteArray>
#include <QPixmap>
#include <QApplication>
#include <QBuffer>
#include <QWidget>
#include <QtGui>
#include <QIODevice>


class Screenshot : public QWidget
{
    Q_OBJECT
private:
    QString format;
    int w, h;
    QByteArray *screen;
public:
    Screenshot(QString format, int w, int h);
    Screenshot(QByteArray* scr);
    ~Screenshot();

    void setSize(int w, int h);
    void newScreen();
    void setFormat(QString format);

    QString getFormat() { return this->format; }
    QByteArray* getScreen() { return this->screen; }
    int getW() { return w; }
    int getH() { return h; }
};

#endif // SCREENSHOT_H
