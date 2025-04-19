//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTMAPPER_H
#define DHMS_AGENTMAPPER_H

#include "thirdparty/SimpleJson.hpp"
#include "../../../domain/model/Agent.h"
#include <string>
#include <list>

#include "domain/model/AgentDTO.h"

using namespace std;
using json::JSON;

class AgentMapper{
public:

    static list<shared_ptr<AgentDTO>> toDTO(list<shared_ptr<Agent>> agents);

    static JSON toJson(shared_ptr<Agent> obj);

    static JSON toJson(list<shared_ptr<Agent>> objs);
};

#endif //DHMS_AGENTMAPPER_H
