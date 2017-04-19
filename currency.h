#ifndef CURRENCY_H
#define CURRENCY_H

#include <QString>
#include <QDateTime>
#include "country.h"
#include "entity.h"

class Currency: protected Entity
{
protected:
    int number;
    QString name;
    QString code;
    int minorUnits;
public:
    Currency();
    Currency(int number, QString name, QString code, int minorUnits, QDateTime createdAt, QDateTime updatedAt);
    int getNumber();
    QString getName();
    QString getCode();
    int getMinorUnits();
    void setNumber(int number);
    void setName(QString name);
    void setCode(QString code);
    void setMinorUnits(int minorUnits);

    static Currency* getById(int id);
};

#endif // CURRENCY_H
