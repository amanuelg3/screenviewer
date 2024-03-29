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

    ui->gbox_login->hide();
    ui->serverButton->hide();
    ui->clientButton->hide();
    this->resize(1024,768);
}


bool ScreenView::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *k = (QMouseEvent *)event;

        Qt::MouseButtons mouseButton = k->button();
        if( mouseButton == Qt::LeftButton )
        {
            mouse->leftClick(true);
        }
        else if( mouseButton == Qt::RightButton )
        {
            mouse->rightClick(true);
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *k = (QMouseEvent *)event;

        Qt::MouseButtons mouseButton = k->button();

        if( mouseButton == Qt::LeftButton )
        {
            mouse->leftClick(false);
        }
        else if( mouseButton == Qt::RightButton )
        {
            mouse->rightClick(false);
        }
    }

    if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent *k = (QMouseEvent *)event;
        mouse->setPos(k->pos());
    }
    return true;
}


void ScreenView::on_clientButton_clicked()
{
    server = false;

    b = new Client(this);
    IPdatabase *ip = new IPdatabase(b);

    //ip->setIP("blA", "aaa");
    ip->getIP(ui->input_user->text(), ui->input_pass->text());

    //Hmz... Right place?
    clicked = true;

    ui->gbox_login->hide();
    ui->serverButton->hide();
    ui->clientButton->hide();
    this->resize(1024,768);
    setMouseTracking(true);
    ui->label->installEventFilter(this);
    ui->label->setMouseTracking(true);

    delete ip;
}
void ScreenView::on_pushButton_clicked()
{
    IPdatabase *ip = new IPdatabase();

    //ip->setIP("blA", "aaa");
    ip->setIP(ui->input_user->text(), ui->input_pass->text());
    //Needs to remove memory leak
}
