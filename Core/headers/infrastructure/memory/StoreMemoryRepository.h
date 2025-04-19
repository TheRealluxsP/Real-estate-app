//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STOREMEMORYREPOSITORY_H
#define DHMS_STOREMEMORYREPOSITORY_H


#include "domain/repositories/StoreRepository.h"
#include "MemoryRepository.h"
#include "../model/Store.h"
#include "../model/StoreId.h"

class StoreMemoryRepository : public StoreRepository, public MemoryRepository<Store, StoreId>{
private:
public:
    StoreMemoryRepository();

    virtual optional<shared_ptr<Store>> getById(const wstring &code);
    virtual list<shared_ptr<Store>> getAll() override;
};

#endif //DHMS_STOREMEMORYREPOSITORY_H
