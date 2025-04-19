//
// Created by Utilizador on 16/12/2024.
//

#ifndef RESIDENCY_H
#define RESIDENCY_H
#include "ResidencyDTO.h"
#include "headers/domain/model/Property.h"

class Residency : public Property {
protected:
    int numberBedrooms;
    int numberBathrooms;
    int parkingSpaces;
    wstring availableEquipment;
public:
    Residency(double area, const wstring& location, const wstring& distanceCenter, const wstring& photograph, int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring& availableEquipment);

    Residency();

    static shared_ptr<Residency> createRes(const shared_ptr<ResidencyDTO> &resDTO);

    int getNumberBedrooms() const;
    void setNumberBedrooms(int numberBedrooms);

    int getNumberBathrooms() const;
    void setNumberBathrooms(int numberBathrooms);

    int getParkingSpaces() const;
    void setParkingSpaces(int parkingSpaces);

    wstring getAvailableEquipment() const;
    void setAvailableEquipment(const wstring& availableEquipment);


};

#endif //RESIDENCY_H
