#ifndef CONFIRMPACKET_H
#define CONFIRMPACKET_H
#include "abstractpacket.h"
#include <QTcpSocket>

class ConfirmPacket : public AbstractPacket
{

public:
    ConfirmPacket();
    void makePacket();
};

#endif // CONFIRMPACKET_H
