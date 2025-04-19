//
// Created by siulo on 03/01/2025.
//

#include "../headers/StoreRouter.h"
#include <headers/controllers/restapi/HttpResult.h>
#include <controllers/restapi/StoreController.h>
#include <headers/domain/shared/StringUtils.h>

StoreRouter::StoreRouter() : RouterConfig("/stores") {
}

void StoreRouter::configure(httplib::Server &svr) {
    string patternBase = this->baseResource + "(\\/?)";
    string patternBaseWithId = this->baseResource + "/(\\w+)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res){
        HttpResult result;
        try{
            StoreController ctrl(extractBearerToken(req));
            try{
                result = ctrl.getAll();
            }
            catch (exception e){
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e){
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Get(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res){
        HttpResult result;
        try{
            StoreController ctrl(extractBearerToken(req));
            try{
                result = ctrl.getById(StringUtils::toWString(req.matches[1]));
            }
            catch (exception e){
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e){
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Post(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            StoreController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring code = StringUtils::toWString(jsonObj["code"].ToString());
                string designation = jsonObj["designation"].ToString();
                string address = jsonObj["address"].ToString();
                string openingTime = jsonObj["openingTime"].ToString();
                string closingTime = jsonObj["closingTime"].ToString();
                result = ctrl.postStore(code, designation, address, openingTime, closingTime);
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Put(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            StoreController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring code = StringUtils::toWString(jsonObj["code"].ToString());
                wstring designationW = StringUtils::toWString(jsonObj["designation"].ToString());
                wstring addressW = StringUtils::toWString(jsonObj["address"].ToString());
                wstring openingTimeW = StringUtils::toWString(jsonObj["openingTime"].ToString());
                wstring closingTimeW = StringUtils::toWString(jsonObj["closingTime"].ToString());

                // Convert wstring to string
                string designation = StringUtils::toString(designationW);
                string address = StringUtils::toString(addressW);
                string openingTime = StringUtils::toString(openingTimeW);
                string closingTime = StringUtils::toString(closingTimeW);

                if (StringUtils::toWString(req.matches[1]) == code)
                    result = ctrl.putStore(code, designation, address, openingTime, closingTime);
                else {
                    result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                    result.setResult("Store Code on Body does not match the one on the URL.");
                }
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Delete(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            StoreController ctrl(extractBearerToken(req));
            try {
                result = ctrl.deleteStore(StringUtils::toWString(req.matches[1]));
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });
}