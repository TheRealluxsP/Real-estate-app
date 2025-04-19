//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STORESERVICE_H
#define DHMS_STORESERVICE_H

#include "domain/repositories/StoreRepository.h"

class StoreService {
private:
    shared_ptr<StoreRepository> repo;

public:
    StoreService(shared_ptr<StoreRepository> repo);

    virtual shared_ptr<Store> create(const wstring& code, const string& designation, const string& address, const string& openingTime, const string& closingTime);

    virtual Result createAndSaveStore(const wstring& code, const string& designation, const string& address, const string& openingTime, const string& closingTime);

    virtual Result addOrUpdate(shared_ptr<Store> obj);

    virtual Result remove(const wstring &code);

    virtual list<shared_ptr<Store>> getAll();

    virtual optional<shared_ptr<Store>> getByCode(const wstring &code);

    virtual Result changeDesignation(const wstring& code, const string& designation);

    virtual Result changeAddress(const wstring& code, const string& address);

    virtual Result changeOpeningTime(const wstring& code, const string& openingTime);

    virtual Result changeClosingTime(const wstring& code, const string& closingTime);

};

#endif //DHMS_STORESERVICE_H
