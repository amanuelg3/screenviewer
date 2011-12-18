#include "mouse.h"

Mouse::Mouse(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    pos = QPoint (0, 0);
    isRightKey = false;
    isLeftKey = false;
    installEventFilter(this);
}

MouseData* Mouse::formPacketData()
{
    MouseData* tmp = new MouseData();
    tmp->x = pos.x();
    tmp->y = pos.y();
    tmp->isRightKey = isRightKeyP();
    tmp->isLeftKey = isLeftKeyP();
    return tmp;
}

bool Mouse::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *k = (QMouseEvent *)event;

        Qt::MouseButtons mouseButton = k->button();
        if( mouseButton == Qt::LeftButton )
        {
            isLeftKey = true;
        }
        else if( mouseButton == Qt::RightButton )
        {
            isRightKey = true;
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *k = (QMouseEvent *)event;

        Qt::MouseButtons mouseButton = k->button();

        if( mouseButton == Qt::LeftButton )
        {
            isLeftKey = false;
        }
        else if( mouseButton == Qt::RightButton )
        {
            isRightKey = false;
        }
    }
    return true;
}

static void setMouseState(int x, int y, bool left, bool right)
{

}
