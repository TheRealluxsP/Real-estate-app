//
// Created by Angelo on 04/01/2025.
//

#include "headers/infrastructure/memory/PurchaseOfferMemoryRepository.h"



using namespace std;

PurchaseOfferMemoryRepository::PurchaseOfferMemoryRepository() : MemoryRepository<PurchaseOffer, PurchaseOfferId>(){

}

optional<shared_ptr<PurchaseOffer>> PurchaseOfferMemoryRepository::getById(const wstring &id) {
    for(list<shared_ptr<PurchaseOffer>>::iterator it = container.begin(); it != container.end(); ++it){
        shared_ptr<PurchaseOffer> obj = *it;
        if(obj->hasCode(id))
            return make_optional<shared_ptr<PurchaseOffer>>(obj);
    }

    return nullopt;
}

