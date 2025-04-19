//
// Created by siulo on 09/01/2025.
//

#include "controllers/ListPropertyController.h"

#include <iostream>

#include "controllers/Company.h"
#include "domain/model/House.h"
#include "domain/model/Residency.h"

ListPropertyController::ListPropertyController() = default;

Result ListPropertyController::getClientByCode(std::wstring internalCode) {

    this->clientService = Company::GetInstance()->getClientService();

    optional<shared_ptr<Client>> client = this->clientService->getByCode(internalCode);

    if(client.has_value()) {
        this->client = client.value();
        return Result::OK(L"Client retrieved");
    }

    return Result::NOK(L"Could not find client with code " + internalCode);
}

list<shared_ptr<AgentDTO>> ListPropertyController::createLand(shared_ptr<PropertyDTO> dto) {
    this->property = Property::createProp(dto);

    this->agentService = Company::GetInstance()->getAgentService();
    return agentService->getAllDTO();
}

list<shared_ptr<AgentDTO>> ListPropertyController::createApartment(shared_ptr<ResidencyDTO> dto) {
    this->property = Residency::createRes(dto);

    this->agentService = Company::GetInstance()->getAgentService();
    return agentService->getAllDTO();
}

list<shared_ptr<AgentDTO>> ListPropertyController::createHouse(shared_ptr<HouseDTO> dto) {
    this->property = House::createHouse(dto);

    this->agentService = Company::GetInstance()->getAgentService();
    return agentService->getAllDTO();
}



void ListPropertyController::saveAdvertisementData(const string &typeProperty, const string &typeBusiness, float price) {
    this->typeProperty = typeProperty;
    this->typeBusiness = typeBusiness;
    this->price = price;
}


Result ListPropertyController::getAgentByCode(wstring code) {
    optional<shared_ptr<Agent>> agentOpt = agentService->getByCode(code);
    shared_ptr<Agent> agent;
    if(agentOpt) {
        agent = agentOpt.value();
    }
    shared_ptr<AdvertisementService> advService = Company::GetInstance()->getAdvertisementService();
    shared_ptr<Advertisement> adv = advService->create(typeProperty, typeBusiness, price, property, client, agent);
    return advService->addOrUpdate(adv);
}

