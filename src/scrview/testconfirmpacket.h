#ifndef TESTCONFIRMPACKET_H
#define TESTCONFIRMPACKET_H

#include <QObject>

class TestConfirmPacket : public QObject
{
    Q_OBJECT
private slots:
    void testMake();
    void testMakeAndGet();
    void testPacketSize();
};

#endif // TESTCONFIRMPACKET_H
