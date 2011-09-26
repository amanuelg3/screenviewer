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


void testFpm();
void testStart() {
    Capturer *A = new Capturer(800, 600, "png")
}

void testSTOP() {

}

//intervalas min, formatas
