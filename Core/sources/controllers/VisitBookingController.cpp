//
// Created by Rui Pedro Monteiro on 02/12/2024.
//
#include "VisitBookingController.h"
#include "VisitMapper.h"
#include <iostream>

// Method to retrieve available dates for a specific property.
std::vector<VisitDTO> VisitBookingController::getAvailableDates(int propertyId) {
    // Simulate the retrieval of available visits from a data source.
    std::vector<Visit> availableVisits = retrieveAvailableVisitsFromDomain(propertyId);
    std::vector<VisitDTO> dtos;

    // Convert domain visits to DTOs using the VisitMapper.
    for (const Visit& visit : availableVisits) {
        dtos.push_back(visit.toDTO());  // Convert each Visit object to a VisitDTO and add to the vector.
    }

    return dtos;  // Return the vector of VisitDTOs.
}

// Method to book a visit with the provided details, given the client ID, property ID, and selected dates.
bool VisitBookingController::bookVisit(int clientId, int propertyId, const std::vector<VisitDTO>& selectedDatesDTO) {
    std::vector<Visit> selectedVisits;

    // Convert the input DTOs to domain objects (Visit objects).
    for (const VisitDTO& dto : selectedDatesDTO) {
        selectedVisits.push_back(Visit::fromDTO(dto));  // Convert each VisitDTO to a Visit object and add to the vector.
    }

    // Create an instance of VisitRequestContainer to validate and store the visit requests.
    VisitRequestContainer container;
    return container.validateAndStoreRequest(clientId, propertyId, selectedVisits);  // Return the result of the validation and storage.
}
