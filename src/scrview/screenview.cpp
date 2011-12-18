#include "screenview.h"
#include "ui_screenview.h"
#include "IPdatabase.h"

ScreenView::ScreenView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenView)
{
    ui->setupUi(this);

    mouse = new Mouse();
    capturer = new Capturer(60, "JPG", 800, 600);
    z = new QTimer(this);
    //connect(z, SIGNAL(timeout()), this, SLOT(doTest()));
    connect(z, SIGNAL(timeout()), this, SLOT(doMouseTest()));
    z->start(500);
    IPdatabase ip;
    ip.setIP("", "");
    //ip.getIP("", "");
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
            qDebug() << capturer->getScreen()->length();
            a->send(*capturer->getScreen());
        }
    }
    else
    {

        if (b->isMade())// && b->fetchScreen()
        {
            QPixmap B;
            B.loadFromData(*b->fetchScreen());
            b->canDel();
            qDebug() << "Galima istrinti";
            qDebug() << b->fetchScreen()->length();
            ui->label->setPixmap(B);
        }

    }
}

void ScreenView::doMouseTest()
{
    if (!clicked)
        return;

    if (server)
    {

    }
    else
    {
        b->send(mouse->isRightKeyP(), mouse->isLeftKeyP(), mouse->getPos().x(), mouse->getPos().y());
    }
}



void ScreenView::on_serverButton_clicked()
{
    server = true;
    a = new Server();
    capturer->start();
    //listen(QHostAddress::Any, 4200);
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
