//
// Created by Angelo on 12/01/2025.
//

#include "controllers/DisplayListedPropertiesController.h"
#include "domain/model/Residency.h"
#include "domain/dtos/DisplayedPropertyDTO.h"
#include "domain/dtos/DisplayedPropertyMapper.h"

// Constructor
DisplayListedPropertiesController::DisplayListedPropertiesController() {
    this->service = Company::GetInstance()->getAdvertisementService();
}

// Method to get listed properties
list<shared_ptr<DisplayedPropertyDTO>> DisplayListedPropertiesController::getListedProperties() {
    // Fetch all advertisements
    this->availableAdvList = this->service->getAvailableAdvertisements(); // Fetch only available (visible and unsold) advertisements

    this->listDisplayedPropertyDTO = DisplayedPropertyMapper::createDTOList();


    // Convert advertisements to DTOs using DisplayedPropertyMapper
    for (const auto &advertisement : this->availableAdvList) {
        shared_ptr<Property> property = advertisement->getProperty();

        // Extract property attributes
        string typeBusiness = advertisement->getTypeBusiness();
        string typeProperty = advertisement->getTypeProperty();
        float price = advertisement->getPrice();
        double area = property->getArea();
        wstring location = property->getLocation();

        // Additional attributes for house or apartment
        int bedrooms = 0, bathrooms = 0, parkingSpaces = 0;
        if (auto residency = dynamic_pointer_cast<Residency>(property)) {
            bedrooms = residency->getNumberBedrooms();
            bathrooms = residency->getNumberBathrooms();
            parkingSpaces = residency->getParkingSpaces();
        }

        // Create a DTO for the property
        shared_ptr<DisplayedPropertyDTO> dto = DisplayedPropertyMapper::toDTO(
                typeBusiness, typeProperty, price, area, location, bedrooms, bathrooms, parkingSpaces
        );

        // Add to the DTO list
        this->listDisplayedPropertyDTO.push_back(dto);
    }

    return this->listDisplayedPropertyDTO;
}
