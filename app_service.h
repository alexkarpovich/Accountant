#ifndef APP_SERVICE_H
#define APP_SERVICE_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QList>
#include "models/account_model.h"

class AppService : public QObject
{
    Q_OBJECT
protected:
    QString dataLocation;
    QSqlDatabase sdb;

    void prepareFolders();
    void initDB();
public:
    explicit AppService(QObject *parent = 0);

signals:
    void userAdded();

public slots:

    void addUser(QString username);
    QList<QObject*> getAccountList();
    bool isLoggedIn();
};

#endif // APP_SERVICE_H
