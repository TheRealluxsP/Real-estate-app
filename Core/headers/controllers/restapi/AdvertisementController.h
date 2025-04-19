//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#ifndef DHMS_ADVERTISEMENTCONTROLLER_H
#define DHMS_ADVERTISEMENTCONTROLLER_H

#include "RestController.h"
#include "HttpResult.h"
#include "domain/services/AdvertisementService.h"
#include "domain/model/Advertisement.h"
#include "headers/controllers/restapi/mappers/AdvertisementMapper.h"

class AdvertisementController : public RestController {

public:
    // Constructor for AdvertisementService with userToken passed to RestController
    AdvertisementController(const wstring &userToken) : RestController(userToken){};

    HttpResult getAll();  // GET /advertisements
    HttpResult getById(const wstring& code);  // GET /advertisements/{id}
    HttpResult postAdvertisement(const string& typeProperty, const string& typeBusiness, float price, const shared_ptr<Property> &property, const shared_ptr<Client> &client,  shared_ptr<Agent> &agent);  // POST /advertisements
    HttpResult putAdvertisement(const wstring& id, const string& typeProperty, const string& typeBusiness, float price, bool isSold, bool visibility);  // PUT /advertisements/{id}
    HttpResult deleteAdvertisement(const wstring& id);  // DELETE /advertisements/{id}
};

#endif //DHMS_ADVERTISEMENTCONTROLLER_H