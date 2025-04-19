//
// Created by Tiago Cunha on 08/01/2025.
//

#include "headers/infrastructure/memory/ClientMemoryRepository.h"

using namespace std;

ClientMemoryRepository::ClientMemoryRepository() : MemoryRepository<Client, ClientId>(){

}

optional<shared_ptr<Client>> ClientMemoryRepository::getById(const wstring &code) {
    for (list<shared_ptr<Client>>::iterator it = container.begin(); it != container.end(); ++it) {
        shared_ptr<Client> obj = *it;
        if (obj->hasCode(code))
            return make_optional<shared_ptr<Client>>(obj);
    }

    return nullopt;
}