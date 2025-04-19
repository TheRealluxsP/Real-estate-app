//
// Created by Angelo on 12/01/2025.
//

#ifndef DHMS_DISPLAYLISTEDPROPERTIESCONTROLLER_H
#define DHMS_DISPLAYLISTEDPROPERTIESCONTROLLER_H


#include "domain/services/AdvertisementService.h"
#include "domain/model/Advertisement.h"
#include "domain/model/AdvertisementDTO.h"
#include "controllers/Company.h"
#include "domain/dtos/DisplayedPropertyDTO.h"

class DisplayListedPropertiesController {

private:
    shared_ptr<AdvertisementService> service;
    list<shared_ptr<Advertisement>> availableAdvList;
    list<shared_ptr<DisplayedPropertyDTO>> listDisplayedPropertyDTO;

public:
    // Constructor
    DisplayListedPropertiesController();


    // Methods
    list<shared_ptr<DisplayedPropertyDTO>> getListedProperties();
};

#endif //DHMS_DISPLAYLISTEDPROPERTIESCONTROLLER_H
