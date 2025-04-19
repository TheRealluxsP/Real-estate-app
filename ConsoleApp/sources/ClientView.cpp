//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#include "ClientView.h"
#include "VisitBookingController.h"
#include <iostream>

std::vector<VisitDTO> ClientView::requestAvailableDates(int propertyId) {
    VisitBookingController controller;
    return controller.getAvailableDates(propertyId);
}

bool ClientView::selectDatesAndRequestBooking(int clientId, int propertyId, const std::vector<VisitDTO>& selectedDatesDTO) {
    VisitBookingController controller;

    if (controller.bookVisit(clientId, propertyId, selectedDatesDTO)) {
        std::cout << "Booking request successfully submitted.\n";
        return true;
    } else {
        std::cout << "Booking failed due to conflicts. Please select different dates.\n";
        return false;
    }
}
