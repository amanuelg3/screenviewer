#ifndef MOUSE_H
#define MOUSE_H
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

struct MouseData {
    MouseData(){}
    MouseData(quint16 x, quint16 y, bool l, bool r) {
        this->x = x;
        this->y = y;
        this->isLeftKey = l;
        this->isRightKey = r;
    }

    quint16 x;
    quint16 y;
    bool isLeftKey;
    bool isRightKey;
};

class Mouse : public QWidget
{
public:
    Mouse(QWidget *parent = 0);
    bool isLeftKeyP() { return isLeftKey; }
    bool isRightKeyP() { return isRightKey; }
    QPoint getPos() { return QCursor::pos(); }
    MouseData* formPacketData();
    void setPos(QPoint pos) { this->pos = pos; qDebug() << "x: " << pos.x(); }
    void rightClick(bool t) { isRightKey = t; }
    void leftClick(bool t) { isLeftKey = t; }
    void setMouseState(int x, int y, bool left, bool right);
private:
    QPoint pos;
    bool isLeftKey;
    bool isRightKey;
};

#endif // MOUSE_H
