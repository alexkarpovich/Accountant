#include "expense_category.h"

ExpenseCategory::ExpenseCategory()
{

}

ExpenseCategory::ExpenseCategory(int id, QString name, QDateTime createdAt, QDateTime updatedAt) {
    this->id = id;
    this->name = name;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;
}

int ExpenseCategory::getId() {
    return this->id;
}

QString ExpenseCategory::getName() {
    return this->name;
}

void ExpenseCategory::setId(int id) {
    this->id = id;
}

void ExpenseCategory::setName(QString name) {
    this->name = name;
}
