#ifndef IPDATABASE_H
#define IPDATABASE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>

#include "client.h"

class IPdatabase : public QObject
{
    Q_OBJECT
public:
    IPdatabase();
    IPdatabase(Client *&bb);

public slots:
    void setIP(QString user, QString pass);
    void getIP(QString user, QString pass);
    void settedIP(QNetworkReply *networkReply);
    void gotIP(QNetworkReply *networkReply);
//protected slots:
//    virtual void finished();
private:
    //QHttp *http;
    //QBuffer m_buffer;
    QNetworkAccessManager networkManagerGet;
    QNetworkAccessManager networkManagerSet;
   // QEventLoop loop;
    QString ip;
    Client *b;
};

#endif // IPDATABASE_H
