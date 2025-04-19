//
// Created by siulo on 02/01/2025.
//

#include "headers/controllers/restapi/HttpResult.h"
#include "headers/controllers/restapi/HttpStatus.h"
#include "thirdparty/SimpleJson.hpp"
#include <string>
#include "headers/domain/shared/StringUtils.h"

using namespace std;
using json::JSON;

HttpResult::HttpResult() {
    this->status = HTTP_OK;
    this->result = JSON::Load("{}");
}

HttpResult::HttpResult(HttpStatus status) {
    this->status = status;
    this->result = JSON::Load("{}");
}

HttpResult::HttpResult(HttpStatus status, const wstring &message) {
    this->status = status;
    this->result["message"] = StringUtils::toString(message);
}

HttpResult::HttpResult(HttpStatus status, const string &message) {
    this->status = status;
    this->result["message"] = message;
}

HttpResult::HttpResult(HttpStatus status, const char *message) {
    std::string str = "";
    str.append(message);
    this->status = status;
    this->result["message"] = str;
}

HttpResult::HttpResult(HttpStatus status, const JSON &result) {
    this->status = status;
    this->result = result;
}

HttpStatus HttpResult::getHttpStatus() {
    return this->status;
}

JSON HttpResult::getResult() {
    return this->result;
}

void HttpResult::setHttpStatus(HttpStatus status) {
    this->status = status;
}

void HttpResult::setResult(const wstring &message) {
    this->result = JSON();
    this->result["message"] = StringUtils::toString(message);
}

void HttpResult::setResult(const string &message) {
    this->result = JSON();
    this->result["message"] = message;
}

void HttpResult::setResult(const char *message) {
    std::string str = "";
    str.append(message);
    this->setResult(str);
}

void HttpResult::setResult(const JSON &result) {
    this->result = result;
}