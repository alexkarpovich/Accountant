#ifndef USER_H
#define USER_H

#include <QString>
#include "entity.h"

class User: protected Entity
{
protected:
    int id;
    QString username;
    QString email;
    QString firstName;
    QString lastName;
public:
    User();
};

#endif // USER_H
