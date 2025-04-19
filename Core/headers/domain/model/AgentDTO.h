//
// Created by Utilizador on 12/01/2025.
//

#ifndef AGENTDTO_H
#define AGENTDTO_H
#include <optional>
#include <string>

using namespace std;

class AgentDTO {
public:
    wstring code;
    string name;

    AgentDTO(const wstring &code, const string &name) : code(code), name(name) {};
};


#endif //AGENTDTO_H
