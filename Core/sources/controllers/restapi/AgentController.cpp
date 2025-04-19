//
// Created by Angelo on 07/01/2025.
//

#include "headers/controllers/restapi/AgentController.h"
#include "headers/controllers/restapi/mappers/AgentMapper.h"
#include "domain/services/StoreService.h"
#include <optional>

HttpResult AgentController::getAll() {
    HttpResult result;
    try{
        shared_ptr<AgentService> service = this->company->getAgentService();
        list<shared_ptr<Agent>> agents = service->getAll();
        result = HttpResult(HttpStatus::HTTP_OK, AgentMapper::toJson(agents));
    }
    catch (invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult AgentController::getById(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<AgentService> service = this->company->getAgentService();
        optional<shared_ptr<Agent>> found = service->getByCode(code);
        if (found.has_value())
            result = HttpResult(HttpStatus::HTTP_OK, AgentMapper::toJson(found.value()));
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND);
    }
    catch(invalid_argument e){
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult AgentController::postAgent(const std::string &name, const optional<string> &idNumber,
                                      const std::string &email, const std::string &phoneNumber,
                                      const shared_ptr<Store> &store) {
    HttpResult result;
    try {
        shared_ptr<AgentService> service = this->company->getAgentService();
        shared_ptr<Agent> agent = service->create(name, idNumber, email, phoneNumber, store);
        Result res = service->addOrUpdate(agent);
        if (res.isOK())
            result = HttpResult(HttpStatus::HTTP_OK_CREATED);
        else
            result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, res.getMessage());

    } catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult AgentController::putAgent(const wstring &code, const string &name, const optional<string> &idNumber, const string& email, const string& phoneNumber, const shared_ptr<Store> &store) {
    HttpResult result;
    try {
        shared_ptr<AgentService> service = this->company->getAgentService();
        // Update name
        Result nameRes = service->changeName(code, name);
        if (!nameRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, nameRes.getMessage());
        }

        Result idRes = service->changeIdNumber(code, idNumber);
        if (!idRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, nameRes.getMessage());
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

        // Update closing time
        Result storeRes = service->changeStore(code, store);
        if (!storeRes.isOK()) {
            return HttpResult(HttpStatus::HTTP_CLIENT_ERROR_FORBIDDEN, storeRes.getMessage());
        }

        // If all updates succeed, return HTTP_OK
        result = HttpResult(HttpStatus::HTTP_OK);
    }
    catch (invalid_argument e) {
        result = HttpResult(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST, e.what());
    }
    return result;
}

HttpResult AgentController::deleteAgent(const std::wstring &code) {
    HttpResult result;
    try {
        shared_ptr<AgentService> service = this->company->getAgentService();
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
