//
// Created by Utilizador on 12/01/2025.
//

#include "domain/model/HouseDTO.h"

HouseDTO::HouseDTO(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph, int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring &availableEquipment, bool existenceBasement, bool habittableAttic, bool sunExposure)
    : area(area), location(location), distanceCenter(distanceCenter), photograph(photograph), numberBedrooms(numberBedrooms), numberBathrooms(numberBathrooms), parkingSpaces(parkingSpaces), availableEquipment(availableEquipment), existenceBasement(existenceBasement),habittableAttic(habittableAttic),sunExposure(sunExposure){}
