//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STOREROUTER_H
#define DHMS_STOREROUTER_H

#include "RouterConfig.h"
#include"../thirdparty/httplib.h"

using namespace std;

class StoreRouter : public RouterConfig{
public:
    StoreRouter();

    void configure(httplib::Server &svr);
};

#endif //DHMS_STOREROUTER_H
