//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#include "headers/infrastructure/memory/AdvertisementMemoryRepository.h"
#include <stdexcept>

AdvertisementMemoryRepository::AdvertisementMemoryRepository() : MemoryRepository<Advertisement, AdvertisementId>(){

}

optional<shared_ptr<Advertisement>> AdvertisementMemoryRepository::getById(const std::wstring &code) {
    for(list<shared_ptr<Advertisement>>::iterator it = container.begin(); it!= container.end(); ++it){
        shared_ptr<Advertisement> obj = *it;
        if(obj->hasCode(code))
            return make_optional<shared_ptr<Advertisement>>(obj);
    }

    return nullopt;
}