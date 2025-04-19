//
// Created by siulo on 30/12/2024.
//

#ifndef DHMS_ENTITY_H
#define DHMS_ENTITY_H

#include <memory>
#include <stdexcept>
#include "EntityId.h"

template<typename TEntityId, typename = enable_if_t<is_base_of_v<EntityId, TEntityId>>>

class Entity {
private:
protected:
    shared_ptr<TEntityId> id;

    Entity(shared_ptr<TEntityId> id) {
        if (!this->isIdValid(id))
            throw invalid_argument("Invalid EntityId.");
        this->id = id;
    }

    virtual void setId(shared_ptr<TEntityId> id) {
        if (!this->isIdValid(id))
            throw invalid_argument("Invalid EntityId.");
        this->id = id;
    }

    virtual bool isIdValid(shared_ptr<TEntityId> id) {
        return true;
    };

public:
    shared_ptr<TEntityId> getId() {
        return this->id;
    }

    virtual bool hasId(TEntityId id) const {
        return (*this->id) == id;
    };

    virtual bool operator==(const Entity &param) const {
        if (&param == this) return true;
        //return (this->id->getValue() == param.id->getValue());
        return ((*this->id) == (*param.id));
    };

    virtual bool operator<(const Entity &param) const {
        //return  (this->id->getValue() < param.id->getValue());
        return ((*this->id) < (*param.id));
    };
};


#endif //DHMS_ENTITY_H
