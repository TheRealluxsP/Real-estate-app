//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_VISITBOOKINGCONTROLLER_H
#define DHMS_VISITBOOKINGCONTROLLER_H

#include <vector>
#include "VisitDTO.h"
#include "VisitDTOMapper.h"
#include "VisitRequestContainer.h"
#include "headers/domain/model/Property.h"

class VisitBookingController {
public:
    // Method to retrieve available dates for a specific property
    std::vector<VisitDTO> getAvailableDates(int propertyId);

    // Method to book a visit with the provided details
    bool bookVisit(int clientId, int propertyId, const std::vector<VisitDTO>& selectedDatesDTO);
};

#endif // DHMS_VISITBOOKINGCONTROLLER_H
