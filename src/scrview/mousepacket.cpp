#include "mousepacket.h"

MousePacket::MousePacket()
{
    md = NULL;
    type = 1;
}

void MousePacket::makePacket()
{
    if (md == NULL) {
        currentPacket = NULL;
        return;
    }
    currentPacket = new QByteArray();
    QDataStream out(currentPacket, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    blockSize = md->getScreen()->size();
    out << (quint16) blockSize;
    out << (quint16) type;
    out << md->x;
    out << md->y;
    out << md->isLeftKey;
    out << md->isRightKey;
}

void MousePacket::setNewContent(MouseData *md)
{
    delete this->md;
    this->md = md;
}

static MouseData* MousePacket::analyzePacket(QDataStream& in)
{
    MouseData* tmp;
    in >> tmp->x;
    in >> tmp->y;
    in >> tmp->isLeftKey;
    in >> tmp->isRightKey;
    return tmp;
}

MouseData* SsPacket::getContent()
{
    return md;
}
