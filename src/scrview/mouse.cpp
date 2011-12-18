#include "mouse.h"
#include <windows.h>

Mouse::Mouse(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    pos = QPoint (0, 0);
    isRightKey = false;
    isLeftKey = false;
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

void Mouse::setMouseState(int x, int y, bool left, bool right)
{
    QCursor::setPos(x,y);
    if (left)
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 1, 1, 0, 0);
    if (right)
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 1, 1, 0, 0);
}
