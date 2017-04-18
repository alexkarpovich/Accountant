#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include "user.h"

User::User()
{

}

int User::getId() {
    return this->id;
}

QString User::getUsername() {
    return this->username;
}

QString User::getEmail() {
    return this->email;
}

QString User::getFirstName() {
    return this->firstName;
}

QString User::getLastName() {
    return this->lastName;
}

bool User::getActive() {
    return this->active;
}

void User::setId(int id) {
    this->id = id;
}

void User::setUsername(QString username) {
    this->username = username;
}

void User::setEmail(QString email) {
    this->email = email;
}

void User::setFirstName(QString firstName) {
    this->firstName = firstName;
}

void User::setLastName(QString lastName) {
    this->lastName = lastName;
}

void User::setActive(bool active) {
    this->active = active;
}

void User::save() {
    QString sql;
    this->createdAt = this->updatedAt = QDateTime::currentDateTime();

    if (this->id == 0) {
        sql = "INSERT INTO user (username, email, first_name, last_name, active, created_at, updated_at) "
                  "VALUES(:username, :email, :first_name, :last_name, :active, :created_at, :updated_at)";
    } else {
        sql = "UPDATE user SET (username, email, first_name, last_name, active, updated_at) VALUES(:username, :email, :first_name, :last_name, :active, :updated_at) WHERE id=:id";
    }

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QVariant(this->id));
    query.bindValue(":username", this->username);
    query.bindValue(":email", this->email);
    query.bindValue(":first_name", this->firstName);
    query.bindValue(":last_name", this->lastName);
    query.bindValue(":active", this->active);
    query.bindValue(":created_at", this->createdAt.toTime_t());
    query.bindValue(":updated_at", this->updatedAt.toTime_t());

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }
}

User* User::getUserById(int id) {
    QString sql = "SELECT * FROM user WHERE id=:id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QVariant(id));

    if (!query.exec()) {
        qDebug() << query.lastError();
    } else if (query.size() > 0){
        User * user = new User();
        user->setId(query.value(0).toInt());
        user->setUsername(query.value(1).toString());
        user->setEmail(query.value(2).toString());
        user->setFirstName(query.value(3).toString());
        user->setLastName(query.value(4).toString());
        user->setActive(query.value(5).toBool());
        user->setCreatedAt(query.value(6).toDateTime());
        user->setUpdatedAt(query.value(7).toDateTime());

        return user;
    }

    return NULL;
}

User* User::getLoggedIn() {
    QSqlQuery query("SELECT * FROM user WHERE active=1");

    if (query.next()){
        User * activeUser = new User();
        activeUser->setId(query.value(0).toInt());
        activeUser->setUsername(query.value(1).toString());
        activeUser->setEmail(query.value(2).toString());
        activeUser->setFirstName(query.value(3).toString());
        activeUser->setLastName(query.value(4).toString());
        activeUser->setActive(query.value(5).toBool());
        activeUser->setCreatedAt(query.value(6).toDateTime());
        activeUser->setUpdatedAt(query.value(7).toDateTime());

        return activeUser;
    }

    return NULL;
}
