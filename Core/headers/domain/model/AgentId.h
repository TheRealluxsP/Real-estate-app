//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTID_H
#define DHMS_AGENTID_H

#include "EntityId.h"
#include <regex>

class AgentId : public EntityId{
public:
    bool isValueValid(const wstring &value) override{
        return true;
    }
    AgentId(const wstring &value) : EntityId(value){
        this->setValue(value);
    }
};

#endif //DHMS_AGENTID_H
