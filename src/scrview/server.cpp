#include "server.h"
#include <QTest>

Server::Server()
{
    client = NULL;
}

void Server::incomingConnection(int socketfd)
{
    qDebug() << "Gavau klienta";
    if (!client)
    {
        client = new QTcpSocket(this);
        client->setSocketDescriptor(socketfd);

        qDebug() << "New client from:" << client->peerAddress().toString();

        connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }
}

void Server::readyRead()
{

}

void Server::disconnected()
{
    delete client;
    client = NULL;
    qDebug() << "Client disconnected!\n";
}

void Server::send(QByteArray data)
{
    /*if (client && (client->bytesToWrite() == 0))
    {
        //client->write(a.size());
        //client->write()
        qDebug() << "turiu klient'a siunciu jam data.";
        client->write(a);
        client->write(QByteArray("done"));
        //qSleep(10000);
        //QTest::qSleep(1000);
    }*/
    if(client == NULL) return;
    if(client->state() != QAbstractSocket::ConnectedState ) return;

    QByteArray tmp;
    QDataStream out(&tmp, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << (quint32) data.size();
    qDebug() << "Issiunciam: " << (quint32) data.size();

    tmp.append(data);
    //qDebug() << "Issiunciam: " << (quint32) tmp.size();


    client->write(tmp);
    client->flush();
}
