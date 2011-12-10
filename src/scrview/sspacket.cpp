#include "sspacket.h"

SsPacket::SsPacket()
{
    ss = NULL;
}

void SsPacket::makePacket()
{
    if (ss == NULL) {
        currentPacket = NULL;
        return;
    }
    currentPacket = new QByteArray();
    QDataStream out(currentPacket, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    blockSize = ss->getScreen()->size();
    out << (quint16) blockSize;
    currentPacket->append(*ss->getScreen());
}

void SsPacket::setNewContent(Screenshot *ss)
{
    delete this->ss;
    this->ss = ss;
}


Screenshot* SsPacket::getContent()
{
    return ss;
}
