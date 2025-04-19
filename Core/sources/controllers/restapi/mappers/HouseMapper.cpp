//
// Created by Utilizador on 12/01/2025.
//

#include  "headers/controllers/restapi/mappers/HouseMapper.h"

shared_ptr<House> HouseMapper::toModel(const shared_ptr<HouseDTO> &houseDTO) {
    double area = houseDTO->area;
    wstring location = houseDTO->location;
    wstring distanceCenter = houseDTO->distanceCenter;
    wstring photograph = houseDTO->photograph;
    int numberBedrooms = houseDTO->numberBedrooms;
    int numberBathrooms = houseDTO->numberBathrooms;
    int parkingSpaces = houseDTO->parkingSpaces;
    wstring availableEquipment = houseDTO->availableEquipment;
    bool existenceBasement = houseDTO->existenceBasement;
    bool habittableAttic = houseDTO->habittableAttic;
    bool sunExposure = houseDTO->sunExposure;

    return make_shared<House>(area, location, distanceCenter, photograph, numberBedrooms, numberBathrooms, parkingSpaces, availableEquipment, existenceBasement, habittableAttic, sunExposure);
}
