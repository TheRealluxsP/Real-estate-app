//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_SERVERSTATUSROUTER_H
#define DHMS_SERVERSTATUSROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class ServerStatusRouter : public RouterConfig{
private:
    httplib::Server *server = nullptr;
public:
    ServerStatusRouter();

    void configure(httplib::Server &svr);
};

#endif //DHMS_SERVERSTATUSROUTER_H
