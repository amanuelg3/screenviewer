#include "TestScreenshot.h"

#include "screenshot.h"
#include <QtTest/QtTest>



void TestScreenshot::testNew()
{
    Screenshot *a;
    a = new Screenshot("JPG", 800, 600);
    a->newScreen();
    QVERIFY2(a->getScreen() != NULL, "Test if screenshoot");
    delete a;
}

void TestScreenshot::testResize()
{
     Screenshot *a;
     a = new Screenshot("JPG", 800, 600);
     a->setSize(800, 600);
     QVERIFY2(a->getW() == 800, "Test resize width");
     QVERIFY2(a->getH() == 600, "Test resize height");
     a->setSize(-1, 90);
     QVERIFY2(a->getW() == 800, "Test negative resize width");
     QVERIFY2(a->getH() == 90, "Test resize height");
     a->setSize(1, -6);
     QVERIFY2(a->getW() == 1, "Test resize width");
     QVERIFY2(a->getH() == 600, "Test resize negative height");
     a->setSize(-1, -9);
     QVERIFY2(a->getW() == 800, "Test negative resize width");
     QVERIFY2(a->getH() == 600, "Test negative resize height");
     a->setSize(0, 0);
     QVERIFY2(a->getW() == 800, "Test null resize width");
     QVERIFY2(a->getH() == 600, "Test null resize height");
     delete a;
}

void TestScreenshot::testFormat()
{
    Screenshot *a;
    a = new Screenshot("JPG", 800, 600);
    a->setFormat("PNG");
    QVERIFY2(a->getFormat() == "PNG", "Simple format test");
    a->setFormat("");
    QVERIFY2(a->getFormat() == "JPG", "Harder format test");
    delete a;
}
//#ifdef TEST
//QTEST_MAIN(TestScreenshot)
//#include "Testscreenshot.moc"
//#endif
