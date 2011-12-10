#ifndef MOUSEPACKET_H
#define MOUSEPACKET_H
#include "mouse.h"

class MousePacket : public AbstractPacket
{
public:
    MousePacket();
    void makePacket();
    void setNewContent(MouseData* md);
    MouseData* getContent();
private:
    MouseData* md;
};

#endif // MOUSEPACKET_H
