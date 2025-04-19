//
// Created by Tiago Cunha on 08/01/2025.
//

#include "headers/domain/services/ClientService.h"

ClientService::ClientService(shared_ptr<ClientRepository> repo) {
    this->repo = repo;
}

shared_ptr<Client> ClientService::create(const std::wstring &code, const std::string &name, const optional<string> &idNumber,
                                         const std::string &tif, const std::string &email, const std::string &phoneNumber) {
    return make_shared<Client>(code, name, idNumber, tif, email, phoneNumber);
}

Result ClientService::addOrUpdate(shared_ptr<Client> obj) {
    return this->repo->save(obj);
}

Result ClientService::remove(const std::wstring &code) {
    optional<shared_ptr<Client>> obj = this->repo->getById(code);
    if(obj.has_value()){
        shared_ptr<Client> client = obj.value();
        return this->repo->remove(client);
    }
    return Result::NOK(L"Client not found.");
}

list <shared_ptr<Client>> ClientService::getAll() {
    return this->repo->getAll();
}

optional<shared_ptr<Client>> ClientService::getByCode(const std::wstring &code) {
    return this->repo->getById(code);
}

Result ClientService::changeName(const std::wstring &code, const std::string &name) {
    optional<shared_ptr<Client>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Client> client = obj.value();
        Result result = client->changeName(name);
        if (result.isOK())
            return this->repo->save(client);
        else
            return result;
    }
    return Result::NOK(L"Client not found.");
}

Result ClientService::changeIdNumber(const std::wstring &code, const optional<std::string> &idNumber) {
    optional<shared_ptr<Client>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Client> client = obj.value();
        Result result = client->changeIdNumber(idNumber);
        if (result.isOK())
            return this->repo->save(client);
        else
            return result;
    }
    return Result::NOK(L"Client not found.");
}

Result ClientService::changeTif(const std::wstring &code, const std::string &tif) {
    optional<shared_ptr<Client>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Client> client = obj.value();
        Result result = client->changeTif(tif);
        if (result.isOK())
            return this->repo->save(client);
        else
            return result;
    }
    return Result::NOK(L"Client not found.");
}

Result ClientService::changeEmail(const std::wstring &code, const std::string &email) {
    optional<shared_ptr<Client>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Client> client = obj.value();
        Result result = client->changeEmail(email);
        if (result.isOK())
            return this->repo->save(client);
        else
            return result;
    }
    return Result::NOK(L"Client not found.");
}

Result ClientService::changePhoneNumber(const std::wstring &code, const std::string &phoneNumber) {
    optional<shared_ptr<Client>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Client> client = obj.value();
        Result result = client->changePhoneNumber(phoneNumber);
        if (result.isOK())
            return this->repo->save(client);
        else
            return result;
    }
    return Result::NOK(L"Client not found.");
}