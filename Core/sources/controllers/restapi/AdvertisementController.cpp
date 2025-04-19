//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#include "headers/controllers/restapi/AdvertisementController.h"
#include "headers/domain/services/AdvertisementService.h"
#include "headers/domain/model/Advertisement.h"
#include <stdexcept>


HttpResult AdvertisementController::getAll() {
    HttpResult result;
    try{
        shared_ptr<AdvertisementService> service = this->company->getAdvertisementService();
        list<shared_ptr<Advertisement>> advs = service->getAll();
        result = HttpResult(HttpStatus::HTTP_OK, AdvertisementMapper::toJson(advs));
    }
    catch (invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult AdvertisementController::getById(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<AdvertisementService> service = this->company->getAdvertisementService();
        optional<shared_ptr<Advertisement>> found = service->getByCode(code);
        if (found.has_value())
            result = HttpResult(HttpStatus::HTTP_OK, AdvertisementMapper::toJson(found.value()));
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
    }
    catch(invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult AdvertisementController::postAdvertisement(const std::string &typeProperty,
                                                      const std::string &typeBusiness, float price,
                                                      const shared_ptr<Property> &property,
                                                      const shared_ptr<Client> &client,
                                                      shared_ptr<Agent> &agent) {
    HttpResult result;
    try {
        shared_ptr<AdvertisementService> service = this->company->getAdvertisementService();
        shared_ptr<Advertisement> adv = service->create(typeProperty, typeBusiness, price, property, client, agent);
        Result res = service->addOrUpdate(adv);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK_CREATED);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, res.getMessage());

    } catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

// PUT /advertisements/{id}
HttpResult AdvertisementController::putAdvertisement(const wstring& id, const string& typeProperty, const string& typeBusiness, float price, bool isSold, bool visibility) {
    HttpResult result;
    try {
        shared_ptr<AdvertisementService> advertisementService = this->company->getAdvertisementService();
        optional<shared_ptr<Advertisement>> advertisementOpt = advertisementService->getByCode(id);

        if (!advertisementOpt.has_value()) {
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
            return result;
        }

        const shared_ptr<Advertisement>& advertisement = advertisementOpt.value();


        advertisement->setTypeProperty(typeProperty);
        advertisement->setTypeBusiness(typeBusiness);
        advertisement->setPrice(price);
        advertisement->setSoldStatus(isSold);
        advertisement->setVisibility(visibility);


        Result res = advertisementService->addOrUpdate(advertisement);

        if (advertisementService) {
            result = HttpResult(HttpStatus::HTTP_OK);
        } else {
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, "Failed to update advertisement");
        }
    }
    catch (invalid_argument& e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

// DELETE /advertisements/{id}
HttpResult AdvertisementController::deleteAdvertisement(const wstring& id) {
    HttpResult result;
    try {
        shared_ptr<AdvertisementService> advertisementService = this->company->getAdvertisementService();
        Result deleteResult = advertisementService->remove(id);

        if (deleteResult.isOK()) {
            result = HttpResult(HttpStatus::HTTP_OK);
        } else {
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
        }
    }
    catch (invalid_argument& e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}