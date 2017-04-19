#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QVector>
#include <QString>
#include <QDateTime>
#include "entity.h"
#include "currency.h"
#include "models/account_model.h"

class Account: protected Entity
{
protected:
    int id = 0;
    Currency * currency;
    QString name;
    float amount;
public:
    Account();
    Account(int id, int currencyId, QString name, float amount, QDateTime createdAt, QDateTime updatedAt);
    int getId();
    Currency* getCurrency();
    QString getName();
    float getAmount();
    void setId(int id);
    void setCurrency(int currencyId);
    void setName(QString name);
    void setAmount(float amount);
    AccountModel* toModel();

    static QVector<Account*> getByUserId(int userId);
};

#endif // ACCOUNT_H
