#include "screenshot.h"
#include <QtTest/QtTest>

class TestScreenshot: public QObject
{
    Q_OBJECT
private slots:
    void testNew();
};

void TestScreenshot::testNew()
{
    Screenshot *a;
    a->newScreen();
    QVERIFY(a->getScreen() != NULL, "Test if screenshoot");
    delete a;
}

void TestScreenshot::testResize()
{
     Screenshot *a;
     a->setSize(800, 600);
     QVERIFY(a->getW() == 800, "Test resize width");
     QVERIFY(a->getH() == 600, "Test resize height");
     a->setSize(-1, 90);
     QVERIFY(a->getW() == 800, "Test negative resize width");
     QVERIFY(a->getH() == 600, "Test resize height");
     a->setSize(1, -6);
     QVERIFY(a->getW() == 800, "Test resize width");
     QVERIFY(a->getH() == 600, "Test resize negative height");
     a->setSize(-1, -9);
     QVERIFY(a->getW() == 800, "Test negative resize width");
     QVERIFY(a->getH() == 600, "Test negative resize height");
     a->setSize(0, 0);
     QVERIFY(a->getW() == 800, "Test null resize width");
     QVERIFY(a->getH() == 600, "Test null resize height");
     delete a;
}

void TestScreenshot::testFormat()
{
    Screenshot *a;
    a->setFormat("PNG");
    QVERIFY(a->getFormat() == "PNG", "Simple format test");
    a->setFormat("");
    QVERIFY(a->getFormat() == "JPG", "Harder format test");
    delete a;
}

QTEST_MAIN(TestScreenshot)
#include "Testscreenshot.moc"
