//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_SERVER_H
#define DHMS_SERVER_H

#include <iostream>
#include <stdexcept>
#include "../thirdparty/httplib.h"
#include <headers/controllers/restapi/HttpResult.h>
#include <headers/controllers/restapi/StoreController.h>
#include <headers/controllers/restapi/AgentController.h>
#include <headers/domain/shared/StringUtils.h>

using namespace std;
using json::JSON;

class Server {
private:
    basic_ostream<char> *logger;
    // HTTP
    httplib::Server svr;

    // HTTPS
    //httplib::SSLServer svr;
    void log(string message);

public:
    Server();

    Server(basic_ostream<char> *logger);

    void run();

    void run(int port);

    void run(string host, int port);
};
#endif //DHMS_SERVER_H
