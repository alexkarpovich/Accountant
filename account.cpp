#include "account.h"
#include "currency.h"

Account::Account()
{

}

Account::Account(int id, int currencyId, QString name, float amount, QDateTime createdAt, QDateTime updatedAt) {
    this->id = id;
    this->name = name;
    this->amount = amount;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    Currency * currency = Currency::getById(currencyId);
    this->currency = currency;
}

int Account::getId() {
    return this->id;
}

Currency* Account::getCurrency() {
    return this->currency;
}

QString Account::getName() {
    return this->name;
}

float Account::getAmount() {
    return this->amount;
}

void Account::setId(int id) {
    this->id = id;
}

void Account::setCurrency(int currencyId) {
    this->currency = Currency::getById(currencyId);
}

void Account::setName(QString name) {
    this->name = name;
}

void Account::setAmount(float amount) {
    this->amount = amount;
}

QVector<Account*> Account::getByUserId(int userId) {
    QSqlQuery query;
    QVector<Account*> accounts;

    QString sql = "SELECT acc.* FROM accountant_account aa "
            "LEFT JOIN accountant_user au ON au.accountant_id=aa.accountant_id and au.user_id=:user_id"
            "LEFT JOIN account acc ON acc.id=aa.account_id";

    query.prepare(sql);
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << QFileInfo(QCoreApplication::applicationFilePath()).fileName() + query.lastError().text();
        qDebug() << query.lastQuery();

        return accounts;
    }

    int count = query.size();

    if (!count) {
        return accounts;
    }

    while(query.next()) {
        Account * account = new Account(
            query.value(0).toInt(),
            query.value(1).toInt(),
            query.value(2).toString(),
            query.value(3).toReal(),
            query.value(4).toDateTime(),
            query.value(5).toDateTime()
        );

        accounts.append(account);
    }

    return accounts;
}

AccountModel* Account::toModel() {
    AccountModel * accountModel = new AccountModel();
    accountModel->setId(this->id);
    accountModel->setName(this->name);
    accountModel->setAmount(this->amount);

    return accountModel;
}
