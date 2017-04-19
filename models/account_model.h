#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H

#include <QObject>
#include <QString>

class AccountModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id MEMBER _id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name MEMBER _name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(float amount MEMBER _amount WRITE setAmount NOTIFY amountChanged)
public:
    explicit AccountModel(QObject *parent = 0);
protected:
    int _id = 0;
    QString _name;
    float _amount;

signals:
    void idChanged();
    void nameChanged();
    void amountChanged();

public slots:
    void setId(int id);
    void setName(QString name);
    void setAmount(float amount);
};

#endif // ACCOUNT_MODEL_H
