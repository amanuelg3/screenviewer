#ifndef TESTHOST_H
#define TESTHOST_H

#include <QObject>

class TestHost : public QObject
{
    Q_OBJECT
public:
    explicit TestHost(QObject *parent = 0);

signals:

public slots:

};

#endif // TESTHOST_H
