//
// Created by Angelo on 12/01/2025.
//

#include "domain/dtos/DisplayedPropertyDTO.h"

// Constructor
DisplayedPropertyDTO::DisplayedPropertyDTO(const std::string& typeBusiness,
                                           const std::string& typeProperty,
                                           float price,
                                           double area,
                                           const std::wstring& location,
                                           int bedrooms,
                                           int bathrooms,
                                           int parkingSpaces)
        : typeBusiness(typeBusiness), typeProperty(typeProperty), price(price),
          area(area), location(location), bedrooms(bedrooms),
          bathrooms(bathrooms), parkingSpaces(parkingSpaces) {}

// Getters
const std::string& DisplayedPropertyDTO::getTypeBusiness() const {
    return typeBusiness;
}

const std::string& DisplayedPropertyDTO::getTypeProperty() const {
    return typeProperty;
}

float DisplayedPropertyDTO::getPrice() const {
    return price;
}

double DisplayedPropertyDTO::getArea() const {
    return area;
}

const std::wstring& DisplayedPropertyDTO::getLocation() const {
    return location;
}

int DisplayedPropertyDTO::getBedrooms() const {
    return bedrooms;
}

int DisplayedPropertyDTO::getBathrooms() const {
    return bathrooms;
}

int DisplayedPropertyDTO::getParkingSpaces() const {
    return parkingSpaces;
}

// Setters
void DisplayedPropertyDTO::setTypeBusiness(const std::string& typeBusiness) {
    this->typeBusiness = typeBusiness;
}

void DisplayedPropertyDTO::setTypeProperty(const std::string& typeProperty) {
    this->typeProperty = typeProperty;
}

void DisplayedPropertyDTO::setPrice(float price) {
    this->price = price;
}

void DisplayedPropertyDTO::setArea(double area) {
    this->area = area;
}

void DisplayedPropertyDTO::setLocation(const std::wstring& location) {
    this->location = location;
}

void DisplayedPropertyDTO::setBedrooms(int bedrooms) {
    this->bedrooms = bedrooms;
}

void DisplayedPropertyDTO::setBathrooms(int bathrooms) {
    this->bathrooms = bathrooms;
}

void DisplayedPropertyDTO::setParkingSpaces(int parkingSpaces) {
    this->parkingSpaces = parkingSpaces;
}
