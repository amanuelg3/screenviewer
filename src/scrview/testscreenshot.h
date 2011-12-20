#ifndef TESTSCREENSCHOT_H
#define TESTSCREENSCHOT_H
#include <qobject.h>
class TestScreenshot: public QObject
{
    Q_OBJECT
private slots:
    void testNew();
    void testResize();
    void testFormat();
};
#endif // TESTSCREENSCHOT_H
