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
    blockSize = sizeof(md->isRightKey) + sizeof(md->isLeftKey) + sizeof(md->x) + sizeof(md->y) + sizeof(quint16);
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

MouseData* MousePacket::analyzePacket(QDataStream& in)
{
    MouseData* tmp = new MouseData();
    in >> tmp->x;
    in >> tmp->y;
    in >> tmp->isLeftKey;
    in >> tmp->isRightKey;
    return tmp;
}

MouseData* MousePacket::getContent()
{
    return md;
}
