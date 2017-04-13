#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>

#include "app.h"

App::App()
{
    this->dataLocation = QStandardPaths::standardLocations(QStandardPaths::DataLocation)[0];
}

void App::init() {
    this->prepareDirectories();
    this->initDatabase();
}

void App::prepareDirectories() {
    QStringList files;
    files << "db.sqlite";

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

bool App::initDatabase() {
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(this->dataLocation + "/db.sqlite");

    if (!sdb.open()) {
        qDebug() << sdb.lastError().text();
        return false;
    } else {
        return true;
    }
}
