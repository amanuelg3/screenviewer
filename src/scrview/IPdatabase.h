#ifndef IPDATABASE_H
#define IPDATABASE_H

#include <QHttp>
#include <QUrl>

class IPdatabase : public QObject
{
    Q_OBJECT
public:
    IPdatabase();
    void getIP(QString user, QString pass);
    bool setIP(QString user, QString pass);
private slots:
    void done(bool error);
private:
    QHttp http;
};

#endif // IPDATABASE_H
