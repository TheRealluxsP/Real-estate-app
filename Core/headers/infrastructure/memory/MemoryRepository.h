//
// Created by siulo on 30/12/2024.
//

#ifndef DHMS_MEMORYREPOSITORY_H
#define DHMS_MEMORYREPOSITORY_H

#include <type_traits>
#include <list>
#include <optional>
#include "headers/domain/repositories/Repository.h"

using namespace std;

template<typename TEntity, typename TEntityId, typename = enable_if_t<is_base_of_v<Entity<TEntityId>, TEntity>>, typename = enable_if_t<is_base_of_v<EntityId, TEntityId>>>
class MemoryRepository : virtual public Repository<TEntity, TEntityId> {
protected:
    list<shared_ptr<TEntity>> container;

    optional<shared_ptr<TEntity>> findObject(shared_ptr<TEntity> obj) {
        if (!obj)
            return nullopt;
        for (typename std::list<shared_ptr<TEntity>>::iterator it = container.begin(); it != container.end(); ++it) {
            shared_ptr<TEntity> obj2 = *it;
            if (obj2 == obj)
                return make_optional<shared_ptr<TEntity>>(obj2);
        }
        return nullopt;
    };

public:
    MemoryRepository() {
    };

    virtual Result save(shared_ptr<TEntity> obj) override {
        if (!obj)
            return Result::NOK(L"Entity object not provided!");
        optional<shared_ptr<TEntity>> exists = this->findObject(obj);
        if (!exists.has_value()) {
            // Aims to add a new object
            exists = this->getById(obj->getId());
            if (!exists.has_value()) {
                // No duplicate object exists, so it can be added
                this->container.push_back(obj);
                return Result::OK();
            } else
                return Result::NOK(L"Trying to add a duplicate entity.");
        } else {
            // Aims to Update the object
            // Since object is in memory nothing is required to be done
            return Result::OK();
        }
    };

    virtual Result remove(shared_ptr<TEntity> obj) override {
        if (!obj)
            return Result::NOK(L"Entity object not provided!");
        optional<shared_ptr<TEntity>> exists = this->findObject(obj);
        if (exists.has_value()) {
            this->container.remove(obj);
            return Result::OK();
        }
        return Result::NOK(L"Entity not found!");
    };

    virtual list<shared_ptr<TEntity>> getAll() override {
        list<shared_ptr<TEntity>> newList;
        newList.insert(newList.end(), container.begin(), container.end());
        return newList;
    };

    virtual optional<shared_ptr<TEntity>> getById(shared_ptr<TEntityId> id) override {
        for (typename list<shared_ptr<TEntity>>::iterator it = container.begin(); it != container.end(); ++it) {
            shared_ptr<TEntity> obj = *it;
            if (obj->hasId(*id))
                return make_optional<shared_ptr<TEntity>>(obj);
        }
        return nullopt;
    };

    virtual bool isEmpty() override {
        return this->container.empty();
    };

    virtual long count() override {
        return this->container.size();
    };
};

#endif //DHMS_MEMORYREPOSITORY_H
