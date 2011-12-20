#include "testsspacket.h"
#include "sspacket.h"
#include <QtTest/QtTest>

void TestSsPacket::testMake()
{
    Screenshot *a;
    a = new Screenshot("JPG", 800, 600);
    a->newScreen();
    SsPacket* tmp = new SsPacket();
    tmp->setNewContent(a);
    tmp->makePacket();
    QVERIFY2(tmp->getPacket() != NULL, "Test make screenshoot packet");
    delete a;
    delete tmp;
}


void TestSsPacket::testPacketSize()
{
    Screenshot *a;
    a = new Screenshot("JPG", 800, 600);
    a->newScreen();
    SsPacket* tmp = new SsPacket();
    tmp->setNewContent(a);
    tmp->makePacket();
    QVERIFY2(tmp->getSize() == (quint16)a->getScreen()->size(), "Test make screenshoot packet");
    delete a;
    delete tmp;
}

void TestSsPacket::testEmptyMake()
{
    SsPacket* tmp = new SsPacket();
    tmp->makePacket();
    QVERIFY2(tmp->getPacket() == NULL, "Test empty screenshoot packet");
    delete tmp;
}

void TestSsPacket::testMakeAndGet() {
    Screenshot *a;
    a = new Screenshot("JPG", 800, 600);
    a->newScreen();
    SsPacket* tmp = new SsPacket();
    tmp->setNewContent(a);
    QVERIFY2(tmp->makeAndGetPacket() != NULL, "Test make screenshoot packet");
    delete a;
    delete tmp;
}

void TestSsPacket::testSetNewContent() {
    Screenshot *a;
    a = new Screenshot("JPG", 800, 600);
    a->newScreen();
    SsPacket* tmp = new SsPacket();
    tmp->setNewContent(a);
    QVERIFY2(tmp->getContent() == a, "Test new screenshoot packet content");
    delete a;
    delete tmp;
}
