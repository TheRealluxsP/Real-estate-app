//
// Created by Utilizador on 12/01/2025.
//

#include "headers/controllers/restapi/mappers/ResidencyMapper.h"

shared_ptr<Residency> ResidencyMapper::toModel(const shared_ptr<ResidencyDTO> &resDTO) {
    double area = resDTO->area;
    wstring location = resDTO->location;
    wstring distanceCenter = resDTO->distanceCenter;
    wstring photograph = resDTO->photograph;
    int numberBedrooms = resDTO->numberBedrooms;
    int numberBathrooms = resDTO->numberBathrooms;
    int parkingSpaces = resDTO->parkingSpaces;
    wstring availableEquipment = resDTO->availableEquipment;

    return make_shared<Residency>(area, location, distanceCenter, photograph, numberBedrooms, numberBathrooms, parkingSpaces, availableEquipment);
}
