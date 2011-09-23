#include "screenview.h"
#include "ui_screenview.h"

ScreenView::ScreenView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenView)
{
    ui->setupUi(this);

    capturer = new Capturer(60, "JPG", 800, 600);
    z = new QTimer(this);
    connect(z, SIGNAL(timeout()), this, SLOT(doTest()));
    z->start(500);
}

ScreenView::~ScreenView()
{
    delete ui;
}

void ScreenView::doTest()
{
    capturer->start();
    if (capturer->hasScreen())
    {
        qDebug() << "have screen";
        QPixmap B;
        B.loadFromData(*capturer->getScreen());
        ui->label->setPixmap(B);
    }
}
