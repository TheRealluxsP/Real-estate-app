//
// Created by siulo on 28/12/2024.
//

#ifndef DHMS_REPOSITORYFACTORY_H
#define DHMS_REPOSITORYFACTORY_H

#include "StoreRepository.h"
#include "AdvertisementRepository.h"
#include "PurchaseOfferRepository.h"
#include "AgentRepository.h"
#include "ClientRepository.h"


class RepositoryFactory{
public:
    virtual shared_ptr<StoreRepository> getStoreRepository() = 0;
    virtual shared_ptr<AgentRepository> getAgentRepository() = 0;
    virtual shared_ptr<ClientRepository> getClientRepository() = 0;
    virtual shared_ptr<AdvertisementRepository> getAdvertisementRepository() = 0;
    virtual shared_ptr<PurchaseOfferRepository> getPurchaseOfferRepository() = 0;

};

#endif //DHMS_REPOSITORYFACTORY_H
