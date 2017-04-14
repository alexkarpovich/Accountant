#ifndef APP_SERVICE_H
#define APP_SERVICE_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>

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
};

#endif // APP_SERVICE_H