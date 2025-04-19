//
// Created by Angelo on 07/01/2025.
//

#include "headers/infrastructure/memory/AgentMemoryRepository.h"

using namespace std;

AgentMemoryRepository::AgentMemoryRepository() : MemoryRepository<Agent, AgentId>(){

}

optional<shared_ptr<Agent>> AgentMemoryRepository::getById(const wstring &code) {
    for(list<shared_ptr<Agent>>::iterator it = container.begin(); it != container.end(); ++it){
        shared_ptr<Agent> obj = *it;
        if(obj->hasCode(code))
            return make_optional<shared_ptr<Agent>>(obj);
    }

    return nullopt;
}