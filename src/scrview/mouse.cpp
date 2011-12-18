#include "mouse.h"

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

static void setMouseState(int x, int y, bool left, bool right)
{

}
