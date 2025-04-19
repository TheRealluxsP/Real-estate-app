//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#include "headers/domain/services/AdvertisementService.h"
#include "headers/domain/repositories/AdvertisementRepository.h"

// Constructor that initializes the repository
AdvertisementService::AdvertisementService(shared_ptr<AdvertisementRepository> repo) {
    this->repo = repo;
}

// Create or update advertisement logic
shared_ptr<Advertisement> AdvertisementService::create(const string& typeProperty, const string& typeBusiness, float price,
                                                       const shared_ptr<Property>& property, const shared_ptr<Client>& client, shared_ptr<Agent>& agent) {
    return make_shared<Advertisement>(typeProperty, typeBusiness, price, property, client, agent);
}

Result AdvertisementService::addOrUpdate(shared_ptr<Advertisement> obj) {
    return this->repo->save(obj);
}

// Get all advertisements
list<shared_ptr<Advertisement>> AdvertisementService::getAll() {
    return this->repo->getAll();
}

list<shared_ptr<Advertisement>> AdvertisementService::getAllDealsMade() {
    list<shared_ptr<Advertisement>> advList = this->repo->getAll();
    list<shared_ptr<Advertisement>> soldAdvList;

    for (shared_ptr<Advertisement> adv : advList) {
        if(adv->isAdvertisementSold()) {
            soldAdvList.push_back(adv);
        }
    }

    return soldAdvList;
}

map<shared_ptr<StoreDTO>, map<string, list<shared_ptr<AdvertisementDTO>>>> AdvertisementService::getAllDealsGroupedByStore(list<shared_ptr<AdvertisementDTO> > &soldAdvListDTO) {
    map<shared_ptr<StoreDTO>, map<string, list<shared_ptr<AdvertisementDTO>>>> storeGroupedAdsDTO;

    for (shared_ptr<AdvertisementDTO> advDTO : soldAdvListDTO) {
        storeGroupedAdsDTO[advDTO->storeDto][advDTO->typeBusiness].push_back(advDTO);
    }

    return storeGroupedAdsDTO;
}



// Get advertisement by ID
optional<shared_ptr<Advertisement>> AdvertisementService::getByCode(const std::wstring &code) {
    return this->repo->getById(code);
}

// Delete advertisement by ID
Result AdvertisementService::remove(const std::wstring &code) {
    optional<shared_ptr<Advertisement>> obj = repo->getById(code);
    if (obj.has_value()) {
        shared_ptr<Advertisement> advertisement = obj.value();
        return this->repo->remove(advertisement);
    }
    return Result::NOK(L"Advertisement not found.");
}

// Change the price of an advertisement
Result AdvertisementService::changePrice(const wstring &id, float price) {
    optional<shared_ptr<Advertisement>> obj = this->repo ->getById(id);
    if (obj.has_value()) {
        shared_ptr<Advertisement> advertisement = obj.value();
        advertisement->setPrice(price);
        repo->save(advertisement); // Return the updated advertisement after saving
        return Result::OK(L"Price updated successfully.");
    }
    return Result::NOK(L"Advertisement not found.");
}

// Change the sold status of an advertisement
Result AdvertisementService::changeSoldStatus(const wstring &id, bool isSold) {
    optional<shared_ptr<Advertisement>> ad = this->repo->getById(id);
    if (ad.has_value()) {
        shared_ptr<Advertisement> advertisement = ad.value();
        advertisement->setSoldStatus(isSold);
        repo->save(advertisement); // Return the updated advertisement after saving
        return Result::OK(L"Sold status updated successfully.");
    }
    return Result::NOK(L"Advertisement not found.");
}

// Change the visibility of an advertisement
Result AdvertisementService::changeVisibility(const wstring &id, bool visibility) {
    optional<shared_ptr<Advertisement>> ad = repo->getById(id);
    if (ad.has_value()) {
        shared_ptr<Advertisement> advertisement = ad.value();
        advertisement->setVisibility(visibility);
        repo->save(advertisement); // Return the updated advertisement after saving
        return Result::OK(L"Visibility updated successfully.");
    }
    return Result::NOK(L"Advertisement not found.");
}

// Change the commission of an advertisement
Result AdvertisementService::changeCommission(const wstring &id, float commission) {
    optional<shared_ptr<Advertisement>> ad = repo->getById(id);
    if (ad.has_value()) {
        shared_ptr<Advertisement> advertisement = ad.value();
        advertisement->setCommission(commission);
        repo->save(advertisement); // Return the updated advertisement after saving
        return Result::OK(L"Commission updated successfully.");
    }
    return Result::NOK(L"Advertisement not found.");
}

list<shared_ptr<Advertisement>> AdvertisementService::getAvailableAdvertisements() {
    // Get all advertisements from the repository
    auto advList = repo->getAll();

    // Filter advertisements that are visible and not sold
    list<shared_ptr<Advertisement>> availableAdvs;
    for (const auto &adv : advList) {
        if (adv->isAdvertisementVisible() && !adv->isAdvertisementSold()) {
            availableAdvs.push_back(adv);
        }
    }

    return availableAdvs;
}