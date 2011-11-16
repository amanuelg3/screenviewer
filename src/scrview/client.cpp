#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    screen = NULL;
    blockSize = 0;
    socket = new QTcpSocket(this);
    isDone = false;
    canDelete = true;

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}


void Client::connected()
{
    socket->write(QString("Connected :P").toUtf8());
}

void Client::readyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
        qDebug() << "Tikiuosi gauti blockSize dydzio paveiksliuka:" << blockSize;
    }

    qDebug() << "Baitu laukia eileje:" << socket->bytesAvailable();
    if (socket->bytesAvailable() < blockSize)
        return;

    if(canDelete) {
        canDelete = false;

        isDone = false;
        screen = new QByteArray();
        *screen = socket->read(blockSize);
        isDone = true;

        qDebug() << "Tokio dydzio paveiksliuka nuskaiciau:" << screen->size();


        blockSize = 0;
    }


    /*
    if (newScreen == currentScreen) {
        QTimer::singleShot(0, this, SLOT(requestNewFortune()));
        return;
    }
    currentScreen = newScreen;
    */
}

void Client::requestNewFortune() {
    blockSize = 0;
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
