#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include <QString>
#include <QVector>
#include "entity.h"
#include "user.h"
#include "account.h"

class Accountant: protected Entity
{
protected:
    int id = 0;
    QString name;
    bool active;
public:
    Accountant();
    Accountant(int id, QString name, bool active, QDateTime createdAt, QDateTime updatedAt);
    int getId();
    QString getName();
    bool isActive();
    void setId(int id);
    void setName(QString name);
    void setActive(bool isActive);
    void linkUser(User * user);
    void linkAccount(Account * accounts);
    void save();

    static Accountant * getById(int id);
    static QVector<Accountant*> getByUserId(int userId);
    static QVector<Accountant*> getByAccountId(int accountId);
};

#endif // ACCOUNTANT_H
