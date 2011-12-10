#include <QtGui/QApplication>
#include "screenview.h"

#include <QTest>
#include "TestScreenshot.h"
#include "TestCapturer.h"
#include "TestSsPacket.h"

//#define TEST
//#ifndef TEST
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestScreenshot test1;
    QTest::qExec(&test1, argc, argv);
    TestCapturer test2;
    QTest::qExec(&test2, argc, argv);
    TestSsPacket test3;
    QTest::qExec(&test3, argc, argv);

    ScreenView w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
//#endif
