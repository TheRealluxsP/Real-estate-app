//
// Created by Tiago Cunha on 08/01/2025.
//

#ifndef DHMS_CLIENTROUTER_H
#define DHMS_CLIENTROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

using namespace std;

class ClientRouter : public RouterConfig {
public:
    ClientRouter();

    void configure(httplib::Server &svr);
};

#endif //DHMS_CLIENTROUTER_H
