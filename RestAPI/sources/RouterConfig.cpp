//
// Created by siulo on 03/01/2025.
//

#include "../headers/RouterConfig.h"
#include <headers/domain/shared/StringUtils.h>


RouterConfig::RouterConfig(const string &baseResource){
    this->baseResource = baseResource;
}

void RouterConfig::setHttpResponse(httplib::Response &res, HttpResult &result) {
    res.status = result.getHttpStatus();
    res.set_content(result.getResult().dump(), "application/json");
}

std::wstring RouterConfig::extractBearerToken(const httplib::Request &req) {
    string token = req.get_header_value("Authorization");
    return StringUtils::toWString(token);
}