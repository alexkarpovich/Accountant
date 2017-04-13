#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "entity.h"
#include "currency.h"

class Account: protected Entity
{
protected:
    int id;
    Currency currency;
    QString name;
    float amount;
public:
    Account();
};

#endif // ACCOUNT_H
