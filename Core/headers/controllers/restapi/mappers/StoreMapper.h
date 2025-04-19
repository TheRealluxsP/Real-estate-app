//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STOREMAPPER_H
#define DHMS_STOREMAPPER_H

#include "thirdparty/SimpleJson.hpp"
#include "../../../domain/model/Store.h"
#include <string>
#include <list>

#include "domain/model/StoreDTO.h"

using namespace std;
using json::JSON;

class StoreMapper{
public:
    static JSON toJson(shared_ptr<Store> obj);

    static JSON toJson(list<shared_ptr<Store>> objs);

    static shared_ptr<StoreDTO> toDTO(const shared_ptr<Store>& store);
};

#endif //DHMS_STOREMAPPER_H
