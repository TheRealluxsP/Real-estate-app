//
// Created by Tiago Cunha on 08/01/2025.
//

#ifndef DHMS_CLIENTMEMORYREPOSITORY_H
#define DHMS_CLIENTMEMORYREPOSITORY_H

#include "domain/repositories/ClientRepository.h"
#include "MemoryRepository.h"
#include "../model/Client.h"
#include "../model/ClientId.h"

class ClientMemoryRepository : public ClientRepository, public MemoryRepository<Client, ClientId>{
private:
public:
    ClientMemoryRepository();

    virtual optional<shared_ptr<Client>> getById(const wstring &code);
};

#endif //DHMS_CLIENTMEMORYREPOSITORY_H
