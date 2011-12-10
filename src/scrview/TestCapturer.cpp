#include "TestCapturer.h"
#include "capturer.h"

#include <QtTest/QtTest>
#include <QThread>



void TestCapturer::testFpm() {}

void TestCapturer::testCommon() {
    Capturer *A = new Capturer(-60, "png", 800, 600);
    A->start();
    delete A;
    A = new Capturer(60, "png", -800, 600);
    A->start();
    delete A;
    A = new Capturer(60, "png", 800, -600);
    A->start();
    delete A;
    A = new Capturer(60, "png", -800, -600);
    A->start();
    delete A;

    A = new Capturer(60, "png", 800, 600);
    QVERIFY2(A->hasScreen() == false, "Makes screen when new object is created");
    A->work();
    QVERIFY2(A->hasScreen() == true, "work() doesn't make screen shot");
    delete A;
}
void TestCapturer::testStartStop() {
    /*
    Capturer *A = new Capturer(60, "png", 800, 600);
    A->start();
    QTest::qSleep(4000);

    QVERIFY2(A->hasScreen() == true, "start() doesn't work");


    QByteArray test = *A->getScreen();
    A->stop();
    QTest::qSleep(2000);
    QVERIFY2(test == *A->getScreen(), "stop() doesn't work");
    delete A;
    */
}
