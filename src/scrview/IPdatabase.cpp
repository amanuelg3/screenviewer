#include "IPdatabase.h"
#include<QDebug>
/*
klase, kuri i serva http protokolu kreipiasi ir siuncia
reg.php?ip=[saityno serveris gali suzinot]&user=manokompas&pass=abc123
ir ip, user ir pass iraso i db, ir kita metoda kuris kreipiasi i
getip.php?user=manokompas&pass=abc123 ir gauna ip
*/

IPdatabase::IPdatabase() {
        connect(&http, SIGNAL(done(bool)), this, SLOT(done(bool)));
}
void IPdatabase::getIP(QString user, QString pass) {
         QHttp * http2 = new QHttp(this);
         connect(http2, SIGNAL(done(bool)), this, SLOT(done(bool)));
         http2->setHost("scrview.albinas.lt");

         QHttpRequestHeader header("GET", "reg.php");
         header.setValue("Host", "scrview.albinas.lt:80");

         http2->request(header);
         qDebug() << "KIK";
}
bool IPdatabase::setIP(QString user, QString pass) {
    QHttpRequestHeader header("GET", "/reg");
    qDebug() << QUrl::toPercentEncoding("/reg.php?user=manokompas&pass=abc123");
    //screenviewer.xn--kstutis-98a.lt
    //
    header.setValue("Host", "scrview.albinas.lt");
    http.setHost("scrview.albinas.lt");
    http.request(header);
    qDebug() << "Register an IP address";
    return false;
}
void IPdatabase::done(bool error)
{
   qDebug() << "1 Register an IP address";
    if (error)
        qDebug() << "error: " << http.errorString() << http.error();
    else {
        QString result(http.readAll());
        qDebug() << result;
    }
    qDebug() << "2 Register an IP address";


}
