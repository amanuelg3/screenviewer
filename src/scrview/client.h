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
    bool isDone;
    quint16 blockSize;
    bool canDelete;
public:
    explicit Client(QObject *parent = 0);
    void setHost(QString host);
    QString getHost();
    void connectToHost();
    void disconnect();
    void requestNewFortune();
    void send(QByteArray a);
    bool isMade() { return isDone; }
    void canDel() { canDelete = true; isDone = false; }
    QByteArray* fetchScreen() { isDone = true; return screen; }

signals:

public slots:
    void connected();
    void readyRead();

};

#endif // CLIENT_H
