//
// Created by Utilizador on 04/01/2025.
//



#ifndef ADVERTISEMENTID_H
#define ADVERTISEMENTID_H

#include "EntityId.h"

class AdvertisementId : public EntityId {
protected:
    bool isValueValid(const wstring &value) override{
        return (!value.empty());
    }
public:
    AdvertisementId(const wstring &value) : EntityId(value){
        this->setValue(value);
    }
};

#endif //ADVERTISEMENTID_H
