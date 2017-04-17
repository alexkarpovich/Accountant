#ifndef ENTITY_H
#define ENTITY_H

#include <QDateTime>

class Entity
{
protected:
    QDateTime createdAt;
    QDateTime updatedAt;
public:
    QDateTime getCreatedAt() { return this->createdAt;};
    QDateTime getUpdatedAt() { return this->updatedAt;};
    void setCreatedAt(QDateTime createdAt) {this->createdAt = createdAt;};
    void setUpdatedAt(QDateTime updatedAt) {this->updatedAt = updatedAt;};
};

#endif // ENTITY_H
