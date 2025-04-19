//
// Created by siulo on 02/01/2025.
//

#include "headers/controllers/restapi/StoreController.h"
#include "headers/controllers/restapi/mappers/StoreMapper.h"
#include "domain/services/StoreService.h"
#include <optional>

HttpResult StoreController::getAll() {
    HttpResult result;
    try{
        shared_ptr<StoreService> service = this->company->getStoreService();
        list<shared_ptr<Store>> stores = service->getAll();
        result = HttpResult(HttpStatus::HTTP_OK, StoreMapper::toJson(stores));
    }
    catch (invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult StoreController::getById(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<StoreService> service = this->company->getStoreService();
        optional<shared_ptr<Store>> found = service->getByCode(code);
        if (found.has_value())
            result = HttpResult(HttpStatus::HTTP_OK, StoreMapper::toJson(found.value()));
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
    }
    catch(invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult StoreController::postStore(const std::wstring &code, const std::string &designation,
                                      const std::string &address, const std::string &openingTime,
                                      const std::string &closingTime) {
    HttpResult result;
    try {
        shared_ptr<StoreService> service = this->company->getStoreService();
        shared_ptr<Store> store = service->create(code, designation, address, openingTime, closingTime);
        Result res = service->addOrUpdate(store);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK_CREATED);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, res.getMessage());

    } catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult StoreController::putStore(const wstring &code, const string &designation, const string& address, const string& openingTime, const string& closingTime) {
    HttpResult result;
    try {
        shared_ptr<StoreService> service = this->company->getStoreService();
        // Update designation
        Result desRes = service->changeDesignation(code, designation);
        if (!desRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, desRes.getMessage());
        }

        // Update address
        Result addRes = service->changeAddress(code, address);
        if (!addRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, addRes.getMessage());
        }

        // Update opening time
        Result openTimeRes = service->changeOpeningTime(code, openingTime);
        if (!openTimeRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, openTimeRes.getMessage());
        }

        // Update closing time
        Result closeTimeRes = service->changeClosingTime(code, closingTime);
        if (!closeTimeRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, closeTimeRes.getMessage());
        }

        // If all updates succeed, return HTTP_OK
        result = HttpResult(HttpStatus::HTTP_OK);
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult StoreController::deleteStore(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<StoreService> service = this->company->getStoreService();
        Result res = service->remove(code);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND, res.getMessage());
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}