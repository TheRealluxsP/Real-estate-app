//
// Created by Angelo on 07/01/2025.
//

#ifndef DHMS_AGENTROUTER_H
#define DHMS_AGENTROUTER_H

#include "RouterConfig.h"
#include"../thirdparty/httplib.h"

using namespace std;

class AgentRouter : public RouterConfig{
public:
    AgentRouter();

    void configure(httplib::Server &svr);
};

#endif //DHMS_AGENTROUTER_H
