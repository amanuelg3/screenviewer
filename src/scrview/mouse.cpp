#include "mouse.h"

Mouse::Mouse()
{
    pos = QPoint (0, 0);
    setMouseTracking(true);
    isRightKey = false;
    isLeftKey = false;
}

void Mouse::mouseMoveEvent(QMouseEvent *mEvent)
{
    pos = mEvent->pos();
    update();
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
