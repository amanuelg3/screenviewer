#include "testconfirmpacket.h"
#include "confirmpacket.h"
#include <QtTest/QtTest>


void TestConfirmPacket::testMake()
{
    ConfirmPacket* tmp = new ConfirmPacket();
    tmp->makePacket();
    QVERIFY2(tmp->getPacket() != NULL, "Test make mouse packet");
    delete tmp;
}


void TestConfirmPacket::testPacketSize()
{
    ConfirmPacket* tmp = new ConfirmPacket();
    tmp->makePacket();
    QVERIFY2(tmp->getSize() == sizeof(quint16), "Test make mouse packet");
    delete tmp;
}


void TestConfirmPacket::testMakeAndGet() {
    ConfirmPacket* tmp = new ConfirmPacket();
    QVERIFY2(tmp->makeAndGetPacket() != NULL, "Test make mouse packet");
    delete tmp;
}
