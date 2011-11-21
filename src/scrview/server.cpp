#include "server.h"
#include <QTest>

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
    connect(socket, SIGNAL(readyRead()),
            this, SLOT(readyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }
}

/*
void Server::incomingConnection(int socketfd)
{
    qDebug() << "Gavau klienta";
    blockSize = 0;
    if (!socket)
    {
        socket = new Qsocket(this);
        socket->setSocketDescriptor(socketfd);

        qDebug() << "New client from:" << socket->peerAddress().toString();

        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    }
}
*/

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
    {
        blockSize = 0;
        return;
    }

    /*quint16 type;
    in >> type;

    switch(type)
    {
        case 0:
            bool isLeftKey;
            bool isRightKey;
            quint16 x;
            quint16 y;
            in >> isLeftKey >> isRightKey >> x >> y;
            qDebug() << isLeftKey << " " << isRightKey << " " << x << " " << y << "\n";
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }*/
    blockSize = 0;
    if (socket->bytesAvailable() > 0) readyRead();
}

void Server::disconnected()
{
    delete socket;
    socket = NULL;
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

void Server::listen(QHostAddress::SpecialAddress host, int port)
{
    server->listen(host,port);
}
