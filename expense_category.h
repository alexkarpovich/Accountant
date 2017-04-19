#ifndef EXPENSE_CATEGORY_H
#define EXPENSE_CATEGORY_H

#include <QString>
#include "entity.h"

class ExpenseCategory: protected Entity
{
protected:
    int id = 0;
    QString name;
public:
    ExpenseCategory();
    ExpenseCategory(int id, QString name, QDateTime createdAt, QDateTime updatedAt);
    int getId();
    QString getName();
    void setId(int id);
    void setName(QString name);
};

#endif // EXPENSE_CATEGORY_H
