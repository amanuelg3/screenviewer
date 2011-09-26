#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QMainWindow>
#include "capturer.h"
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

private slots:
    void doTest();
};

#endif // SCREENVIEW_H
