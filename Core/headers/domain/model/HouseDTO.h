//
// Created by Utilizador on 12/01/2025.
//

#ifndef HOUSEDTO_H
#define HOUSEDTO_H

#include <string>
using namespace std;

class HouseDTO {
public:
    double area;
    wstring location;
    wstring distanceCenter;
    wstring photograph;
    int numberBedrooms;
    int numberBathrooms;
    int parkingSpaces;
    wstring availableEquipment;
    bool existenceBasement;
    bool habittableAttic;
    bool sunExposure;

    HouseDTO(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph,
             int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring &availableEquipment,
             bool existenceBasement, bool habittableAttic, bool sunExposure);

};

#endif //HOUSEDTO_H
