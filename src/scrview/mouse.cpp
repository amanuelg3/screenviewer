#include "mouse.h"

Mouse::Mouse()
{
    pos = QPoint (0, 0);
    isRightKey = false;
    isLeftKey = false;
}

void Mouse::mouseMoveEvent(QMouseEvent *mEvent)
{
    pos = mEvent->pos();
    update();
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

void Mouse::mousePressEvent (QMouseEvent *mEvent)
{
    switch (mEvent->button())
    {
        case Qt::LeftButton:
            isLeftKey = true;
            break;
        case Qt::RightButton:
            isRightKey = true;
            break;
        default:
            break;
    }
}

void Mouse::mouseReleaseEvent(QMouseEvent *mEvent)
{
    switch (mEvent->button())
    {
        case Qt::LeftButton:
            isLeftKey = false;
            break;
        case Qt::RightButton:
            isRightKey = false;
            break;
        default:
            break;
    }
}

static void setMouseState(int x, int y, bool left, bool right)
{

}
