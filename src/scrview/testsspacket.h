#ifndef TESTSSPACKET_H
#define TESTSSPACKET_H
#include <qobject.h>

class TestSsPacket : public QObject
{
Q_OBJECT
private slots:

    void testEmptyMake();
    void testMake();
    void testMakeAndGet();
    void testSetNewContent();
    void testPacketSize();
};
#endif // TESTSSPACKET_H
