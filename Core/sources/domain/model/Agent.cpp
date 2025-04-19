//
// Created by Angelo on 11/11/2024.
//

#include "headers/domain/model/Agent.h"

//Constructors

int Agent::code = 0;

Agent::Agent(const string &name, const optional<string> &idNumber, const string &email,const string &phoneNumber, const shared_ptr<Store> &store)
        : Entity (make_shared<AgentId>(to_wstring(++code))){
    setName(name);
    setIdNumber(idNumber);
    setEmail(email);
    setPhoneNumber(phoneNumber);
    setStore(store);
}

//Destructors
Agent::~Agent() = default;


// Getters

const wstring &Agent::getCode() const { return this->id->getValue(); }
const optional<string> &Agent::getIdNumber() const {return this->idNumber; }
const string &Agent::getEmail() const { return email; }
const string &Agent::getName() const { return name; }
const string& Agent::getPhoneNumber() const {return phoneNumber; }
const shared_ptr<Store> &Agent::getStore() const {return store; }

//Setters

void Agent::setName(const string &name) {
    if (!isNameValid(name)) {
        throw std::invalid_argument("name is empty");
    }
    this->name = name;
}

void Agent::setIdNumber(const optional<string> &idNumber){
    if(!isIdNumberValid(idNumber)){
        throw std::invalid_argument("idNumber is empty");
    }
    this->idNumber = idNumber;
}

void Agent::setEmail(const string &email) {
    if (!isEmailValid(email)) {
        throw std::invalid_argument("email is invalid");
    }
    this->email = email;
}
void Agent::setPhoneNumber(const string& phoneNumber) {
    if (!isPhoneNumberValid(phoneNumber)) {
        throw std::invalid_argument("phoneNumber must have 9 digits");
    }
    this->phoneNumber = phoneNumber;
}
void Agent::setStore(const shared_ptr<Store> &store) {
    if (store == nullptr) {
        throw std::invalid_argument("store is not valid");
    }
    this->store = store;
}

//Validation

bool Agent::isValidCode(const std::string &code) const {
    return (!code.empty());
}

bool Agent::hasCode(const wstring &code) const {
    return this->id->getValue() == code;
}

bool Agent::isNameValid(const std::string &name) {
    return (!name.empty());
}

bool Agent::isIdNumberValid(const optional<string> &idNumber){
    return (!idNumber->empty());
}

bool Agent::isEmailValid(const std::string &email) {

    const regex emailPattern(R"(([\w.%+-]+)@([\w-]+\.)+([\w]{2,}))");
    return regex_match(email, emailPattern);
}

bool Agent::isPhoneNumberValid(const std::string &phoneNumber) {

    const regex phoneNumberPattern(R"(\d{9})");
    return regex_match(phoneNumber, phoneNumberPattern);
}


Result Agent::changeName(const string &newName) {
    if (this->isNameValid(newName)) {
        this->name = newName;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent name.");
}

Result Agent::changeIdNumber(const optional<std::string> &idNumber) {
    if (this->isIdNumberValid(idNumber)) {
        this->idNumber = idNumber;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent ID Number.");
}


Result Agent::changeEmail(const string &newEmail) {
    if (this->isEmailValid(newEmail)) {
        this->email = newEmail;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent email address.");
}

Result Agent::changePhoneNumber(const string &newPhoneNumber) {
    if (this->isPhoneNumberValid(newPhoneNumber)) {
        this->phoneNumber = newPhoneNumber;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent phone number.");
}

Result Agent::changeStore(const shared_ptr<Store> newStore) {
    if (newStore != nullptr) {
        this->store = newStore;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent store id.");
}



