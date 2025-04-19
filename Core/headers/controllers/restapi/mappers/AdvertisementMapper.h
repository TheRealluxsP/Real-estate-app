//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#ifndef DHMS_ADVERTISEMENTMAPPER_H
#define DHMS_ADVERTISEMENTMAPPER_H

#include "thirdparty/SimpleJson.hpp"
#include "../../../domain/model/Advertisement.h"
#include <list>
#include <memory>
#include <string>

#include "domain/model/AdvertisementDTO.h"

using namespace std;
using json::JSON;

class AdvertisementMapper {
public:
    static JSON toJson(shared_ptr<Advertisement> advertisement);
    static JSON toJson(list<shared_ptr<Advertisement>> advertisements);
    static shared_ptr<Advertisement> toEntity(const JSON& json);
    static list<shared_ptr<AdvertisementDTO>> toDTO(list<shared_ptr<Advertisement>> advs);
};

#endif //DHMS_ADVERTISEMENTMAPPER_H
