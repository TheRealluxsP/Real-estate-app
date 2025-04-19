//
// Created by Angelo on 15/11/2024.
//

#ifndef DHMS_COMPANY_H
#define DHMS_COMPANY_H

#include <memory>
#include <mutex>
#include "../repositories/RepositoryFactory.h"
#include "domain/services/AdvertisementService.h"
#include "domain/services/StoreService.h"
#include "domain/services/PurchaseOfferService.h"
#include "domain/services/AgentService.h"
#include "domain/services/ClientService.h"

using namespace std;

class Company {
private:
    static Company *pinstance_; // Singleton instance
    static mutex mutex_;
    shared_ptr<RepositoryFactory> repoFactory;

    shared_ptr<RepositoryFactory> createRepositoryFactory(const wstring &persistenceMode);

protected:
    // Private constructor to prevent direct instantiation
    Company();

    ~Company();

public:
    // Disable copying and assignment
    Company(Company &other) = delete;
    void operator=(const Company&) = delete;

    // Method to get the singleton instance
    static Company *GetInstance();

    virtual shared_ptr<StoreService> getStoreService();
    virtual shared_ptr<AgentService> getAgentService();
    virtual shared_ptr<ClientService> getClientService();

    virtual shared_ptr<AdvertisementService> getAdvertisementService();

    virtual shared_ptr<PurchaseOfferService> getPurchaseOfferService();




};

#endif // DHMS_COMPANY_H
