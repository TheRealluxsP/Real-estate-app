//
// Created by Tiago Cunha on 07/01/2025.
//

#include "headers/controllers/restapi/mappers/ClientMapper.h"
#include "thirdparty/SimpleJson.hpp"
#include <list>
#include "headers/domain/shared/StringUtils.h"

using namespace std;
using json::JSON;

JSON ClientMapper::toJson(shared_ptr<Client> obj) {
    JSON result = JSON::Load("{}");
    result["code"] = StringUtils::toString(obj->getCode());
    result["name"] = obj->getName();
    result["idNumber"] = obj->getIdNumber().has_value() ? obj->getIdNumber().value() : "null";
    result["tif"] = obj->getTif();
    result["email"] = obj->getEmail();
    result["phoneNumber"] = obj->getPhoneNumber();
    return result;
}

JSON ClientMapper::toJson(list<shared_ptr<Client>> objs) {
    JSON result = JSON::Load("[]");
    int i=0;
    for(shared_ptr<Client> client: objs){
        result[i] = ClientMapper::toJson(client);
        i++;
    }
    return result;
}
