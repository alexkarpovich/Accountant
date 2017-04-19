#include "accountant.h"

Accountant::Accountant()
{

}

Accountant::Accountant(int id, QString name, bool active, QDateTime createdAt, QDateTime updatedAt) {
    this->id = id;
    this->name = name;
    this->active = active;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;
}

int Accountant::getId() {
    return this->id;
}

QString Accountant::getName() {
    return this->name;
}

bool Accountant::isActive() {
    return this->active;
}

void Accountant::setId(int id) {
    this->id = id;
}

void Accountant::setName(QString name) {
    this->name = name;
}

void Accountant::setActive(bool isActive) {
    this->active = isActive;
}

void Accountant::save() {
    QString sql;
    this->createdAt = this->updatedAt = QDateTime::currentDateTime();

    if (!this->id) {
        sql = "INSERT INTO accountant (name, created_at, updated_at) "
                  "VALUES(:name, :created_at, :updated_at)";
    } else {
        sql = "UPDATE accountant SET (name, updated_at) VALUES(:name, :updated_at) WHERE id=:id";
    }

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QVariant(this->id));
    query.bindValue(":name", this->name);
    query.bindValue(":created_at", this->createdAt.toTime_t());
    query.bindValue(":updated_at", this->updatedAt.toTime_t());

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();

        return;
    }

    this->id = query.lastInsertId().toInt();
}

Accountant * Accountant::getById(int id) {
    QSqlQuery query;
    QString sql = "SELECT * FROM accountant WHERE id=:id";
    query.prepare(sql);
    query.bindValue(":id", QVariant(id));

    if (!query.exec()) {
        qDebug() << query.lastError();

        return NULL;
    }

    Accountant * accountant = new Accountant();

    if (query.next()) {
        accountant->setId(query.value(0).toInt());
        accountant->setName(query.value(1).toString());
        accountant->setActive(query.value(2).toBool());
    }

    return accountant;
}

QVector<Accountant*> Accountant::getByUserId(int userId) {
    QSqlQuery query;
    QVector<Accountant*> accountants;

    QString sql = "SELECT accountant_id, acc.name, au.active, acc.created_at, acc.updated_at FROM accountant_user au "
                  "LEFT JOIN accountant acc ON acc.id = au.accountant_id "
                  "WHERE user_id=:user_id";

    query.prepare(sql);
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << query.lastError();

        return accountants;
    }

    int count = query.size();

    if (!count) {
        return accountants;
    }

    while(query.next()) {
        Accountant * accountant = new Accountant(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toBool(),
            query.value(3).toDateTime(),
            query.value(4).toDateTime()
        );

        accountants.append(accountant);
    }

    return accountants;
}

QVector<Accountant*> Accountant::getByAccountId(int accountId) {
    QSqlQuery query;
    QVector<Accountant*> accountants;

    QString sql = "SELECT accountant_id, acc.name, acc.created_at, acc.updated_at FROM accountant_account aa "
                  "LEFT JOIN accountant acc ON acc.id = aa.accountant_id "
                  "WHERE account_id=:account_id";

    query.prepare(sql);
    query.bindValue(":account_id", accountId);

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return accountants;
    }

    int count = query.size();

    if (!count) {
        return accountants;
    }

    while(query.next()) {
        Accountant * accountant = new Accountant(
            query.value(0).toInt(),
            query.value(1).toString(),
            false,
            query.value(3).toDateTime(),
            query.value(4).toDateTime()
        );

        accountants.append(accountant);
    }

    return accountants;
}

void Accountant::linkUser(User *user) {
    QVector<Accountant*> accountants = Accountant::getByUserId(user->getId());

    if (!accountants.size()) {
        QSqlQuery query;
        QString sql = "INSERT INTO accountant_user (accountant_id, user_id, active) VALUES(:accountant_id, :user_id, :isActive)";
        query.prepare(sql);
        query.bindValue(":accountant_id", this->id);
        query.bindValue(":user_id", user->getId());
        query.bindValue(":isActive", true);

        if (!query.exec()) {
            qDebug() << query.lastError();
            qDebug() << query.lastQuery();

            return;
        }
    }
}

void Accountant::linkAccount(Account * account) {
    QVector<Accountant*> accountants = Accountant::getByAccountId(account->getId());
    bool isAlreadyAdded = false;

    for(int i = 0; i < accountants.size(); i++) {
        if (accountants.at(i)->getId() == this->getId()) {
            isAlreadyAdded = true;
            break;
        }
    }

    if (isAlreadyAdded) {
        return;
    }

    QSqlQuery query;
    QString sql = "INSERT INTO accountant_account (accountant_id, account_id) VALUES(:accountant_id, :account_id)";
    query.prepare(sql);
    query.bindValue(":accountant_id", QVariant(this->getId()));
    query.bindValue(":account_id", QVariant(account->getId()));

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return;
    }

}
