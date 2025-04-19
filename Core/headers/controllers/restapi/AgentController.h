//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTCONTROLLER_H
#define DHMS_AGENTCONTROLLER_H

#include "RestController.h"
#include "HttpResult.h"

class AgentController : public RestController{
protected:

public:
    AgentController(const wstring &userToken) : RestController(userToken){};

    HttpResult getAll();

    HttpResult getById(const wstring &code);

    HttpResult postAgent(const string& name, const optional<string> &idNumber, const string& email, const string& phoneNumber, const shared_ptr<Store> &store);

    HttpResult putAgent(const wstring& code, const string& name, const optional<string> &idNumber, const string& email, const string& phoneNumber, const shared_ptr<Store> &store);

    HttpResult deleteAgent(const wstring &code);
};


#endif //DHMS_AGENTCONTROLLER_H
