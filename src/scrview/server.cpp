#include "server.h"
#include <QTest>
#include "mousepacket.h"
#include "confirmpacket.h"
#include "sspacket.h"
#include "host.h"

Server::Server(QMutex* scrMutex, QMutex* mouseMutex, Host* parrentHost)
{
    this->scrMutex = scrMutex;
    this->mouseMutex = mouseMutex;
    this->parrentHost = parrentHost;
    blockSize = 0;
    server = new QTcpServer();
    socket = NULL;
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

Server::Server()
{
    blockSize = 0;
    server = new QTcpServer();
    socket = NULL;
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}



void Server::acceptConnection()
{
    qDebug() << "Gavau klienta";
    blockSize = 0;
    if (!socket)
    {
        socket = server->nextPendingConnection();
        parrentHost->start();
        connect(socket, SIGNAL(readyRead()),
                this, SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }
}

void Server::readyRead()
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
        case 1:
            //gavom peles duomenis siunciam juos ispakavimui ir liepiam apdoroti
            parrentHost->takeMouseData(MousePacket::analyzePacket(in));
            mouseMutex->unlock();
            break;
        case 2:
            //galim siusti nauja screenshot
            scrMutex->unlock();
            break;
        default:
            break;
    }
    blockSize = 0;
    if (socket->bytesAvailable() > 0) readyRead();
}

void Server::disconnected()
{
    delete socket;
    socket = NULL;
    parrentHost->takeClient();
    qDebug() << "Client disconnected!\n";
}

void Server::send(QByteArray data)
{
    if(socket == NULL) return;
    if(socket->state() != QAbstractSocket::ConnectedState ) return;

    QByteArray tmp;
    QDataStream out(&tmp, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << (quint16) data.size();
    qDebug() << "Issiunciam: " << (quint16) data.size();

    tmp.append(data);
    //qDebug() << "Issiunciam: " << (quint32) tmp.size();


    socket->write(tmp);
    socket->flush();
}

void Server::sendPacket(QByteArray data)
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



void Server::listen(QHostAddress::SpecialAddress host, int port)
{
    server->listen(host,port);
}
