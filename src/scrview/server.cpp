#include "server.h"

Server::Server()
{
    client = NULL;
}

void Server::incomingConnection(int socketfd)
{
    qDebug() << "gavau klienta";
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

void Server::send(QByteArray a)
{
    if (client)
    {
        qDebug() << "turiu klient'a siunciu jam data.";
        client->write(a);
    }
}
