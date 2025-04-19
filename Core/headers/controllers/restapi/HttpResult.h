//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_HTTPRESULT_H
#define DHMS_HTTPRESULT_H

#include "HttpStatus.h"
#include "thirdparty/SimpleJson.hpp"
#include <string>

using namespace std;
using json::JSON;

class HttpResult {
private:
    HttpStatus status;
    JSON result;

public:
    HttpResult();

    HttpResult(HttpStatus status);

    HttpResult(HttpStatus status, const wstring &message);

    HttpResult(HttpStatus status, const string &message);

    HttpResult(HttpStatus status, const char *message);

    HttpResult(HttpStatus status, const JSON &result);

    HttpStatus getHttpStatus();

    JSON getResult();

    void setHttpStatus(HttpStatus status);

    void setResult(const wstring &message);

    void setResult(const string &message);

    void setResult(const char *message);

    void setResult(const JSON &result);
};

#endif //DHMS_HTTPRESULT_H
