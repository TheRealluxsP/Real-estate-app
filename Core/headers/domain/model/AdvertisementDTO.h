//
// Created by Utilizador on 12/01/2025.
//

#ifndef ADVERTISEMENTDTO_H
#define ADVERTISEMENTDTO_H

#include <memory>
#include <string>

#include "PropertyDTO.h"
#include "StoreDTO.h"

using namespace std;

class AdvertisementDTO {
public:
    string typeProperty;
    string typeBusiness;
    float price;
    shared_ptr<PropertyDTO> propertyDto;
    shared_ptr<StoreDTO> storeDto;
    float commission;
    bool isPercentageValue;

    AdvertisementDTO(const string& typeProperty, const string& typeBusiness,
        float price, shared_ptr<PropertyDTO> propertyDto,
        shared_ptr<StoreDTO> storeDto, float commission, bool isPercentageValue)
    : typeProperty(typeProperty), typeBusiness(typeBusiness),
    price(price), propertyDto(propertyDto),
    storeDto(storeDto), commission(commission), isPercentageValue(isPercentageValue) {};
};

#endif //ADVERTISEMENTDTO_H
