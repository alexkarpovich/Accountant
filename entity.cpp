#include "entity.h"


QDateTime Entity::getCreatedAt() {
    return this->createdAt;
}

QDateTime Entity::getUpdatedAt() {
    return this->updatedAt;
}

void Entity::setCreatedAt(QDateTime createdAt) {
    this->createdAt = createdAt;
}

void Entity::setUpdatedAt(QDateTime updatedAt) {
    this->updatedAt = updatedAt;
}
