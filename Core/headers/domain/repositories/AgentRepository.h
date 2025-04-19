//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTREPOSITORY_H
#define DHMS_AGENTREPOSITORY_H

#include "../model/Agent.h"
#include "../model/AgentId.h"
#include "Repository.h"

class AgentRepository : virtual public Repository<Agent, AgentId>{
public:
    virtual optional<shared_ptr<Agent>> getById(const wstring &code) = 0;
};

#endif //DHMS_AGENTREPOSITORY_H
