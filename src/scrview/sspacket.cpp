#include "sspacket.h"
#include <QTcpSocket>

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
    currentPacket->append(*ss);
}

void SsPacket::setNewContent(QByteArray *ss)
{
    delete this->ss;
    this->ss = ss;
}

static QByteArray* analyzePacket(QDataStream* in)
{
    Screenshot* tmp;
    QByteArray* screen;
    i
}

QByteArray* SsPacket::getContent()
{
    return ss;
}
