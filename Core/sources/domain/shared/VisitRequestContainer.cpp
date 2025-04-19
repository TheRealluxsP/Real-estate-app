//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#include "VisitRequestContainer.h"
#include <iostream>

bool VisitRequestContainer::validateAndStoreRequest(int clientId, int propertyId, const std::vector<Visit>& selectedVisits) {
    // Check for conflicts with existing visits for the given property
    for (const Visit& existingVisit : visitRequests) {
        if (existingVisit.getPropertyId() == propertyId) {
            // Check for date conflicts
            for (const Visit& newVisit : selectedVisits) {
                if (newVisit.getDate().getDate() == existingVisit.getDate().getDate() &&
                    newVisit.getDate().getHour() == existingVisit.getDate().getHour()) {
                    // Conflict found
                    std::cout << "Conflict detected: The date and time "
                              << newVisit.getDate().getDate() << " at " << newVisit.getDate().getHour()
                              << " is already booked for this property.\n";
                    return false;
                }
            }
        }
    }

    // Add the new visit requests to the container
    visitRequests.insert(visitRequests.end(), selectedVisits.begin(), selectedVisits.end());

    // Indicate that the request was successfully stored
    std::cout << "Visit request successfully stored for Client ID " << clientId
              << " and Property ID " << propertyId << ".\n";
    return true;
}

