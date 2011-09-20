#include "screenview.h"
#include "ui_screenview.h"
#include "screenshot.h"

ScreenView::ScreenView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenView)
{
    ui->setupUi(this);
    // TEST to see if screenshot is working.
    Screenshot *A;
    A = new Screenshot("JPG", 800, 600);
    A->newScreen();
    QPixmap B;
    B.loadFromData(*A->getScreen());
    ui->label->setPixmap(B);
    // TEST is over.
}

ScreenView::~ScreenView()
{
    delete ui;
}
