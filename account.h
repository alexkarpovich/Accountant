#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QVector>
#include <QString>
#include <QDateTime>
#include "entity.h"
#include "currency.h"

class Account: protected Entity
{
protected:
    int id;
    Currency * currency;
    QString name;
    float amount;
public:
    Account();
    Account(int id, int currencyId, QString name, float amount, QDateTime createdAt, QDateTime updatedAt);
    static QVector<Account*> getByUserId(int userId);
};

#endif // ACCOUNT_H
