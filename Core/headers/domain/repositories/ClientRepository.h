//
// Created by Tiago Cunha on 08/01/2025.
//

#ifndef DHMS_CLIENTREPOSITORY_H
#define DHMS_CLIENTREPOSITORY_H

#include "../model/Client.h"
#include "../model/ClientId.h"
#include "Repository.h"

class ClientRepository : virtual public Repository<Client, ClientId>{
public:
    virtual optional<shared_ptr<Client>> getById(const wstring &code) = 0;
};

#endif //DHMS_CLIENTREPOSITORY_H
