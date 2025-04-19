//
// Created by Utilizador on 12/01/2025.
//

#include "headers/controllers/restapi/mappers/PropertyMapper.h"

shared_ptr<Property> PropertyMapper::toModel(const shared_ptr<PropertyDTO> &propertyDTO) {
    double area = propertyDTO->area;
    wstring location = propertyDTO->location;
    wstring distanceCenter = propertyDTO->distanceCenter;
    wstring photograph = propertyDTO->photograph;

    return make_shared<Property>(area, location, distanceCenter, photograph);
}

shared_ptr<PropertyDTO> PropertyMapper::toDTO(const shared_ptr<Property> &property) {
    wstring code = property->getCode();
    double area = property->getArea();
    wstring location = property->getLocation();
    wstring distanceCenter = property->getDistanceCenter();
    wstring photograph = property->getPhotograph();

    return make_shared<PropertyDTO>(code, area, location, distanceCenter, photograph);
}

