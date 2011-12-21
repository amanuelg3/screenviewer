#include "client.h"
#include "viewer.h"
#include "sspacket.h"

Client::Client(QObject *parent, Viewer* parrentViewer, QMutex* scrMutex, QMutex* mouseMutex) :
    QObject(parent)
{
    screen = NULL;
    blockSize = 0;
    socket = new QTcpSocket(this);
    isDone = false;
    canDelete = true;
    this->scrMutex = scrMutex;
    this->mouseMutex = mouseMutex;
    this->parrentViewer = parrentViewer;
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}


void Client::connected()
{
    parrentViewer->start();
}

void Client::readyRead()
{
    if (socket == NULL) return;
    if ( socket->state() != QAbstractSocket::ConnectedState ) return;

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_2);
    //in.setVersion( in.version() ); // set to the current Qt version instead

    qDebug() << "skaitau paketa " << blockSize;
    if (blockSize == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16)) return;
        in >> blockSize;
        qDebug() << "Tikiuosi gauti blockSize dydzio paketa:" << blockSize;
    }

    qDebug() << "Baitu laukia eileje:" << socket->bytesAvailable() << " reikia " << blockSize;
    if (socket->bytesAvailable() < blockSize)
        return;

    quint16 type;
    in >> type;

    switch(type)
    {
        case 0:
            //gavom peles duomenis siunciam juos ispakavimui ir liepiam apdoroti
            parrentViewer->takeScreenshot(SsPacket::analyzePacket(socket, blockSize));
            scrMutex->unlock();
            break;
        default:
            break;
    }
    blockSize = 0;
    if (socket->bytesAvailable() > 0) readyRead();
}

void Client::requestNewFortune() {
    blockSize = 0;
}

void Client::connectToHost()
{
    qDebug() << "Bandom connect to host" << host;
    socket->connectToHost(host, 4200);
    qDebug() << "Connected";
}

void Client::disconnect()
{
    socket->disconnect();
    parrentViewer->stop();
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


void Client::sendPacket(QByteArray data)
{
    if(socket == NULL) return;
    if(socket->state() != QAbstractSocket::ConnectedState ) return;

    QByteArray tmp;
    QDataStream out(&tmp, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    tmp.append(data);
    //qDebug() << "Issiunciam: " << (quint32) tmp.size();
    socket->write(tmp);
    socket->flush();
}

/* OLD CODE










  */

void Client::send(bool isRight, bool isLeft, quint16 x, quint16 y)
{
    if(socket == NULL) return;
    if(socket->state() != QAbstractSocket::ConnectedState ) return;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    quint16 size = sizeof(isRight) + sizeof(isLeft) + sizeof(x) + sizeof(y) + sizeof(quint16);
    out << size; //paketo dydis
    out << (quint16) 0; //tipas
    out << isRight;
    out << isLeft;
    out << x;
    out << y;

    qDebug() << "Issiunciam peles coord: " << (quint16)block.size() << " blocksize " << size;

    socket->write(block);
    socket->flush();
}
