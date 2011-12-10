#ifndef SSPACKET_H
#define SSPACKET_H
#include "screenshot.h"
#include "abstractpacket.h"
#include <QTcpSocket>

class SsPacket : public AbstractPacket
{
public:
    SsPacket();
    void makePacket();
    void setNewContent(Screenshot* ss);
    static Screenshot* analyzePacket(QTcpSocket *socket, quint16 size);
    Screenshot* getContent();
private:
    Screenshot* ss;
};

#endif // SSPACKET_H
