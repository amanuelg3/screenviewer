#include "sspacket.h"

SsPacket::SsPacket()
{
    ss = NULL;
    type = 0;
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
    out << (quint16) type;
    currentPacket->append(*ss->getScreen());
}

void SsPacket::setNewContent(Screenshot *ss)
{
    delete this->ss;
    this->ss = ss;
}

static Screenshot* analyzePacket(QTcpSocket *socket, quint16 size)
{
    QByteArray* screen = new QByteArray();
     *screen = socket->read(size);
    Screenshot* tmp = new Screenshot(screen);
    return tmp;

}

Screenshot* SsPacket::getContent()
{
    return ss;
}
