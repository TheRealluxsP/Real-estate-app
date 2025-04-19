//
// Created by siulo on 08/01/2025.
//

#ifndef DHMS_LISTPROPERTYCONTROLLER_H
#define DHMS_LISTPROPERTYCONTROLLER_H

#include "domain/model/AgentDTO.h"
#include "domain/model/HouseDTO.h"
#include "domain/model/PropertyDTO.h"
#include "domain/model/ResidencyDTO.h"
#include "domain/services/AdvertisementService.h"
#include "domain/services/AgentService.h"
#include "domain/services/ClientService.h"

class ListPropertyController{
private:
    shared_ptr<ClientService> clientService;
    shared_ptr<AgentService> agentService;
    shared_ptr<Client> client;
    shared_ptr<Property> property;
    string typeProperty;
    string typeBusiness;
    float price;
public:
    ListPropertyController();

    Result getClientByCode(wstring internalCode);

    list<shared_ptr<AgentDTO>> createLand(shared_ptr<PropertyDTO> dto);

    list<shared_ptr<AgentDTO>> createApartment(shared_ptr<ResidencyDTO> dto);

    list<shared_ptr<AgentDTO>> createHouse(shared_ptr<HouseDTO> dto);

    void saveAdvertisementData(const string& typeProperty, const string& typeBusiness, float price);

    Result getAgentByCode(wstring code);
};

#endif //DHMS_LISTPROPERTYCONTROLLER_H
