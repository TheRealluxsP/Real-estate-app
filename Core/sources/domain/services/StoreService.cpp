//
// Created by siulo on 02/01/2025.
//

#include "headers/domain/services/StoreService.h"

StoreService::StoreService(shared_ptr<StoreRepository> repo) {
    this->repo = repo;
}

shared_ptr<Store> StoreService::create(const std::wstring &code, const std::string &designation,
                                       const std::string &address, const std::string &openingTime,
                                       const std::string &closingTime) {
    return make_shared<Store>(code, designation, address, openingTime, closingTime);
}

Result StoreService::createAndSaveStore(const std::wstring &code, const std::string &designation,
                                        const std::string &address, const std::string &openingTime,
                                        const std::string &closingTime) {


    return this->repo->save(make_shared<Store>(code, designation, address, openingTime, closingTime));
}

Result StoreService::addOrUpdate(shared_ptr<Store> obj) {
    return this->repo->save(obj);
}

Result StoreService::remove(const std::wstring &code) {
    optional<shared_ptr<Store>> obj = this->repo->getById(code);
    if(obj.has_value()){
        shared_ptr<Store> store = obj.value();
        return this->repo->remove(store);
    }
    return Result::NOK(L"Store not found.");
}

list <shared_ptr<Store>> StoreService::getAll() {
    return this->repo->getAll();
}

optional<shared_ptr<Store>> StoreService::getByCode(const std::wstring &code) {
    return this->repo->getById(code);
}

Result StoreService::changeDesignation(const std::wstring &code, const std::string &designation) {
    optional<shared_ptr<Store>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Store> store = obj.value();
        Result result = store->changeDesignation(designation);
        if (result.isOK())
            return this->repo->save(store);
        else
            return result;
    }
    return Result::NOK(L"Store not found.");
}

Result StoreService::changeAddress(const std::wstring &code, const std::string &address) {
    optional<shared_ptr<Store>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Store> store = obj.value();
        Result result = store->changeAddress(address);
        if (result.isOK())
            return this->repo->save(store);
        else
            return result;
    }
    return Result::NOK(L"Store not found.");
}

Result StoreService::changeOpeningTime(const std::wstring &code, const std::string &openingTime) {
    optional<shared_ptr<Store>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Store> store = obj.value();
        Result result = store->changeOpeningTime(openingTime);
        if (result.isOK())
            return this->repo->save(store);
        else
            return result;
    }
    return Result::NOK(L"Store not found.");
}

Result StoreService::changeClosingTime(const std::wstring &code, const std::string &closingTime) {
    optional<shared_ptr<Store>> obj = this->repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Store> store = obj.value();
        Result result = store->changeClosingTime(closingTime);
        if (result.isOK())
            return this->repo->save(store);
        else
            return result;
    }
    return Result::NOK(L"Store not found.");
}
