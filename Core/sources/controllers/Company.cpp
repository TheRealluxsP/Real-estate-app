//
// Created by Angelo on 15/11/2024.
//

#include "headers/controllers/Company.h"
#include "controllers/ConfigFileReader.h"
#include "infrastructure/memory/MemoryRepositoryFactory.h"

using namespace std;

// Initialize the static instance to nullptr
Company *Company::pinstance_{nullptr};
std::mutex Company::mutex_;

//Read the type of data persistence from the file
Company::Company()  {
    ConfigFileReader reader;
    ConfigObject cfg = reader.read_config("config.ini");
    this->repoFactory = this->createRepositoryFactory(cfg.persistenceMode);
}

Company::~Company(){}


// Get the singleton instance
Company *Company::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if(pinstance_ == nullptr){
        pinstance_ = new Company();
    }
    return pinstance_;
}

// Create the RepositoryFactory depending on the persistence mode
shared_ptr<RepositoryFactory> Company::createRepositoryFactory(const wstring &persistenceMode) {
    // By now the only known/available RepositoryFactory is the MemoryRepositoryFactory
    // Further, the "persistenceMode" argument must be evaluated to decide which one to create

    shared_ptr<RepositoryFactory> repoFactory = make_shared<MemoryRepositoryFactory>();
    return repoFactory;
}

shared_ptr<StoreService> Company::getStoreService() {
    return make_shared<StoreService>(this->repoFactory->getStoreRepository());
}

shared_ptr<AgentService> Company::getAgentService() {
    return make_shared<AgentService>(this->repoFactory->getAgentRepository());
}

shared_ptr<ClientService> Company::getClientService() {
    return make_shared<ClientService>(this->repoFactory->getClientRepository());
}


shared_ptr<AdvertisementService> Company::getAdvertisementService() {
    return make_shared<AdvertisementService>(this->repoFactory->getAdvertisementRepository());
}


shared_ptr<PurchaseOfferService> Company::getPurchaseOfferService() {
    return make_shared<PurchaseOfferService>(this->repoFactory->getPurchaseOfferRepository());
}
