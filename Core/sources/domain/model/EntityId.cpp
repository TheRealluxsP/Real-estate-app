//
// Created by siulo on 02/01/2025.
//

#include <stdexcept>
#include "headers/domain/model/EntityId.h"

EntityId::EntityId(const std::wstring &value) {
    this ->value = value;
}

const wstring &EntityId::getValue() const {
    return this->value;
}

void EntityId::setValue(const std::wstring &value) {
    if(!this->isValueValid(value))
        throw invalid_argument("Invalid value for an Id.");
    this->value = value;
}

bool EntityId::operator==(const EntityId &other) const {
    if(&other == this) return true;
    return (this->value == other.value);
}

bool EntityId::operator<(const EntityId &other) const {
    return (this->value < other.value);
}