//
// Created by Angelo on 04/01/2025.
//



#ifndef DHMS_PURCHASEOFFERMEMORYREPOSITORY_H
#define DHMS_PURCHASEOFFERMEMORYREPOSITORY_H

#include "domain/repositories/PurchaseOfferRepository.h"
#include "MemoryRepository.h"
#include "../model/PurchaseOffer.h"
#include "../model/PurchaseOfferId.h"

class PurchaseOfferMemoryRepository : public PurchaseOfferRepository, public MemoryRepository<PurchaseOffer, PurchaseOfferId>{
private:
public:
    PurchaseOfferMemoryRepository();

    virtual optional<shared_ptr<PurchaseOffer>> getById(const wstring &id);
};

#endif //DHMS_PURCHASEOFFERMEMORYREPOSITORY_H

