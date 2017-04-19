#include "account_model.h"

AccountModel::AccountModel(QObject *parent) : QObject(parent)
{

}

void AccountModel::setId(int id) {
    this->_id = id;
}

void AccountModel::setName(QString name) {
    this->_name = name;
}

void AccountModel::setAmount(float amount) {
    this->_amount = amount;
}
