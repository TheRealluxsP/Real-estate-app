//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#ifndef DHMS_ADVERTISEMENTROUTER_H
#define DHMS_ADVERTISEMENTROUTER_H

#include "RouterConfig.h"
#include "domain/services/AdvertisementService.h"
#include "../thirdparty/httplib.h"

using namespace std;

class AdvertisementRouter : public RouterConfig {
public:
    // Constructor
    AdvertisementRouter();

    // Configure method (already implemented)
    void configure(httplib::Server &svr);

};

#endif //DHMS_ADVERTISEMENTROUTER_H