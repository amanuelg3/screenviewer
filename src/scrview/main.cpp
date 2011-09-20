#include <QtGui/QApplication>
#include "screenview.h"


#ifdef A
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScreenView w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
#endif