//
// Created by Utilizador on 17/12/2024.
//

#include "headers/domain/model/Residency.h"

#include <stdexcept>

#include "StringUtils.h"
#include "controllers/restapi/mappers/ResidencyMapper.h"

Residency::Residency(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph, int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring &availableEquipment)
    : Property(area, location, distanceCenter, photograph)
{
    setNumberBedrooms(numberBedrooms);
    setNumberBathrooms(numberBathrooms);
    setParkingSpaces(parkingSpaces);
    setAvailableEquipment(availableEquipment);
}

Residency::Residency() : Property(), numberBedrooms(0), numberBathrooms(0), parkingSpaces(0), availableEquipment(L""){

}

shared_ptr<Residency> Residency::createRes(const shared_ptr<ResidencyDTO> &resDTO) {
    return ResidencyMapper::toModel(resDTO);
}


int Residency::getNumberBedrooms() const {
    return numberBedrooms;
}

void Residency::setNumberBedrooms(int numberBedrooms) {
    if (numberBedrooms < 0) {
        throw invalid_argument("Number of bedrooms cannot be a negative number");
    }
    this->numberBedrooms=numberBedrooms;
}

int Residency::getParkingSpaces() const {
    return parkingSpaces;
}

void Residency::setParkingSpaces(int parkingSpaces) {
    if (parkingSpaces < 0) {
        throw invalid_argument("Number of parking spaces cannot be a negative number");
    }
    this->parkingSpaces=parkingSpaces;
}

int Residency::getNumberBathrooms() const {
    return numberBathrooms;
}

void Residency::setNumberBathrooms(int numberBathrooms) {
    if (numberBathrooms <= 0) {
        throw invalid_argument("Number of bathrooms cannot be a negative number");
    }
    this->numberBathrooms=numberBathrooms;
}

wstring Residency::getAvailableEquipment() const {
    return availableEquipment;
}

void Residency::setAvailableEquipment(const wstring& availableEquipment) {
    if(StringUtils::trim(availableEquipment)== L"") {
        throw invalid_argument("Available Equipment cannot be empty");
    }
    this->availableEquipment = StringUtils::trim(availableEquipment);
}
