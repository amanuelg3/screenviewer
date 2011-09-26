#include "capturer.h"
#include <QtTest/QtTest>

class TestCapturer: public QObject
{
    Q_OBJECT
private slots:
    void testFpm();
    void testStart();
    void testSTOP();
};


void TestCapturer::testFpm() {}
void TestCapturer::testStart() {
    Capturer *A = new Capturer(30, "png", 800, 600);
}

void TestCapturer::testSTOP() {

}

//intervalas min, formatas
