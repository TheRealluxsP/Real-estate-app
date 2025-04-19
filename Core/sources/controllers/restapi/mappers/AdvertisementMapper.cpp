//
// Created by Rui Pedro Monteiro on 07/01/2025.
//
#include "headers/controllers/restapi/mappers/AdvertisementMapper.h"
#include "thirdparty/SimpleJson.hpp"
#include <list>
#include <memory>
#include <stdexcept>

#include "controllers/restapi/mappers/PropertyMapper.h"
#include "controllers/restapi/mappers/StoreMapper.h"
#include "headers/domain/shared/StringUtils.h"
#include "domain/model/Residency.h"
#include "domain/model/House.h"

using namespace std;
using json::JSON;

JSON AdvertisementMapper::toJson(shared_ptr<Advertisement> advertisement) {
    JSON result = JSON::Load("{}"); //object JSON
    result["code"] = StringUtils::toString(advertisement->getCode());
    result["typeProperty"] = advertisement->getTypeProperty();
    result["typeBusiness"] = advertisement->getTypeBusiness();
    result["price"] = advertisement->getPrice();
    result["isSold"] = advertisement->isAdvertisementSold();
    result["visibility"] = advertisement->isAdvertisementVisible();
    result["commission"] = advertisement->getCommission();
    result["isPercentageValue"] = advertisement->getIsPercentageValue();

    JSON propObject = JSON::Load("{}");

    propObject["id"] = StringUtils::toString(advertisement->getProperty()->getCode());
    propObject["area"] = advertisement->getProperty()->getArea();
    propObject["location"] = StringUtils::toString(advertisement->getProperty()->getLocation());
    propObject["distanceCenter"] = StringUtils::toString(advertisement->getProperty()->getDistanceCenter());
    propObject["photograph"] = StringUtils::toString(advertisement->getProperty()->getPhotograph());

    if(advertisement->getTypeProperty() == "House" || advertisement->getTypeProperty() == "Apartment"){

        std::shared_ptr<Property> prop = advertisement->getProperty();
        Residency* res = static_cast<Residency*>(prop.get());

        propObject["numberBathrooms"] = res->getNumberBathrooms();
        propObject["numberBedrooms"] = res->getNumberBedrooms();
        propObject["parkingSpaces"] = res->getParkingSpaces();
        propObject["availableEquipment"] = StringUtils::toString(res->getAvailableEquipment());

        if(advertisement->getTypeProperty() == "House"){
            House* house = static_cast<House*>(res);
            propObject["Basement"] = house->getExistenceBasement();
            propObject["HabittableAttic"] = house->getHabittableAttic();
            propObject["SunExposure"] = house->getExistenceBasement();
        }
    }

    result["property"] = propObject;

    JSON agentObject = JSON::Load("{}");
    agentObject["code"] = StringUtils::toString(advertisement->getAgent()->getCode());
    agentObject["name"] = advertisement->getAgent()->getName();
    agentObject["email"] = advertisement->getAgent()->getEmail();
    agentObject["phoneNumber"] = advertisement->getAgent()->getPhoneNumber();


    JSON storeObject = JSON::Load("{}");
    storeObject["code"] = StringUtils::toString(advertisement->getAgent()->getStore()->getCode());
    storeObject["designation"] = (advertisement->getAgent()->getStore()->getDesignation());
    storeObject["address"] = (advertisement->getAgent()->getStore()->getAddress());
    storeObject["openingTime"] = (advertisement->getAgent()->getStore()->getOpeningTime());
    storeObject["closingTime"] = (advertisement->getAgent()->getStore()->getClosingTime());
    storeObject["revenue"] = (advertisement->getAgent()->getStore()->getRevenue());
    
    agentObject["store"] = storeObject;

    result["agent"] = agentObject;

    JSON clientObject = JSON::Load("{}");
    clientObject["id"] = StringUtils::toString(advertisement->getClient()->getCode());
    clientObject["name"] = advertisement->getClient()->getName();
    clientObject["tif"] = advertisement->getClient()->getTif();
    clientObject["email"] = advertisement->getClient()->getEmail();
    clientObject["phoneNumber"] = advertisement->getClient()->getPhoneNumber();

    result["client"] = clientObject;

    return result;
}

JSON AdvertisementMapper::toJson(list<shared_ptr<Advertisement>> advertisements) {
    JSON result = JSON::Load("[]"); //array JSON
    int i = 0;
    for (shared_ptr<Advertisement> adv : advertisements) {
        result[i] = AdvertisementMapper::toJson(adv);
        i++;
    }
    return result;
}

shared_ptr<Advertisement> AdvertisementMapper::toEntity(const JSON& json) {
    if (!json.hasKey("typeProperty") || !json.hasKey("typeBusiness") || !json.hasKey("price")) {
        throw invalid_argument("Invalid JSON object: missing required keys");
    }


    auto advertisement = make_shared<Advertisement>();
    advertisement->setTypeProperty(json.at("typeProperty").ToString());
    advertisement->setTypeBusiness(json.at("typeBusiness").ToString());
    advertisement->setPrice(json.at("price").ToFloat());
    advertisement->setSoldStatus(json.at("isSold").ToBool());
    advertisement->setVisibility(json.at("visibility").ToBool());
    advertisement->setCommission(json.at("commission").ToFloat());
    return advertisement;
}

list<shared_ptr<AdvertisementDTO> > AdvertisementMapper::toDTO(list<shared_ptr<Advertisement> > advs) {
    list<shared_ptr<AdvertisementDTO>> soldAdvListDTO;

    for (shared_ptr<Advertisement> adv : advs) {
        shared_ptr<Store> store = adv->getStoreByAgent();
        shared_ptr<StoreDTO> storeDto = StoreMapper::toDTO(store);
        shared_ptr<Property> property = adv->getProperty();
        shared_ptr<PropertyDTO> propertyDto = PropertyMapper::toDTO(property);
        shared_ptr<AdvertisementDTO> advDTO = make_shared<AdvertisementDTO>(adv->getTypeProperty(), adv->getTypeBusiness(), adv->getPrice(), propertyDto, storeDto, adv->getCommission(), adv->getIsPercentageValue());
        soldAdvListDTO.push_back(advDTO);
    }

    return soldAdvListDTO;
}

