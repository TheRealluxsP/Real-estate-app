//
// Created by Angelo on 04/01/2025.
//


#include "domain/services/PurchaseOfferService.h"

PurchaseOfferService::PurchaseOfferService(shared_ptr<PurchaseOfferRepository> repo) {
    this->repo = repo;
}

shared_ptr<PurchaseOffer> PurchaseOfferService::create(float value, const shared_ptr<Advertisement>& adv, const shared_ptr<Client>& client) {
    return make_shared<PurchaseOffer>(value, adv, client);
}

Result PurchaseOfferService::addOrUpdate(shared_ptr<PurchaseOffer> obj) {
    return this->repo->save(obj);
}

Result PurchaseOfferService::remove(const std::wstring &code) {
    optional<shared_ptr<PurchaseOffer>> obj = this->repo->getById(code);
    if(obj.has_value()){
        shared_ptr<PurchaseOffer> PurchaseOffer = obj.value();
        return this->repo->remove(PurchaseOffer);
    }
    return Result::NOK(L"Agent not found.");
}

list <shared_ptr<PurchaseOffer>> PurchaseOfferService::getAll() {
    return this->repo->getAll();
}



optional<shared_ptr<PurchaseOffer>> PurchaseOfferService::getByCode(const std::wstring &code) {
    return this->repo->getById(code);
}