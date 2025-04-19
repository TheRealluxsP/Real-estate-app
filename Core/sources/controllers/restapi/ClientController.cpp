//
// Created by Tiago Cunha on 07/01/2025.
//

#include "headers/controllers/restapi/ClientController.h"
#include "headers/controllers/restapi/mappers/ClientMapper.h"
#include <optional>

HttpResult ClientController::getAll() {
    HttpResult result;
    try{
        shared_ptr<ClientService> service = this->company->getClientService();
        list<shared_ptr<Client>> clients = service->getAll();
        result = HttpResult(HttpStatus::HTTP_OK, ClientMapper::toJson(clients));
    }
    catch (invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult ClientController::getById(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<ClientService> service = this->company->getClientService();
        optional<shared_ptr<Client>> found = service->getByCode(code);
        if (found.has_value())
            result = HttpResult(HttpStatus::HTTP_OK, ClientMapper::toJson(found.value()));
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
    }
    catch(invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult ClientController::postClient(const std::wstring &code, const std::string &name, const optional<string> &idNumber, const std::string &tif,
                                      const std::string &email, const std::string &phoneNumber) {
    HttpResult result;
    try {
        shared_ptr<ClientService> service = this->company->getClientService();
        shared_ptr<Client> client = service->create(code, name, idNumber, tif, email, phoneNumber);
        Result res = service->addOrUpdate(client);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK_CREATED);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, res.getMessage());

    } catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult ClientController::putClient(const wstring &code, const string &name, const optional<string> &idNumber, const string& tif, const string& email, const string& phoneNumber) {
    HttpResult result;
    try {
        shared_ptr<ClientService> service = this->company->getClientService();
        // Update name
        Result nameRes = service->changeName(code, name);
        if (!nameRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, nameRes.getMessage());
        }

        Result idRes = service->changeIdNumber(code, idNumber);
        if (!idRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, nameRes.getMessage());
        }

        // Update tif
        Result tifRes = service->changeTif(code, tif);
        if (!tifRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, tifRes.getMessage());
        }

        // Update email address
        Result emailRes = service->changeEmail(code, email);
        if (!emailRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, emailRes.getMessage());
        }

        // Update phone number
        Result phoneRes = service->changePhoneNumber(code, phoneNumber);
        if (!phoneRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, phoneRes.getMessage());
        }

        // If all updates succeed, return HTTP_OK
        result = HttpResult(HttpStatus::HTTP_OK);
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult ClientController::deleteClient(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<ClientService> service = this->company->getClientService();
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