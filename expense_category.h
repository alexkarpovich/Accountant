#ifndef EXPENSE_CATEGORY_H
#define EXPENSE_CATEGORY_H

#include <QString>
#include "entity.h"

class ExpenseCategory: protected Entity
{
protected:
    int id;
    QString name;
public:
    ExpenseCategory();
};

#endif // EXPENSE_CATEGORY_H
