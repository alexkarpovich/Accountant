#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>
#include "app_service.h"
#include "user.h"

AppService::AppService(QObject *parent) :
    QObject(parent)
{
    this->prepareFolders();
    this->initDB();
}

void AppService::prepareFolders() {
    QStringList files;
    files << "db.sqlite";

    this->dataLocation = QStandardPaths::standardLocations(QStandardPaths::DataLocation)[0];
    QDir dataDir(this->dataLocation);

    if (!dataDir.exists()) {
        dataDir.mkdir(this->dataLocation);
    }

    QFileInfo dataDirInfo(this->dataLocation);

    if (dataDirInfo.isWritable()) {
        for (int i = 0; i < files.size(); i++) {
            QString filePath = this->dataLocation + "/" + files.at(i);
            QFileInfo fileInfo(filePath);

            if (!fileInfo.exists()) {
                QFile::copy(":/" + files.at(i), filePath);
                QFile::setPermissions(filePath, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
            }
        }
    }

}

void AppService::initDB() {
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(this->dataLocation + "/db.sqlite");

    if (!sdb.open()) {
        qDebug() << sdb.lastError().text();
    }    
}

void AppService::addUser(QString username) {
    qDebug() << username;

    User * user = new User();
    user->setUsername(username);
    user->setActive(true);
    user->save();

    emit userAdded();
}

bool AppService::isLoggedIn() {
    User* activeUser = User::getLoggedIn();

    return activeUser != NULL;
}
