#include "testmousepacket.h"
#include "mousepacket.h"
#include <QtTest/QtTest>


void TestMousePacket::testMake()
{
    MouseData *a;
    a = new MouseData(100, 100, true, false);
    MousePacket* tmp = new MousePacket();
    tmp->setNewContent(a);
    tmp->makePacket();
    QVERIFY2(tmp->getPacket() != NULL, "Test make mouse packet");
    delete a;
    delete tmp;
}


void TestMousePacket::testPacketSize()
{
    MouseData *a;
    a = new MouseData(100, 100, true, false);
    MousePacket* tmp = new MousePacket();
    tmp->setNewContent(a);
    tmp->makePacket();
    quint16 size = sizeof(a->isRightKey) + sizeof(a->isLeftKey) + sizeof(a->x) + sizeof(a->y)+ sizeof(quint16);
    QVERIFY2(tmp->getSize() == size, "Test make mouse packet");
    delete a;
    delete tmp;
}

void TestMousePacket::testEmptyMake()
{
    MousePacket* tmp = new MousePacket();
    tmp->makePacket();
    QVERIFY2(tmp->getPacket() == NULL, "Test empty mouse packet");
    delete tmp;
}

void TestMousePacket::testMakeAndGet() {
    MouseData *a;
    a = new MouseData(100, 100, true, false);
    MousePacket* tmp = new MousePacket();
    tmp->setNewContent(a);
    QVERIFY2(tmp->makeAndGetPacket() != NULL, "Test make mouse packet");
    delete a;
    delete tmp;
}

void TestMousePacket::testSetNewContent() {
    MouseData *a;
    a = new MouseData(100, 100, true, false);
    MousePacket* tmp = new MousePacket();
    tmp->setNewContent(a);
    QVERIFY2(tmp->getContent() == a, "Test new mouse packet content");
    delete a;
    delete tmp;
}
