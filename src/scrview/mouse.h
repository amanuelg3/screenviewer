#ifndef MOUSE_H
#define MOUSE_H
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>

struct MouseData {
    MouseData(){}
    MouseData(int x, int y, bool l, bool r) {
        this->x = x;
        this->y = y;
        this->isLeftKey = l;
        this->isRightKey = r;
    }

    int x;
    int y;
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
    static void setMouseState(int x, int y, bool left, bool right);
private:
    QPoint pos;
    bool isLeftKey;
    bool isRightKey;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MOUSE_H
