//
// Created by siulo on 09/01/2025.
//

#ifndef DHMS_PROPERTYID_H
#define DHMS_PROPERTYID_H

#include "EntityId.h"

class PropertyId : public EntityId{
public:
    bool isValueValid(const wstring &value) override{
        return (!value.empty());
    }
    PropertyId(const wstring &value) : EntityId(value){
        this->setValue(value);
    }
};

#endif //DHMS_PROPERTYID_H
