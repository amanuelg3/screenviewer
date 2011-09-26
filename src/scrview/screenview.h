#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QMainWindow>
#include "capturer.h"
#include "server.h"
#include "client.h"

namespace Ui {
    class ScreenView;
}

class ScreenView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScreenView(QWidget *parent = 0);
    ~ScreenView();

private:
    Ui::ScreenView *ui;
    QTimer *z;
    Capturer *capturer;
    Server *a;
    Client *b;
    bool server;
    bool clicked;

private slots:
    void doTest();
    void on_serverButton_clicked();
    void on_clientButton_clicked();
};

#endif // SCREENVIEW_H
