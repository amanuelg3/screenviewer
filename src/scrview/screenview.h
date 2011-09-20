#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QMainWindow>

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
};

#endif // SCREENVIEW_H
