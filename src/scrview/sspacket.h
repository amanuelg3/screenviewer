#ifndef SSPACKET_H
#define SSPACKET_H
#include "screenshot.h"
#include "abstractpacket.h"

class SsPacket : public AbstractPacket
{
public:
    SsPacket();
    void makePacket();
    void setNewContent(Screenshot* ss);
    Screenshot* getContent();
private:
    Screenshot* ss;
};

#endif // SSPACKET_H
