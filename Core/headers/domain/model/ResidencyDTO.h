//
// Created by Utilizador on 12/01/2025.
//

#ifndef RESIDENCYDTO_H
#define RESIDENCYDTO_H

#include <string>
using namespace std;

class ResidencyDTO {
public:
    double area;
    wstring location;
    wstring distanceCenter;
    wstring photograph;
    int numberBedrooms;
    int numberBathrooms;
    int parkingSpaces;
    wstring availableEquipment;

    ResidencyDTO(double area, const wstring& location, const wstring& distanceCenter, const wstring& photograph, int numberBedrooms, int numberBathrooms, int parkingSpaces, const wstring& availableEquipment);

};

#endif //RESIDENCYDTO_H
