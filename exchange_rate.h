#ifndef EXCHANGE_RATE_H
#define EXCHANGE_RATE_H

#include <QString>
#include <QDateTime>
#include "entity.h"
#include "currency.h"

class ExchangeRate: protected Entity
{
protected:
    int id;
    Currency * base;
    Currency * compare;
    float rate;
    QDateTime date;
public:
    ExchangeRate();
};

#endif // EXCHANGE_RATE_H
