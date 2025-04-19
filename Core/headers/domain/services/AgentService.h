//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTSERVICE_H
#define DHMS_AGENTSERVICE_H

#include "domain/model/AgentDTO.h"
#include "domain/repositories/AgentRepository.h"

class AgentService {
private:
    shared_ptr<AgentRepository> repo;

public:
    AgentService(shared_ptr<AgentRepository> repo);

    virtual shared_ptr<Agent> create(const string& name, const optional<string>& idNumber, const string& email, const string& phoneNumber, const shared_ptr<Store> &store);

    virtual Result addOrUpdate(shared_ptr<Agent> obj);

    virtual Result remove(const wstring &code);

    virtual list<shared_ptr<Agent>> getAll();

    virtual list<shared_ptr<AgentDTO>> getAllDTO();

    virtual optional<shared_ptr<Agent>> getByCode(const wstring &code);

    virtual Result changeName(const wstring& code, const string& name);

    virtual Result changeIdNumber(const wstring& code, const optional<string>& idNumber);

    virtual Result changeEmail(const wstring& code, const string& email);

    virtual Result changePhoneNumber(const wstring& code, const string& phoneNumber);

    virtual Result changeStore(const wstring& code, const shared_ptr<Store> &store);

};


#endif //DHMS_AGENTSERVICE_H
