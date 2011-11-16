#ifndef MOUSE_H
#define MOUSE_H
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>

class Mouse : public QWidget
{
public:
    Mouse();
    bool isLeftKeyP() { return isLeftKey; }
    bool isRightKeyP() { return isRightKey; }
    QPoint getPos() { return pos; }
private:
    QPoint pos;
    bool isLeftKey;
    bool isRightKey;
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // MOUSE_H
