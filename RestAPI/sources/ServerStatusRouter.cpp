//
// Created by siulo on 03/01/2025.
//

#include "../headers/ServerStatusRouter.h"
#include <headers/controllers/restapi/HttpResult.h>
#include <headers/domain/shared/StringUtils.h>

ServerStatusRouter::ServerStatusRouter() : RouterConfig("/status") {
}

void ServerStatusRouter::configure(httplib::Server &svr) {
    this->server = &svr;

    string patternBase = this->baseResource + "(\\/?)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res){
        HttpResult result(HttpStatus::HTTP_OK_EMPTY);
        setHttpResponse(res, result);
    });

    string patternBaseStop = this->baseResource + "/stop";
    svr.Post(patternBaseStop, [&](const httplib::Request &req, httplib::Response &res) {
        std::wstring msg = L"Shutting down the server.";
        HttpResult result(HttpStatus::HTTP_OK, msg);
        setHttpResponse(res, result);
        this->server->stop();
    });

    svr.set_error_handler([&](const auto &req, auto &res) {
        if (res.status != HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND)
            return;
        if (res.status == HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH) {
            HttpResult result(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH, "Bearer Token Authorization is required.");
            setHttpResponse(res, result);
            return;
        }
        // Otherwise
        std::string msg = "Resource not found: " + req.method + "//" + req.path;
        HttpResult result(HttpStatus::HTTP_CLIENT_ERROR_NOT_FOUND, msg);
        setHttpResponse(res, result);
    });

    svr.set_exception_handler([&](const auto &req, auto &res, std::exception &e) {
        std::wstring msg = L"An error occurred on server.";
        HttpResult result(HttpStatus::HTTP_SERVER_ERROR, msg);
        setHttpResponse(res, result);
    });
}