//
// Created by Angelo on 12/01/2025.
//

#ifndef DHMS_DISPLAYEDPROPERTYMAPPER_H
#define DHMS_DISPLAYEDPROPERTYMAPPER_H

#ifndef DISPLAYEDPROPERTYMAPPER_H
#define DISPLAYEDPROPERTYMAPPER_H


#include <memory>
#include <list>
#include "domain/model/PropertyDTO.h"
#include "domain/model/Advertisement.h"
#include "DisplayedPropertyDTO.h"
#include "domain/model/Residency.h"

class DisplayedPropertyMapper {
public:

    // Method to create an empty list of DisplayedPropertyDTO
    static list<shared_ptr<DisplayedPropertyDTO>> createDTOList() {
        return {};  // Return an empty list
    }

    // Method to convert a single Advertisement to a DisplayedPropertyDTO
    static shared_ptr<DisplayedPropertyDTO> toDTO(const string &typeBusiness, const string &typeProperty, float price,
                                                  double area, const wstring &location, int bedrooms = 0,
                                                  int bathrooms = 0, int parkingSpaces = 0) {
        return make_shared<DisplayedPropertyDTO>(typeBusiness, typeProperty, price, area, location, bedrooms, bathrooms, parkingSpaces);
    }

};
#endif // DISPLAYEDPROPERTYMAPPER_H

#endif //DHMS_DISPLAYEDPROPERTYMAPPER_H
