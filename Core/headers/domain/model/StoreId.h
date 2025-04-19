//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STOREID_H
#define DHMS_STOREID_H

#include "EntityId.h"
#include <regex>

class StoreId : public EntityId{
public:
    StoreId(const wstring &value) : EntityId(value){
        this->setValue(value);
    }

    bool isValueValid(const wstring &value) override{
        return regex_match(value, std::wregex(L"^[A-Za-z0-9]{5}$"));
    }
};

#endif //DHMS_STOREID_H
