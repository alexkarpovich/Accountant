#ifndef APP_H
#define APP_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QQmlApplicationEngine>

class App: public QObject
{
    Q_OBJECT

protected:
    QSqlDatabase sdb;
    QString dataLocation;
public:
    explicit App(QObject *parent = 0);
    void initialize();
    void prepareDirectories();
    bool initDatabase();
};

#endif // APP_H
