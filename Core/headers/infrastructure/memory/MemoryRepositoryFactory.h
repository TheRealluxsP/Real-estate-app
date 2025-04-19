//
// Created by siulo on 29/12/2024.
//

#ifndef DHMS_MEMORYREPOSITORYFACTORY_H
#define DHMS_MEMORYREPOSITORYFACTORY_H

#include "domain/repositories/RepositoryFactory.h"
#include "StoreMemoryRepository.h"
#include "AgentMemoryRepository.h"
#include "ClientMemoryRepository.h"
#include "AdvertisementMemoryRepository.h"
#include "PurchaseOfferMemoryRepository.h"

class MemoryRepositoryFactory : public RepositoryFactory{
private:
    shared_ptr<StoreRepository> stores = make_shared<StoreMemoryRepository>();
    shared_ptr<AgentRepository> agents = make_shared<AgentMemoryRepository>();
    shared_ptr<ClientRepository> clients = make_shared<ClientMemoryRepository>();
    shared_ptr<AdvertisementRepository> advertisements = make_shared<AdvertisementMemoryRepository>();
    shared_ptr<PurchaseOfferRepository> purchaseOffers = make_shared<PurchaseOfferMemoryRepository>();

public:
    MemoryRepositoryFactory();

    virtual shared_ptr<StoreRepository> getStoreRepository() override;
    virtual shared_ptr<AgentRepository> getAgentRepository() override;
    virtual shared_ptr<ClientRepository> getClientRepository() override;
    virtual shared_ptr<AdvertisementRepository> getAdvertisementRepository() override;
    virtual shared_ptr<PurchaseOfferRepository> getPurchaseOfferRepository() override;

};

#endif //DHMS_MEMORYREPOSITORYFACTORY_H
