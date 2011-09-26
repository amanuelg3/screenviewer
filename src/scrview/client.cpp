#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    screen = NULL;
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}


void Client::connected()
{
    socket->write(QString("Connected :P").toUtf8());
}

void Client::readyRead()
{
    while(socket->canReadLine())
    {
        if (screen)
            delete screen;
        screen = new QByteArray(socket->readLine());
        qDebug() << "skaitau.";
        //screen = *socket->readAll();
    }
}

void Client::connectToHost()
{
    socket->connectToHost(host, 4200);
}

void Client::disconnect()
{
    socket->disconnect();
}

void Client::setHost(QString host)
{
    this->host = host;
}

QString Client::getHost()
{
    return this->host;
}

void Client::send(QByteArray a)
{
    socket->write(a);
}
