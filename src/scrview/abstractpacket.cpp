#include "abstractpacket.h"
#include <QByteArray>

AbstractPacket::AbstractPacket()
{
    blockSize =  0;
    currentPacket = NULL;
}

quint16 AbstractPacket::getSize()
{
    return blockSize;
}

QByteArray* AbstractPacket::getPacket()
{
    return currentPacket;
}

QByteArray* AbstractPacket::makeAndGetPacket()
{
    //Delete old packet
    delete currentPacket;
    //Make new packet
    makePacket();
    return getPacket();
}

void AbstractPacket::makePacket(){

}
