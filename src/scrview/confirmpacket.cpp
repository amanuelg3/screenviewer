#include "confirmpacket.h"

ConfirmPacket::ConfirmPacket()
{
    type = 2;
}

void ConfirmPacket::makePacket() {
    currentPacket = new QByteArray();
    QDataStream out(currentPacket, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    blockSize = sizeof(quint16);
    out << (quint16) blockSize;
    out << (quint16) type;
}
