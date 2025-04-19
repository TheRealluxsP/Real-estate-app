//
// Created by Angelo on 07/01/2025.
//

#include "headers/controllers/restapi/mappers/AgentMapper.h"
#include "thirdparty/SimpleJson.hpp"
#include <list>
#include "headers/domain/shared/StringUtils.h"

using namespace std;
using json::JSON;

JSON AgentMapper::toJson(shared_ptr<Agent> obj) {
    JSON result = JSON::Load("{}");
    result["code"] = StringUtils::toString(obj->getCode());
    result["name"] = obj->getName();
    result["idNumber"] = obj->getIdNumber().has_value() ? obj->getIdNumber().value() : "null";
    result["email"] = obj->getEmail();
    result["phoneNumber"] = obj->getPhoneNumber();


    JSON storeObject = JSON::Load("{}");

    storeObject["code"] = StringUtils::toString(obj->getStore()->getCode());
    storeObject["designation"] = (obj->getStore()->getDesignation());
    storeObject["address"] = (obj->getStore()->getAddress());
    storeObject["openingTime"] = (obj->getStore()->getOpeningTime());
    storeObject["closingTime"] = (obj->getStore()->getClosingTime());
    storeObject["revenue"] = (obj->getStore()->getRevenue());

    result ["store"] = storeObject;

    return result;

}



JSON AgentMapper::toJson(list<shared_ptr<Agent>> objs) {
    JSON result = JSON::Load("[]");
    int i=0;
    for(shared_ptr<Agent> agent: objs){
        result[i] = AgentMapper::toJson(agent);
        i++;
    }
    return result;
}

list<shared_ptr<AgentDTO>> AgentMapper::toDTO(list<shared_ptr<Agent> > agents) {
    list<shared_ptr<AgentDTO>> agentListDTO;
    for(shared_ptr<Agent> agent: agents) {
        shared_ptr<AgentDTO> agentDTO = make_shared<AgentDTO>(agent->getCode(), agent->getName());
        agentListDTO.push_back(agentDTO);
    }
    return agentListDTO;
}
