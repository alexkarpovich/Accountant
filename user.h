#ifndef USER_H
#define USER_H

#include <QString>
#include "entity.h"

class User: protected Entity
{
protected:
    int id = 0;
    QString username = NULL;
    QString email = NULL;
    QString firstName = NULL;
    QString lastName = NULL;
    bool active = NULL;
public:
    User();
    User(int, QString, QString, QString, QString, bool);
    int getId();
    QString getUsername();
    QString getEmail();
    QString getFirstName();
    QString getLastName();
    bool getActive();
    void setId(int);
    void setUsername(QString);
    void setEmail(QString);
    void setFirstName(QString);
    void setLastName(QString);
    void setActive(bool);
    void save();
    static User* getUserById(int);
    static User* getLoggedIn();
};

#endif // USER_H
