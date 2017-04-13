#ifndef CURRENCY_H
#define CURRENCY_H

#include <QString>
#include "country.h"
#include "entity.h"

class Currency: protected Entity
{
protected:
    int number;
    Country country;
    QString name;
    QString code;
public:
    Currency();
};

#endif // CURRENCY_H
