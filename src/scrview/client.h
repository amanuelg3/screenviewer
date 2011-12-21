#ifndef CLIENT_H
#define CLIENT_H
#include <QThread>
#include <QMutex>
#include <QObject>
#include <QTcpSocket>

class Viewer;

class Client : public QObject
{
    Q_OBJECT
private:
    QMutex* scrMutex;
    QMutex* mouseMutex;
    QTcpSocket *socket;
    QString host;
    QByteArray *screen;
    bool isDone;
    quint16 blockSize;
    bool canDelete;
    Viewer* parrentViewer;
public:
    explicit Client(QObject *parent = 0, Viewer* parrentViewer, QMutex* scrMutex, QMutex* mouseMutex);
    void sendPacket(QByteArray data);
    void setHost(QString host);
    QString getHost();
    void connectToHost();
    void disconnect();
    void requestNewFortune();
    void send(QByteArray a);
    bool isMade() { return isDone; }
    void canDel() { canDelete = true; isDone = false; }
    QByteArray* fetchScreen() { isDone = true; return screen; }
    void send(bool isRight, bool isLeft, quint16 x, quint16 y);

signals:

public slots:
    void connected();
    void readyRead();

};

#endif // CLIENT_H
