//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#ifndef DHMS_ADVERTISEMENTREPOSITORY_H
#define DHMS_ADVERTISEMENTREPOSITORY_H

#include "domain/model/Advertisement.h"
#include "Repository.h"
#include <memory>
#include <list>
#include <string>

using namespace std;

class AdvertisementRepository : virtual public Repository<Advertisement, AdvertisementId> {
public:

    virtual optional<shared_ptr<Advertisement>> getById(const wstring &code) = 0;
};

#endif //DHMS_ADVERTISEMENTREPOSITORY_H