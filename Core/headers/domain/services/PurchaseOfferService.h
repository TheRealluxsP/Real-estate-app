//
// Created by Angelo on 04/01/2025.
//



#ifndef DHMS_PURCHASEOFFERSERVICE_H
#define DHMS_PURCHASEOFFERSERVICE_H

#include "domain/repositories/PurchaseOfferRepository.h"

class PurchaseOfferService {
private:
    shared_ptr<PurchaseOfferRepository> repo;
public:
    PurchaseOfferService(shared_ptr<PurchaseOfferRepository> repo);

    shared_ptr<PurchaseOffer> create(float value, const std::shared_ptr<Advertisement>& adv, const std::shared_ptr<Client>& client);

    virtual Result addOrUpdate(shared_ptr<PurchaseOffer> obj);

    virtual Result remove(const wstring &code);

    virtual list<shared_ptr<PurchaseOffer>> getAll();

    virtual optional<shared_ptr<PurchaseOffer>> getByCode(const wstring &code);



};




#endif //DHMS_PURCHASEOFFERSERVICE_H


