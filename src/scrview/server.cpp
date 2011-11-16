#include "server.h"
#include <QTest>

Server::Server()
{
    socket = NULL;
}

void Server::incomingConnection(int socketfd)
{
    qDebug() << "Gavau klienta";
    if (!socket)
    {
        socket = new QTcpSocket(this);
        socket->setSocketDescriptor(socketfd);

        qDebug() << "New client from:" << socket->peerAddress().toString();

        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }
}

void Server::readyRead()
{
    /*
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
    *screen = socket->read(blockSize);
    isDone = true;
    qDebug() << "Tokio dydzio paveiksliuka nuskaiciau:" << screen->size();
    blockSize = 0;
    */

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
    out << (quint32) data.size();
    qDebug() << "Issiunciam: " << (quint32) data.size();

    tmp.append(data);
    //qDebug() << "Issiunciam: " << (quint32) tmp.size();


    socket->write(tmp);
    socket->flush();
}

