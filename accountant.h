#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include <QString>
#include "entity.h"
#include "user.h"
#include "account.h"

class Accountant: protected Entity
{
protected:
    int id;
    User user;
    Account account;
    QString name;
public:
    Accountant();
};

#endif // ACCOUNTANT_H
