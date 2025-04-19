//
// Created by Rui Monteiro on 04/01/2025.
//

#ifndef DHMS_ADVERTISEMENTSERVICE_H
#define DHMS_ADVERTISEMENTSERVICE_H

#include "domain/repositories/AdvertisementRepository.h"
#include "domain/model/Advertisement.h"
#include <list>
#include <memory>
#include <string>
#include <optional>
#include "Result.h"
#include "domain/model/AdvertisementDTO.h"

using namespace std;

class AdvertisementService {
private:
    shared_ptr<AdvertisementRepository> repo;  // Repository for managing advertisements

public:
    // Constructor that accepts a repository object
    AdvertisementService(shared_ptr<AdvertisementRepository> repo);

    // Create or update an advertisement
    virtual shared_ptr<Advertisement> create(const string& typeProperty, const string& typeBusiness, float price,
                                             const shared_ptr<Property>& property, const shared_ptr<Client>& client,  shared_ptr<Agent>& agent);

    virtual Result addOrUpdate(shared_ptr<Advertisement> obj);

    // Get all advertisements
    virtual list<shared_ptr<Advertisement>> getAll();

    virtual list<shared_ptr<Advertisement>> getAllDealsMade();

    virtual map<shared_ptr<StoreDTO>, map<string, list<shared_ptr<AdvertisementDTO>>>> getAllDealsGroupedByStore(list<shared_ptr<AdvertisementDTO>> &soldAdvListDTO);

    // Get an advertisement by ID
    virtual optional<shared_ptr<Advertisement>> getByCode(const wstring &code);

    // Delete an advertisement by ID
    virtual Result remove(const wstring &code);

    // Change the price of an advertisement
    virtual Result changePrice(const wstring &id, float price);

    // Change the sold status of an advertisement
    virtual Result changeSoldStatus(const wstring &id, bool isSold);

    // Change the visibility of an advertisement
    virtual Result changeVisibility(const wstring &id, bool visibility);

    // Change the commission of an advertisement
    virtual Result changeCommission(const wstring &id, float commission);

    virtual list<shared_ptr<Advertisement>> getAvailableAdvertisements();
};

#endif //DHMS_ADVERTISEMENTSERVICE_H