//
// Created by Rui Pedro Monteiro on 07/01/2025.
//

#include "../headers/AdvertisementRouter.h"

#include "domain/model/House.h"
#include "domain/model/Residency.h"
#include "headers/controllers/restapi/AdvertisementController.h"
#include "headers/domain/shared/StringUtils.h"
#include "headers/domain/services/AdvertisementService.h"
#include "headers/infrastructure/memory/AdvertisementMemoryRepository.h"

// Constructor
AdvertisementRouter::AdvertisementRouter() : RouterConfig("/advertisements") {
}

// Configure method
void AdvertisementRouter::configure(httplib::Server &svr) {
    string patternBase = this->baseResource + "(\\/?)";
    string patternBaseWithId = this->baseResource + "/([\\w\\-]+)";

    // GET /advertisements
    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            AdvertisementController ctrl( extractBearerToken(req));
            try {
                result = ctrl.getAll();
            } catch (exception &e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        } catch (invalid_argument &e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    // GET /advertisements/{id}
    svr.Get(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            AdvertisementController ctrl( extractBearerToken(req));
            try {
                result = ctrl.getById(StringUtils::toWString(req.matches[1]));
            } catch (exception &e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        } catch (invalid_argument &e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    // POST /advertisements
    svr.Post(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            AdvertisementController ctrl( extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                string typeProperty = jsonObj["typeProperty"].ToString();
                string typeBusiness = jsonObj["typeBusiness"].ToString();
                float price = jsonObj["price"].ToFloat();
                wstring agentCode;
                shared_ptr<Agent> agent;
                if(jsonObj.hasKey("agentCode") && !jsonObj["agentCode"].ToString().empty()){
                    agentCode = StringUtils::toWString(jsonObj["agentCode"].ToString());
                    shared_ptr<AgentService> agentService = Company::GetInstance()->getAgentService();
                    optional<shared_ptr<Agent>> agentOpt = agentService->getByCode(agentCode);
                    if(agentOpt) {
                        agent = agentOpt.value();
                    }
                }
                wstring clientCode;
                shared_ptr<Client> client;
                if(jsonObj.hasKey("clientId") && !jsonObj["clientId"].ToString().empty()){
                    clientCode = StringUtils::toWString(jsonObj["clientId"].ToString());
                    shared_ptr<ClientService> clientService = Company::GetInstance()->getClientService();
                    optional<shared_ptr<Client>> clientOpt = clientService->getByCode(clientCode);
                    if(clientOpt) {
                        client = clientOpt.value();
                    }
                }
                shared_ptr<Property> property = make_shared<Property>();

                if(jsonObj.hasKey("property")){

                    auto propertyJson = jsonObj["property"];
                    wstring location = StringUtils::toWString(propertyJson["location"].ToString());
                    double area = static_cast<double>(propertyJson["area"].ToFloat());
                    wstring distanceCenter=StringUtils::toWString(propertyJson["distanceCenter"].ToString());
                    wstring photograph=StringUtils::toWString(propertyJson["photograph"].ToString());

                    shared_ptr<Property> prop = make_shared<Property>(area, location, distanceCenter, photograph);
                    property = prop;

                    if(typeProperty == "House" || typeProperty == "Apartment") {
                        int numBedrooms=(propertyJson["numberBedrooms"].ToInt());
                        int numBathrooms=(propertyJson["numberBathrooms"].ToInt());
                        int parkingSpaces=(propertyJson["parkingSpaces"].ToInt());
                        wstring availableEquipment=(StringUtils::toWString(propertyJson["availableEquipment"].ToString()));

                        shared_ptr<Residency> res = make_shared<Residency>(area, location, distanceCenter, photograph, numBedrooms, numBathrooms, parkingSpaces, availableEquipment);
                        property = res;

                        if(typeProperty == "House") {
                            bool existenceBasement=(propertyJson["existenceBasement"].ToBool());
                            bool habittableAttic=(propertyJson["habittableAttic"].ToBool());
                            bool sunExposure=(propertyJson["sunExposure"].ToBool());


                            shared_ptr<House> house = make_shared<House>(area, location, distanceCenter, photograph, numBedrooms, numBathrooms, parkingSpaces, availableEquipment, existenceBasement, habittableAttic, sunExposure);
                            property = house;

                        }
                    }
                }
                result = ctrl.postAdvertisement( typeProperty, typeBusiness, price, property, client, agent);
            } catch (exception &e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        } catch (invalid_argument &e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });
/*

    // PUT /advertisements/{id}
    svr.Put(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            AdvertisementController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring id = StringUtils::toWString(req.matches[1]);
                string typeProperty = jsonObj["typeProperty"].ToString();
                string typeBusiness = jsonObj["typeBusiness"].ToString();

                // Usando ToFloat diretamente para evitar a conversão com stringstream
                float price = jsonObj["price"].ToFloat();
                if (price == 0.0f) { // Verifica se o preço é inválido (se for zero)
                    throw std::invalid_argument("Preço inválido");
                }

                bool isSold = jsonObj["isSold"].ToBool();
                bool visibility = jsonObj["visibility"].ToBool();

                result = ctrl.putAdvertisement(id, typeProperty, typeBusiness, price, isSold, visibility);
            } catch (exception &e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        } catch (invalid_argument &e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });
*/

// DELETE /advertisements/{id}
    svr.Delete(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            AdvertisementController ctrl(extractBearerToken(req));
            try {
                result = ctrl.deleteAdvertisement(StringUtils::toWString(req.matches[1]));
            } catch (exception &e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        } catch (invalid_argument &e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);

    });

}

