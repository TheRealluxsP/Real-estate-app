//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTMEMORYREPOSITORY_H
#define DHMS_AGENTMEMORYREPOSITORY_H

#include "domain/repositories/AgentRepository.h"
#include "MemoryRepository.h"
#include "../model/Agent.h"
#include "../model/AgentId.h"

class AgentMemoryRepository : public AgentRepository, public MemoryRepository<Agent, AgentId>{
private:
public:
    AgentMemoryRepository();

    virtual optional<shared_ptr<Agent>> getById(const wstring &code);
};


#endif //DHMS_AGENTMEMORYREPOSITORY_H
