//
// Created by Angelo on 04/01/2025.
//

#ifndef DHMS_PURCHASEOFFERID_H
#define DHMS_PURCHASEOFFERID_H

#include "EntityId.h"
#include <regex>





class PurchaseOfferId : public EntityId{
protected:
    bool isValueValid(const wstring &value) override{
        return (!value.empty());
    }
public:
    PurchaseOfferId(const wstring &value) : EntityId(value){
        this->setValue(value);
    }
};



#endif //DHMS_PURCHASEOFFERID_H
