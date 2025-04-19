//
// Created by Utilizador on 17/12/2024.
//

#include "headers/domain/model/House.h"

#include "controllers/restapi/mappers/HouseMapper.h"

House::House(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph, int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring &availableEquipment, bool existenceBasement, bool habittableAttic, bool sunExposure)
    :Residency(area,location,distanceCenter, photograph, numberBedrooms,numberBathrooms, parkingSpaces, availableEquipment) {
    setHabittableAttic(habittableAttic);
    setSunExposure(sunExposure);
    setExistenceBasement(existenceBasement);
}

shared_ptr<House> House::createHouse(const shared_ptr<HouseDTO> &houseDTO) {
    return HouseMapper::toModel(houseDTO);
}


bool House::getExistenceBasement() const{
    return existenceBasement;
}

bool House::getHabittableAttic() const{
    return habittableAttic;
}

bool House::getSunExposure() const{
    return sunExposure;
}

void House::setExistenceBasement(bool existenceBasement) {
    this->existenceBasement = existenceBasement;
}

void House::setHabittableAttic(bool habittableAttic) {
    this->habittableAttic = habittableAttic;
}

void House::setSunExposure(bool sunExposure) {
    this->sunExposure = sunExposure;
}
