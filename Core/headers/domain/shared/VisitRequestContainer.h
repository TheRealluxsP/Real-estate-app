//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_VISITREQUESTCONTAINER_H
#define DHMS_VISITREQUESTCONTAINER_H

#include <vector>
#include "Visit.h"

class VisitRequestContainer {
private:
    std::vector<Visit> visitRequests; // List of all visit requests

public:
    // Method to validate the visit request and store it if valid
    bool validateAndStoreRequest(int clientId, int propertyId, const std::vector<Visit>& selectedVisits);
};

#endif // DHMS_VISITREQUESTCONTAINER_H
