//
// Created by Angelo on 15/11/2024.
//

#ifndef DHMS_REGISTERAGENTCONTROLLER_H
#define DHMS_REGISTERAGENTCONTROLLER_H

#include <string>
#include <memory>
#include <optional>
#include <list>
#include "Company.h"
#include "headers/domain/model/Store.h"
#include "headers/domain/services/StoreService.h"
#include "headers/domain/services/AgentService.h"
#include "headers/domain/model/Agent.h"
#include "Result.h"

using namespace std;

class RegisterAgentController {

private:

    shared_ptr<Agent> agent;
    list<shared_ptr<Store>> storeList;
    shared_ptr<StoreService> storeService;
    shared_ptr<AgentService> agentService;

public:
    // Constructor
    RegisterAgentController();

    // Get all stores
    list<shared_ptr<Store>> getAllStores();

    // Get a store by code
    /*
    optional<shared_ptr<Store>> getStoreByCode(const wstring& code);

     */
    // Register a new agent
    Result registerAgent(const string& name, const optional<string>& idNumber, const string& email, const string& phoneNumber, const wstring& storeCode);

};

#endif // DHMS_REGISTERAGENTCONTROLLER_H
