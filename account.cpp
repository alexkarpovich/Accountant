#include "account.h"
#include <QDebug>
#include <QSqlQuery>

Account::Account()
{
    QSqlQuery query;
    query.exec("select * from sqlite_sequence");

    while(query.next()) {
        qDebug() << query.value(0).toString();
    }
}
