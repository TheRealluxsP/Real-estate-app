//
// Created by Angelo on 04/01/2025.
//



#ifndef DHMS_PURCHASEOFFERREPOSITORY_H
#define DHMS_PURCHASEOFFERREPOSITORY_H

#include "../model/PurchaseOffer.h"
#include "../model/PurchaseOfferId.h"
#include "Repository.h"

class PurchaseOfferRepository : virtual public Repository<PurchaseOffer, PurchaseOfferId>{
public:
    virtual optional<shared_ptr<PurchaseOffer>> getById(const wstring &id) = 0;
};



#endif //DHMS_PURCHASEOFFERREPOSITORY_H


