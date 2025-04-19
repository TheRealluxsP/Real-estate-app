//
// Created by Angelo on 07/01/2025.
//

#include "headers/domain/services/AgentService.h"

#include "controllers/restapi/mappers/AgentMapper.h"

AgentService::AgentService(shared_ptr<AgentRepository> repo) {
    this->repo = repo;
}

shared_ptr<Agent> AgentService::create(const std::string &name, const optional<string> &idNumber,
                                       const std::string &email, const std::string &phoneNumber,
                                       const shared_ptr<Store> &store) {
    return make_shared<Agent>(name, idNumber, email, phoneNumber, store);
}

Result AgentService::addOrUpdate(shared_ptr<Agent> obj) {

    list<shared_ptr<Agent>> agents = this->repo->getAll();
    for (const auto& existingAgent : agents) {
        if (existingAgent->getEmail() == obj->getEmail() && existingAgent->getCode() != obj->getCode()) {
            return Result::NOK(L"email already exists.");
        }
    }


    return this->repo->save(obj);
}

Result AgentService::remove(const std::wstring &code) {
    optional<shared_ptr<Agent>> obj = this->repo->getById(code);
    if(obj.has_value()){
        shared_ptr<Agent> agent = obj.value();
        return this->repo->remove(agent);
    }
    return Result::NOK(L"Agent not found.");
}

list <shared_ptr<Agent>> AgentService::getAll() {
    return this->repo->getAll();
}

list<shared_ptr<AgentDTO> > AgentService::getAllDTO() {
    list<shared_ptr<Agent>> list = this->repo->getAll();

    return AgentMapper::toDTO(list);
}


optional<shared_ptr<Agent>> AgentService::getByCode(const std::wstring &code) {
    return this->repo->getById(code);
}

Result AgentService::changeName(const std::wstring &code, const std::string &name) {
    optional<shared_ptr<Agent>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Agent> agent = obj.value();
        Result result = agent->changeName(name);
        if (result.isOK())
            return this->repo->save(agent);
        else
            return result;
    }
    return Result::NOK(L"Agent not found.");
}

Result AgentService::changeIdNumber(const std::wstring &code, const optional<std::string> &idNumber) {
    optional<shared_ptr<Agent>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Agent> agent = obj.value();
        Result result = agent->changeIdNumber(idNumber);
        if (result.isOK())
            return this->repo->save(agent);
        else
            return result;
    }
    return Result::NOK(L"Agent not found.");
}

Result AgentService::changeEmail(const std::wstring &code, const std::string &email) {
    optional<shared_ptr<Agent>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Agent> agent = obj.value();
        Result result = agent->changeEmail(email);
        if (result.isOK())
            return this->repo->save(agent);
        else
            return result;
    }
    return Result::NOK(L"Agent not found.");
}

Result AgentService::changePhoneNumber(const std::wstring &code, const std::string &phoneNumber) {
    optional<shared_ptr<Agent>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Agent> agent = obj.value();
        Result result = agent->changePhoneNumber(phoneNumber);
        if (result.isOK())
            return this->repo->save(agent);
        else
            return result;
    }
    return Result::NOK(L"Agent not found.");
}

Result AgentService::changeStore(const std::wstring &code, const shared_ptr<Store> &store) {
    optional<shared_ptr<Agent>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Agent> agent = obj.value();
        Result result = agent->changeStore(store);
        if (result.isOK())
            return this->repo->save(agent);
        else
            return result;
    }
    return Result::NOK(L"Agent not found.");
}