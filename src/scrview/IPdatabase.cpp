#include "IPdatabase.h"
#include <QDebug>
#include <QtCore>
#include <QtNetwork>

#define REGISTERIP_URL "http://scrview.albinas.lt/reg.php?user=%1&pass=%2"
#define GETIP_URL "http://scrview.albinas.lt/getip.php?user=%1&pass=%2"
/*
klase, kuri i serva http protokolu kreipiasi ir siuncia
reg.php?ip=[saityno serveris gali suzinot]&user=manokompas&pass=abc123
ir ip, user ir pass iraso i db, ir kita metoda kuris kreipiasi i
getip.php?user=manokompas&pass=abc123 ir gauna ip
*/
IPdatabase::IPdatabase() {
    connect(&networkManagerGet, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(gotIP(QNetworkReply *)));
    connect(&networkManagerSet, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(settedIP(QNetworkReply *)));
}
IPdatabase::IPdatabase(Client *&bb) {
    b = bb;
    connect(&networkManagerGet, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(gotIP(QNetworkReply *)));
    connect(&networkManagerSet, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(settedIP(QNetworkReply *)));
}
void IPdatabase::getIP(QString user, QString pass) {
    QString url = QString(GETIP_URL).arg(user, pass);
    qDebug() << url;
    networkManagerGet.get(QNetworkRequest(QString(url)));// QNetworkReply *reply =
    qDebug() << "request sent to get IP request";
}
void IPdatabase::gotIP(QNetworkReply *networkReply)
{
    if (!networkReply->error()) {
        QString ip(networkReply->readAll());//Response from our server
        qDebug() << "Got IP" << ip;
        if(!ip.isEmpty()) {
            b->setHost(ip);
            //b->setHost("88.222.10.7"); test ip
        } else {
            b->setHost("127.0.0.1");
        }
        b->connectToHost();

        this->ip = ip;
    }

    networkReply->deleteLater();
}



void IPdatabase::setIP(QString user, QString pass) {

    QString url = QString(REGISTERIP_URL).arg(user, pass);
    qDebug() << url;
    networkManagerSet.get(QNetworkRequest(QString(url)));
    qDebug() << "Request sent to save IP into our server database";
}
void IPdatabase::settedIP(QNetworkReply *networkReply)
{
    if (!networkReply->error()) {
        QString response(networkReply->readAll());
        qDebug() << "Setted IP:" << response;
    }

    networkReply->deleteLater();
}
