#ifndef COUNTRY_H
#define COUNTRY_H

#include <QString>
#include "entity.h"

class Country: protected Entity
{
protected:
    int isoN;
    QString name;
    char iso2[2];
    char iso3[3];
public:
    Country();
};

#endif // COUNTRY_H
