//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_CLIENTVIEW_H
#define DHMS_CLIENTVIEW_H

#include <vector>
#include "VisitDTO.h"

class ClientView {
public:
    std::vector<VisitDTO> requestAvailableDates(int propertyId);
    bool selectDatesAndRequestBooking(int clientId, int propertyId, const std::vector<VisitDTO>& selectedDatesDTO);
};

#endif // DHMS_CLIENTVIEW_H
