//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#ifndef DHMS_ADVERTISEMENTMEMORYREPOSITORY_H
#define DHMS_ADVERTISEMENTMEMORYREPOSITORY_H

#include "domain/repositories/AdvertisementRepository.h"
#include "MemoryRepository.h"
#include "domain/model/Advertisement.h"
#include <list>
#include <memory>
#include <unordered_map>
#include <string>
//#include <uuid/uuid.h>  // For generating unique UUIDs

using namespace std;

class AdvertisementMemoryRepository : public AdvertisementRepository, public MemoryRepository<Advertisement, AdvertisementId> {
public:
    AdvertisementMemoryRepository();

    virtual optional<shared_ptr<Advertisement>> getById(const wstring &code);

};

#endif //DHMS_ADVERTISEMENTMEMORYREPOSITORY_H