//
// Created by siulo on 02/01/2025.
//

#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"

MemoryRepositoryFactory::MemoryRepositoryFactory() {

}

shared_ptr<StoreRepository> MemoryRepositoryFactory::getStoreRepository() {
    return this->stores;
}

shared_ptr<AgentRepository> MemoryRepositoryFactory::getAgentRepository() {
    return this->agents;
}

shared_ptr<ClientRepository> MemoryRepositoryFactory::getClientRepository() {
    return this->clients;
}


shared_ptr<AdvertisementRepository> MemoryRepositoryFactory::getAdvertisementRepository() {
    return this->advertisements;
}

shared_ptr<PurchaseOfferRepository> MemoryRepositoryFactory::getPurchaseOfferRepository() {
    return this->purchaseOffers;
}



