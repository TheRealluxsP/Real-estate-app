//
// Created by Tiago Cunha on 08/01/2025.
//

#ifndef DHMS_CLIENTSERVICE_H
#define DHMS_CLIENTSERVICE_H

#include "domain/repositories/ClientRepository.h"

class ClientService {
private:
    shared_ptr<ClientRepository> repo;

public:
    ClientService(shared_ptr<ClientRepository> repo);

    virtual shared_ptr<Client> create(const wstring& code, const string& name, const optional<string> &idNumber, const string& tif, const string& email, const string& phoneNumber);

    virtual Result addOrUpdate(shared_ptr<Client> obj);

    virtual Result remove(const wstring &code);

    virtual list<shared_ptr<Client>> getAll();

    virtual optional<shared_ptr<Client>> getByCode(const wstring &code);

    virtual Result changeName(const wstring& code, const string& name);

    virtual Result changeIdNumber(const wstring& code, const optional<string>& idNumber);

    virtual Result changeTif(const wstring& code, const string& tif);

    virtual Result changeEmail(const wstring& code, const string& email);

    virtual Result changePhoneNumber(const wstring& code, const string& phoneNumber);

};

#endif //DHMS_CLIENTSERVICE_H
