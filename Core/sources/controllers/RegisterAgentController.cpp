
#include "controllers/RegisterAgentController.h"

// Constructor
RegisterAgentController::RegisterAgentController() = default;

// Get all stores
list<shared_ptr<Store>> RegisterAgentController::getAllStores() {
    this->storeService = Company::GetInstance()->getStoreService();
    this->storeList = storeService->getAll();

    return storeList;
}

// Get a store by code
/*
optional<shared_ptr<Store>> RegisterAgentController::getStoreByCode(const wstring& code){
    this->storeService = Company::GetInstance()->getStoreService();
    this->store = storeService->getByCode(code);

    return store;
}
*/

// Register a new agent
Result RegisterAgentController::registerAgent(const string& name, const optional<string>& idNumber, const string& email, const string& phoneNumber,const wstring& storeCode) {
    this->agentService = Company::GetInstance()->getAgentService();
    this->storeService = Company::GetInstance()->getStoreService();
    shared_ptr<Store> store = storeService->getByCode(storeCode).value();
    this->agent = agentService->create(name, idNumber, email, phoneNumber, store);

    if(this->agent) {
        return this->agentService->addOrUpdate(this->agent);
    }
    return Result::NOK(L"Agent could not be created.");

}
