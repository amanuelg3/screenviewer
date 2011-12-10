#ifndef MOUSEPACKET_H
#define MOUSEPACKET_H
#include "mouse.h"
#include "abstractpacket.h"
#include <QTcpSocket>

class MousePacket : public AbstractPacket
{
public:
    MousePacket();
    void makePacket();
    void setNewContent(MouseData* md);
    MouseData* getContent();
    static MouseData* analyzePacket(QDataStream& in);
private:
    MouseData* md;
};

#endif // MOUSEPACKET_H
