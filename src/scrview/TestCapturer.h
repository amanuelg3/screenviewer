#ifndef TESTCAPTURER_H
#define TESTCAPTURER_H
#include <qobject.h>

class TestCapturer : public QObject
{
Q_OBJECT
private slots:
    void testFpm();
    void testCommon();
    void testStartStop();
};
#endif // TESTCAPTURER_H
