//
// Created by Tiago Cunha on 07/01/2025.
//

#ifndef DHMS_CLIENTMAPPER_H
#define DHMS_CLIENTMAPPER_H

#include "thirdparty/SimpleJson.hpp"
#include "../../../domain/model/Client.h"
#include <string>
#include <list>
#include <memory>


using namespace std;
using json::JSON;

class ClientMapper {
public:
    static JSON toJson(shared_ptr<Client> obj);

    static JSON toJson(list<shared_ptr<Client>> objs);
};

#endif //DHMS_CLIENTMAPPER_H
