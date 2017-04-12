#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QFileDevice>
#include <QStandardPaths>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("/home/akarpovich/dev/qt/Accountant/db.sqlite");

    if (!sdb.open()) {
        qDebug() << sdb.lastError().text();
    }

    QSqlQuery query;

    query.exec("select * from sqlite_sequence");
    while(query.next()) {
        qDebug() << query.value(0).toString();
    }

    QFile::copy(":/db.sqlite", "/home/akarpovich/db.sqlite");
    QFile::setPermissions("/home/akarpovich/db.sqlite", QFileDevice::ReadOwner | QFileDevice::WriteOwner);

    qDebug() << QStandardPaths::standardLocations(QStandardPaths::DataLocation);

    return app.exec();
}
