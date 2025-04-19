//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STOREREPOSITORY_H
#define DHMS_STOREREPOSITORY_H

#include "../model/Store.h"
#include "../model/StoreId.h"
#include "Repository.h"

class StoreRepository : virtual public Repository<Store, StoreId>{
public:
    virtual optional<shared_ptr<Store>> getById(const wstring &code) = 0;
    virtual list <shared_ptr<Store>> getAll() = 0;
};

#endif //DHMS_STOREREPOSITORY_H
