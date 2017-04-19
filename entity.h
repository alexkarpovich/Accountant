#ifndef ENTITY_H
#define ENTITY_H

#include <QDateTime>

class Entity
{
protected:
    QDateTime createdAt;
    QDateTime updatedAt;
public:
    QDateTime getCreatedAt();
    QDateTime getUpdatedAt();
    void setCreatedAt(QDateTime createdAt);
    void setUpdatedAt(QDateTime updatedAt);
};

#endif // ENTITY_H
