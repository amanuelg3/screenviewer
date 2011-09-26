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
    if (!clicked)
        return;

    if (server)
    {
        if (capturer->hasScreen())
        {
            a->send(*capturer->getScreen());
        }
    }
    else
    {

        if (b->fetchScreen())
        {
            QPixmap B;
            B.loadFromData(*b->fetchScreen());
            ui->label->setPixmap(B);
        }

    }
}

void ScreenView::on_serverButton_clicked()
{
    server = true;
    a = new Server();
    capturer->start();
    a->listen(QHostAddress::Any, 4200);
    clicked = true;
}

void ScreenView::on_clientButton_clicked()
{
    server = false;
    b = new Client(this);
    b->setHost("127.0.0.1");
    b->connectToHost();
    clicked = true;
}
