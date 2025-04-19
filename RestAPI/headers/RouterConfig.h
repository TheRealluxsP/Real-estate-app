// RouterConfig.h

#ifndef DHMS_ROUTERCONFIG_H
#define DHMS_ROUTERCONFIG_H

#include <stdio.h>
#include "../thirdparty/httplib.h"
#include <headers/controllers/restapi/HttpResult.h>

using namespace std;

class RouterConfig{
protected:
    string baseResource;

    std::wstring extractBearerToken(const httplib::Request &req);

    void setHttpResponse(httplib::Response &res, HttpResult &result);

public:
    RouterConfig(const string &baseResource);

    virtual void configure(httplib::Server &svr) = 0;

    // Virtual destructor with default implementation
    virtual ~RouterConfig() = default;
};

#endif //DHMS_ROUTERCONFIG_H
