//
// Created by Tiago Cunha on 08/01/2025.
//

#ifndef DHMS_CLIENTID_H
#define DHMS_CLIENTID_H

#include "EntityId.h"
#include <regex>

class ClientId : public EntityId{
public:
    bool isValueValid(const wstring &value) override{
        return (!value.empty());
    }
    ClientId(const wstring &value) : EntityId(value){
        this->setValue(value);
    }
};

#endif //DHMS_CLIENTID_H
