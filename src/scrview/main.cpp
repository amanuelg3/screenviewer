#include <QtGui/QApplication>
#include "screenview.h"

#include <QTest>
#include "Testscreenshot.h"
#include "TestCapturer.h"

//#define TEST
//#ifndef TEST
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestScreenshot test1;
    QTest::qExec(&test1, argc, argv);
    TestCapturer test2;
    QTest::qExec(&test2, argc, argv);

    ScreenView w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
//#endif
