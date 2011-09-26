#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
private slots:
    void readyRead();
    void disconnected();
public:
    Server();
    void send(QByteArray a);
protected:
    void incomingConnection(int socketfd);
private:
    QTcpSocket *client;
};

#endif // SERVER_H
