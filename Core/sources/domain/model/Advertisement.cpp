//
// Created by Utilizador on 04/01/2025.
//
#include "headers/domain/model/Advertisement.h"
#include "domain/services/AgentService.h"
#include "controllers/Company.h"
#include <stdexcept>


int Advertisement::code = 0;
int Advertisement::assignedAgent = 0;

// Constructor with full parameters including code, type, price, etc.
Advertisement::Advertisement(const string &typeProperty, const string &typeBusiness,
                             float price, const shared_ptr<Property>& property, const shared_ptr<Client>& client,
                              shared_ptr<Agent>& agent)
        : Entity(make_shared<AdvertisementId>(to_wstring(++code))) // Initialize base class with code
         {setTypeProperty(typeProperty); setTypeBusiness(typeBusiness); setPrice(price);
                     setProperty(property); setClient(client); setAgent(agent); setSoldStatus(false); setVisibility(false); setCommission(0);
         }

// Default constructor initializes empty advertisement
Advertisement::Advertisement()
        : Entity<AdvertisementId>(std::make_shared<AdvertisementId>(L"")),  // Initialize with empty code
          typeProperty(""), typeBusiness(""), price(0.0f), isSold(false),
          visibility(false), commission(0) {}

// Destructor
Advertisement::~Advertisement() {}

// Getter methods to retrieve the advertisement's properties
const wstring& Advertisement::getCode() const {
    return this->id->getValue();
}

const string& Advertisement::getTypeProperty() const {
    return this->typeProperty;
}

const string& Advertisement::getTypeBusiness() const {
    return this->typeBusiness;
}

float Advertisement::getPrice() const {
    return this->price;
}

const shared_ptr<Property>& Advertisement::getProperty() const {
    return this->property;
}

const shared_ptr<Client>& Advertisement::getClient() const {
    return this->client;
}

const shared_ptr<Agent>& Advertisement::getAgent() const {
    return this->agent;
}

const shared_ptr<Store> &Advertisement::getStoreByAgent() const {
    return this->agent->getStore();
}


bool Advertisement::isAdvertisementSold() const {
    return this->isSold;
}

bool Advertisement::isAdvertisementVisible() const {
    return this->visibility;
}

float Advertisement::getCommission() const {
    return this->commission;
}

bool Advertisement::getIsPercentageValue() const {
    return this->isPercentageValue;
}

bool Advertisement::hasCode(const wstring &code) const {
    return this->id->getValue() == code;
}

// Setter methods to set properties
void Advertisement::setTypeProperty(const string& typeProperty) {
    if (typeProperty != "House" && typeProperty != "Apartment" && typeProperty != "Land") {
        throw std::invalid_argument("typeProperty must be either House, Apartment or Land");
    }
    this->typeProperty = typeProperty;
}

void Advertisement::setTypeBusiness(const string& typeBusiness) {
    if(typeBusiness != "Sale" && typeBusiness != "Rent") {
        throw std::invalid_argument("typeBusiness must be either Sale or Rent");
    }
    this->typeBusiness = typeBusiness;
}

void Advertisement::setPrice(float price) {
    if (price < 0.0) {
        throw std::invalid_argument("price must be positive");
    }
    this->price = price;
}

void Advertisement::setSoldStatus(bool isSold) {
    this->isSold = isSold;
}

void Advertisement::setVisibility(bool visibility) {
    this->visibility = visibility;
}

void Advertisement::setCommission(float commission) {
    this->commission = commission;
}

void Advertisement::setId(const wstring& id) {
    this->id = std::make_shared<AdvertisementId>(id);
}

void Advertisement::setIsPercentageValue(bool isPercentageValue) {
    this->isPercentageValue = isPercentageValue;
}

void Advertisement::setClient(const shared_ptr<Client> &client) {
    if(client == nullptr){
        throw invalid_argument("That client is not registered in the application's data");
    }
    this->client = client;
}

void Advertisement::setAgent(shared_ptr<Agent> &agent) {
    if(agent == nullptr){
        shared_ptr<AgentService> service = Company::GetInstance()->getAgentService();

        optional<shared_ptr<Agent>> fetchedAgent = service->getByCode(to_wstring(++assignedAgent));
        if(fetchedAgent){
            agent = fetchedAgent.value();
        }
        if(agent == nullptr){
            assignedAgent = 0;
            optional<shared_ptr<Agent>> fetchedAgent2 = service->getByCode(to_wstring(++assignedAgent));
            if(fetchedAgent2){
                agent = fetchedAgent2.value();
            }

        }
    }

    if(agent == nullptr){
        assignedAgent = 0;
        throw invalid_argument("There needs to be at least one agent to manage this advertisement, the one you entered doesnt exist so the system tried assigning one automatically but couldn't find any");
    }

    this->agent = agent;
}

void Advertisement::setProperty(const shared_ptr<Property> &property) {
    if(property == nullptr){
        throw invalid_argument("Please create a valid property");
    }
    this->property = property;
}

// Change methods to update properties of the advertisement
Result Advertisement::changePrice(float newPrice) {
    if (newPrice >= 0.0) {
        this->price = newPrice;
        return Result::OK();
    }
    return Result::NOK(L"Invalid price.");
}

Result Advertisement::changeCommission(float newCommission) {
    if (newCommission >= 0.0 && newCommission <= 100.0) {
        this->commission = newCommission;
        return Result::OK();
    }
    return Result::NOK(L"Invalid commission.");
}

Result Advertisement::changeProperty(const shared_ptr<Property>& newProperty) {
    if (newProperty) {
        this->property = newProperty;
        return Result::OK();
    }
    return Result::NOK(L"Invalid property.");
}

Result Advertisement::changeClient(const shared_ptr<Client>& newClient) {
    if (newClient) {
        this->client = newClient;
        return Result::OK();
    }
    return Result::NOK(L"Invalid client.");
}

Result Advertisement::changeAgent(const shared_ptr<Agent>& newAgent) {
    if (newAgent) {
        this->agent = newAgent;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent.");
}

Result Advertisement::changeSoldStatus(bool newStatus) {
    this->isSold = newStatus;
    return Result::OK();
}

Result Advertisement::changeVisibility(bool newVisibility) {
    this->visibility = newVisibility;
    return Result::OK();
}