//
// Created by Tiago Cunha on 08/01/2025.
//

#include "../headers/ClientRouter.h"
#include <headers/controllers/restapi/HttpResult.h>
#include <controllers/restapi/ClientController.h>
#include <headers/domain/shared/StringUtils.h>

ClientRouter::ClientRouter() : RouterConfig("/clients") {
}

void ClientRouter::configure(httplib::Server &svr) {
    string patternBase = this->baseResource + "(\\/?)";
    string patternBaseWithId = this->baseResource + "/(\\w+)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            ClientController ctrl(extractBearerToken(req));
            try {
                result = ctrl.getAll();
            } catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        } catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Get(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            ClientController ctrl(extractBearerToken(req));
            try {
                result = ctrl.getById(StringUtils::toWString(req.matches[1]));
            } catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        } catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Post(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            ClientController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring code = StringUtils::toWString(jsonObj["code"].ToString());
                string name = jsonObj["name"].ToString();
                string tif = jsonObj["tif"].ToString();
                string email = jsonObj["email"].ToString();
                string phoneNumber = jsonObj["phoneNumber"].ToString();

                optional<string> idNumber = std::nullopt;
                if (jsonObj.hasKey("idNumber") && !jsonObj["idNumber"].ToString().empty()) {
                    idNumber = jsonObj["idNumber"].ToString();
                }
                result = ctrl.postClient(code, name, idNumber, tif, email, phoneNumber);
            } catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        } catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Put(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            ClientController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring code = StringUtils::toWString(jsonObj["code"].ToString());
                wstring nameW = StringUtils::toWString(jsonObj["name"].ToString());
                wstring idNumberW = StringUtils::toWString(jsonObj["idNumber"].ToString());
                wstring tifW = StringUtils::toWString(jsonObj["tif"].ToString());
                wstring emailW = StringUtils::toWString(jsonObj["email"].ToString());
                wstring phoneNumberW = StringUtils::toWString(jsonObj["phoneNumber"].ToString());

                // Convert wstring to string
                string name = StringUtils::toString(nameW);
                string tif = StringUtils::toString(tifW);
                string email = StringUtils::toString(emailW);
                string phoneNumber = StringUtils::toString(phoneNumberW);

                optional<string> idNumber = std::nullopt;
                if (jsonObj.hasKey("idNumber") && !jsonObj["idNumber"].ToString().empty()) {
                    idNumber = jsonObj["idNumber"].ToString();
                }

                if (StringUtils::toWString(req.matches[1]) == code)
                    result = ctrl.putClient(code, name, idNumber, tif, email, phoneNumber);
                else {
                    result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                    result.setResult("Client Code on Body does not match the one on the URL.");
                }
            } catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        } catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Delete(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            ClientController ctrl(extractBearerToken(req));
            try {
                result = ctrl.deleteClient(StringUtils::toWString(req.matches[1]));
            } catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        } catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });
}