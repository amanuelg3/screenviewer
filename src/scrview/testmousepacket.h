#ifndef TESTMOUSEPACKET_H
#define TESTMOUSEPACKET_H
#include <qobject.h>

class TestMousePacket : public QObject
{
Q_OBJECT
private slots:
    void testEmptyMake();
    void testMake();
    void testMakeAndGet();
    void testSetNewContent();
    void testPacketSize();
};

#endif // TESTMOUSEPACKET_H
