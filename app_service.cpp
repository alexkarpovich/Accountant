#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>
#include <QUuid>
#include "app_service.h"
#include "user.h"
#include "accountant.h"

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
    User * user = new User();
    user->setUsername(username);
    user->setActive(true);
    user->save();

    Accountant * accountant = new Accountant();
    accountant->setName(QUuid::createUuid().toString());
    accountant->save();

    accountant->linkUser(user);

    emit userAdded();
}

bool AppService::isLoggedIn() {
    User* activeUser = User::getLoggedIn();

    return activeUser != NULL;
}

QList<QObject*> AppService::getAccountList() {
    QList<QObject*> accountList;

    User * activeUser = User::getLoggedIn();
    QVector<Account*> accounts = Account::getByUserId(activeUser->getId());

    for (int i = 0; i < accounts.size(); i++) {
        accountList.append(accounts.at(i)->toModel());
    }

    return accountList;
}
