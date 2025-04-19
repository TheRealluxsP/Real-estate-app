//
// Created by siulo on 02/01/2025.
//

#include "infrastructure/memory/StoreMemoryRepository.h"

using namespace std;

StoreMemoryRepository::StoreMemoryRepository() : MemoryRepository<Store, StoreId>(){

}

list<shared_ptr<Store>> StoreMemoryRepository::getAll() {
    list<shared_ptr<Store>> newList;
    newList.insert(newList.end(), container.begin(), container.end());
    return newList;
}

optional<shared_ptr<Store>> StoreMemoryRepository::getById(const wstring &code) {
    for(list<shared_ptr<Store>>::iterator it = container.begin(); it != container.end(); ++it){
        shared_ptr<Store> obj = *it;
        if(obj->hasCode(code))
            return make_optional<shared_ptr<Store>>(obj);
    }

    return nullopt;
}
