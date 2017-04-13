#ifndef APP_H
#define APP_H

#include <QString>
#include <QSqlDatabase>

class App
{
protected:
    QSqlDatabase sdb;
    QString dataLocation;
public:
    App();
    void init();
    void prepareDirectories();
    bool initDatabase();
};

#endif // APP_H
