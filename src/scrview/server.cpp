#include "server.h"

Server::Server()
{
}

void Server::incomingConnection(int socketfd)
{
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
    QTcpSocket *clnt = (QTcpSocket*)sender();
    while(clnt->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        qDebug() << "Read line:" << line;

        clnt->write("You are accepted.");
    }
}
