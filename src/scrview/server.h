#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMutex>

class Host;

class Server : public QObject
{
    Q_OBJECT
public slots:
    void readyRead();
    void disconnected();
    void acceptConnection();
public:
    Server();
    Server(QMutex* scrMutex, QMutex* mouseMutex, Host* parrentHost);
    void send(QByteArray data);
    void sendPacket(QByteArray data);
    void listen(QHostAddress::SpecialAddress host, int port);
private:
    quint16 blockSize;
    QTcpSocket *socket;
    QTcpServer *server;
    QMutex* scrMutex;
    QMutex* mouseMutex;
    Host* parrentHost;


};

#endif // SERVER_H
