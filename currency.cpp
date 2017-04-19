#include "currency.h"

Currency::Currency()
{

}

Currency::Currency(int number, QString name, QString code, int minorUnits, QDateTime createdAt, QDateTime updatedAt) {
    this->number = number;
    this->name = name;
    this->code = code;
    this->minorUnits = minorUnits;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;
}

int Currency::getNumber() {
    this->number;
}

QString Currency::getName() {
    this->name;
}

QString Currency::getCode() {
    this->code;
}

int Currency::getMinorUnits() {
    this->minorUnits;
}

void Currency::setNumber(int number) {
    this->number = number;
}
void Currency::setName(QString name) {
    this->name = name;
}

void Currency::setCode(QString code) {
    this->code = code;
}

void Currency::setMinorUnits(int minorUnits) {
    this->minorUnits = minorUnits;
}

Currency* Currency::getById(int id) {
    QSqlQuery query;
    QString sql = "SELECT * FROM currency WHERE id=:id";
    query.prepare(sql);
    query.bindValue(":id", QVariant(id));

    if (!query.exec()) {
        qDebug() << query.lastError();

        return NULL;
    }

    if (query.size() == 0) {
        return NULL;
    }

    Currency * currency = new Currency();

    if (query.next()) {
        currency->setNumber(query.value(0).toInt());
        currency->setName(query.value(1).toString());
        currency->setCode(query.value(2).toString());
        currency->setMinorUnits(query.value(3).toInt());
        currency->setCreatedAt(query.value(4).toDateTime());
        currency->setUpdatedAt(query.value(5).toDateTime());
    }

    return currency;
}
