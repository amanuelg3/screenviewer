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
    //http = new QHttp(this);
    //connect(http, SIGNAL(done(bool)), this, SLOT(done(bool)));
    connect(&networkManagerGet, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(gotIP(QNetworkReply *)));
    connect(&networkManagerSet, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(settedIP(QNetworkReply *)));
}
void IPdatabase::getIP(QString user, QString pass) {
    QString url = QString(GETIP_URL).arg(user, pass);
    qDebug() << url;
    networkManagerGet.get(QNetworkRequest(QString(url)));
    qDebug() << "request sent to get IP request";
    /*
     QHttp * http2 = new QHttp(this);
     connect(http2, SIGNAL(done(bool)), this, SLOT(done(bool)));
     http2->setHost("scrview.albinas.lt");

     QHttpRequestHeader header("GET", QUrl::toPercentEncoding("/reg.php?user=manokompas&pass=abc123"));
     header.setValue("Host", "scrview.albinas.lt:80");

     http2->request(header);
     qDebug() << "End of getIP()";
     */
}
void IPdatabase::setIP(QString user, QString pass) {
    /*
    QHttpRequestHeader header("GET", QUrl::toPercentEncoding("/reg.php?user=manokompas&pass=abc123"));
    //QHttpRequestHeader header("GET", QUrl::toPercentEncoding("/getip.php?user=manokompas&pass=abc123"));
    qDebug() << QUrl::toPercentEncoding("/reg.php?user=manokompas&pass=abc123");
    //screenviewer.xn--kstutis-98a.lt
    //
    header.setValue("User-Agent", "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-GB; rv:1.9.0.4) Gecko/2008102920 "
        "Firefox/3.0.4 (.NET CLR 3.5.30729)");

    header.setValue("Accept-Language", "en-gb,en;q=0.5");
    header.setValue("Accept-Encoding", "gzip,deflate");
    header.setValue("Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.7");
    header.setValue("Keep-Alive", "300");
    header.setValue("Connection", "keep-alive");

    http->setHost("scrview.albinas.lt");

    header.setValue("Host", "scrview.albinas.lt");
    //qDebug() << http->request(header);
    //http->setHost()
    //http->get()
    //http->close();
     QBuffer m_buffer;
     qDebug() << "aaa" << http->get(QUrl::toPercentEncoding("scrview.albinas.lt/reg.php?user=manokompas&pass=abc123"), &m_buffer);
    qDebug() << "Register an IP address";
    */

    /*
    http = new QHttp(this);
    connect(http, SIGNAL(done(int, bool)),this, SLOT(done(int, bool)));

    int id = http->setHost("www.google.de"); // id == 1
        qDebug() << "setHost id=" << id;
    qDebug() << "get " << http->get("/index.html", &m_buffer);
    */

    QString url = QString(REGISTERIP_URL).arg(user, pass);
    qDebug() << url;
    networkManagerSet.get(QNetworkRequest(QString(url)));
    qDebug() << "request sent to save IP into our server database";
}

void IPdatabase::gotIP(QNetworkReply *networkReply)
{
    if (!networkReply->error()) {
        QString ip(networkReply->readAll());//Response from our server
        qDebug() << "Got IP" << ip;
    }

    networkReply->deleteLater();
}
void IPdatabase::settedIP(QNetworkReply *networkReply)
{
    if (!networkReply->error()) {
        QString response(networkReply->readAll());
        qDebug() << "Setted IP:" << response;
    }

    networkReply->deleteLater();
}


/*
void IPdatabase::done(int requestId, bool error)
{
   qDebug() << "1 Register an IP address";
    if (error)
        qDebug() << "error: " << http->errorString() << http->error();
    else {
        //QString result(http->readAll());
        //qDebug() << result;
    }
    qDebug() << "2 Register an IP address";


}
*/
