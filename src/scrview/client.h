#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QString host;
    QByteArray *screen;
public:
    explicit Client(QObject *parent = 0);
    void setHost(QString host);
    QString getHost();
    void connectToHost();
    void disconnect();
    void send(QByteArray a);
    QByteArray* fetchScreen() { return screen; }

signals:

public slots:
    void connected();
    void readyRead();

};

#endif // CLIENT_H
