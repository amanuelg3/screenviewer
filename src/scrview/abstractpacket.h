#ifndef ABSTRACTPACKET_H
#define ABSTRACTPACKET_H
#include <QByteArray>

#include <QObject>

class AbstractPacket : public QObject
{
    Q_OBJECT
public:
    AbstractPacket();
    virtual void makePacket();
    QByteArray* makeAndGetPacket();
    QByteArray* getPacket();
    quint16 getSize();

protected:
    quint16 blockSize;
    QByteArray* currentPacket;
};

#endif // ABSTRACTPACKET_H
