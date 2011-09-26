#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class server : public QTcpServer
{
private slots:
    void readyRead();
    void disconnected();
public:
    server();
protected:
    void incomingConnection(int socketfd);
private:
    QTcpSocket *client;
};

#endif // SERVER_H
