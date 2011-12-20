#ifndef IPDATABASE_H
#define IPDATABASE_H

//#include <QHttp>
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QBuffer>

#include <QEventLoop>

class IPdatabase : public QObject
{
    Q_OBJECT
public:
    IPdatabase();

public slots:
    void setIP(QString user, QString pass);
    void getIP(QString user, QString pass);
    void settedIP(QNetworkReply *networkReply);
    void gotIP(QNetworkReply *networkReply);
    //void done(int requestId, bool error);
private:
    //QHttp *http;
    //QBuffer m_buffer;
    QNetworkAccessManager networkManagerGet;
    QNetworkAccessManager networkManagerSet;
};

#endif // IPDATABASE_H
