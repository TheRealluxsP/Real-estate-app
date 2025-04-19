//
// Created by Angelo on 07/01/2025.
//

#include "../headers/AgentRouter.h"
#include <headers/controllers/restapi/HttpResult.h>
#include <controllers/restapi/AgentController.h>
#include <headers/domain/shared/StringUtils.h>
#include "../headers/controllers/Company.h"

AgentRouter::AgentRouter() : RouterConfig("/agents") {
}

void AgentRouter::configure(httplib::Server &svr) {
    string patternBase = this->baseResource + "(\\/?)";
    string patternBaseWithId = this->baseResource + "/(\\w+)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res){
        HttpResult result;
        try{
            AgentController ctrl(extractBearerToken(req));
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
            AgentController ctrl(extractBearerToken(req));
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
            AgentController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                string name = jsonObj["name"].ToString();
                string email = jsonObj["email"].ToString();
                string phoneNumber = jsonObj["phoneNumber"].ToString();
                shared_ptr<Store> store;
                wstring storeCode;

                if (jsonObj.hasKey("storeCode") && !jsonObj["storeCode"].ToString().empty()) {
                    storeCode = StringUtils::toWString(jsonObj["storeCode"].ToString());
                    shared_ptr<StoreService> storeService = Company::GetInstance()->getStoreService();
                    store = storeService->getByCode(storeCode).value();
                }

                optional<string> idNumber = std::nullopt;
                if (jsonObj.hasKey("idNumber") && !jsonObj["idNumber"].ToString().empty()) {
                    idNumber = jsonObj["idNumber"].ToString();
                }
                result = ctrl.postAgent(name, idNumber, email, phoneNumber, store);
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
            // Extract the agentCode from the URL
            std::wstring agentCode = StringUtils::toWString(req.matches[1]);

            AgentController ctrl(extractBearerToken(req));

            try {
                // Parse the JSON body
                auto jsonObj = JSON::Load(req.body);
                string name = jsonObj["name"].ToString();
                string email = jsonObj["email"].ToString();
                string phoneNumber = jsonObj["phoneNumber"].ToString();

                shared_ptr<Store> store = nullptr;
                if (jsonObj.hasKey("storeCode") && !jsonObj["storeCode"].ToString().empty()) {
                    // Fetch the store by its code
                    wstring storeCode = StringUtils::toWString(jsonObj["storeCode"].ToString());
                    auto storeOpt = Company::GetInstance()->getStoreService()->getByCode(storeCode);

                    if (!storeOpt) {
                        result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                        result.setResult("Invalid storeCode: Store not found.");
                        setHttpResponse(res, result);
                        return;
                    }

                    store = storeOpt.value();
                }

                // Optional ID number
                optional<string> idNumber = std::nullopt;
                if (jsonObj.hasKey("idNumber") && !jsonObj["idNumber"].ToString().empty()) {
                    idNumber = jsonObj["idNumber"].ToString();
                }

                // Update the agent based on the agentCode from the URL
                result = ctrl.putAgent(agentCode, name, idNumber, email, phoneNumber, store);

            } catch (const std::exception &e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }

        } catch (const std::invalid_argument &e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
            result.setResult(std::string("Authorization error: ") + e.what());
        }

        // Set the response
        setHttpResponse(res, result);
    });

    svr.Delete(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            AgentController ctrl(extractBearerToken(req));
            try {
                result = ctrl.deleteAgent(StringUtils::toWString(req.matches[1]));
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
