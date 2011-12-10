#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public slots:
    void readyRead();
    void disconnected();
    void acceptConnection();
public:
    Server();
    void send(QByteArray data);
    void listen(QHostAddress::SpecialAddress host, int port);
private:
    quint16 blockSize;

    QTcpSocket *socket;
    QTcpServer *server;

};

#endif // SERVER_H
