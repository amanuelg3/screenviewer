#include "screenview.h"
#include "ui_screenview.h"

ScreenView::ScreenView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenView)
{
    ui->setupUi(this);
}

ScreenView::~ScreenView()
{
    delete ui;
}
