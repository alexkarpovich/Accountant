#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>
#include "entity.h"
#include "expense_category.h"

class Expense: protected Entity
{
protected:
    int id;
    ExpenseCategory category;
    float value;
public:
    Expense();
};

#endif // EXPENSE_H
