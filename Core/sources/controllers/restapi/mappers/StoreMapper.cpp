//
// Created by siulo on 02/01/2025.
//

#include "headers/controllers/restapi/mappers/StoreMapper.h"
#include "thirdparty/SimpleJson.hpp"
#include <list>

#include "domain/model/StoreDTO.h"
#include "headers/domain/shared/StringUtils.h"

using namespace std;
using json::JSON;

JSON StoreMapper::toJson(shared_ptr<Store> obj) {
    JSON result = JSON::Load("{}");
    result["code"] = StringUtils::toString(obj->getCode());
    result["designation"] = obj->getDesignation();
    result["address"] = obj->getAddress();
    result["openingTime"] = obj->getOpeningTime();
    result["closingTime"] = obj->getClosingTime();
    result["revenue"] = obj->getRevenue();
    return result;
}

JSON StoreMapper::toJson(list<shared_ptr<Store>> objs) {
    JSON result = JSON::Load("[]");
    int i=0;
    for(shared_ptr<Store> store: objs){
        result[i] = StoreMapper::toJson(store);
        i++;
    }
    return result;
}

shared_ptr<StoreDTO> StoreMapper::toDTO(const shared_ptr<Store> &store) {
    wstring code = store->getCode();
    string designation = store->getDesignation();
    float revenue = store->getRevenue();

    return make_shared<StoreDTO>(code, designation, revenue);
}
