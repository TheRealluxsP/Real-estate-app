//
// Created by Utilizador on 17/12/2024.
//

#ifndef HOUSE_H
#define HOUSE_H
#include "HouseDTO.h"
#include "headers/domain/model/Residency.h"

class House : public Residency {
protected:
    bool existenceBasement;
    bool habittableAttic;
    bool sunExposure;
public:

    House(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph, int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring &availableEquipment, bool existenceBasement, bool habittableAttic, bool sunExposure);

    static shared_ptr<House> createHouse(const shared_ptr<HouseDTO> &houseDTO);

    bool getExistenceBasement() const;
    bool getHabittableAttic() const;
    bool getSunExposure() const;

    void setExistenceBasement(bool existenceBasement);
    void setHabittableAttic(bool habittableAttic);
    void setSunExposure(bool sunExposure);
};

#endif //HOUSE_H
