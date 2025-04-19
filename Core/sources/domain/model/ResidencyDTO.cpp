//
// Created by Utilizador on 12/01/2025.
//


#include  "domain/model/ResidencyDTO.h"

ResidencyDTO::ResidencyDTO(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph,
    int numberBedrooms, int numberBathrooms,
    int parkingSpaces, const wstring &availableEquipment) : area(area), location(location), distanceCenter(distanceCenter), photograph(photograph), numberBedrooms(numberBedrooms), numberBathrooms(numberBathrooms), parkingSpaces(parkingSpaces), availableEquipment(availableEquipment) {

}
