//
// Created by Tiago Cunha on 08/01/2025.
//

#include "headers/domain/model/Client.h"

//Constructors


Client::Client(const wstring& code, const string& name, const optional<string> &idNumber, const string& tif, const string& email, const string& phoneNumber)
        : Entity (make_shared<ClientId>(code)){
    setName(name);
    setIdNumber(idNumber);
    setTif(tif);
    setEmail(email);
    setPhoneNumber(phoneNumber);
}

//Destructors
Client::~Client() = default;


// Getters

const wstring &Client::getCode() const { return this->id->getValue(); }
const optional<string> &Client::getIdNumber() const {return this->idNumber; }
const string &Client::getTif() const { return tif; }
const string &Client::getEmail() const { return email; }
const string &Client::getName() const { return name; }
const string& Client::getPhoneNumber() const {return phoneNumber; }

//Setters

void Client::setName(const string &name) {
    if (!isNameValid(name)) {
        throw std::invalid_argument("name is empty");
    }
    this->name = name;
}

void Client::setIdNumber(const optional<string> &idNumber){
    if(!isIdNumberValid(idNumber)){
        throw std::invalid_argument("idNumber is empty");
    }
    this->idNumber = idNumber;
}

void Client::setTif(const string &tif) {
    if (!isTifValid(tif)) {
        throw std::invalid_argument("tif is invalid");
    }
    this->tif = tif;
}

void Client::setEmail(const string &email) {
    if (!isEmailValid(email)) {
        throw std::invalid_argument("email is invalid");
    }
    this->email = email;
}
void Client::setPhoneNumber(const string& phoneNumber) {
    if (!isPhoneNumberValid(phoneNumber)) {
        throw std::invalid_argument("phoneNumber must have 9 digits");
    }
    this->phoneNumber = phoneNumber;
}

//Validation

bool Client::isValidCode(const std::string &code) const {
    return (!code.empty());
}

bool Client::hasCode(const wstring &code) const {
    return this->id->getValue() == code;
}

bool Client::isNameValid(const std::string &name) {
    return (!name.empty());
}

bool Client::isIdNumberValid(const optional<string> &idNumber){
    return (!idNumber->empty());
}

bool Client::isTifValid(const std::string &tif) {
    return (!tif.empty());
}

bool Client::isEmailValid(const std::string &email) {

    const regex emailPattern(R"(([\w.%+-]+)@([\w-]+\.)+([\w]{2,}))");
    return regex_match(email, emailPattern);
}

bool Client::isPhoneNumberValid(const std::string &phoneNumber) {

    const regex phoneNumberPattern(R"(\d{9})");
    return regex_match(phoneNumber, phoneNumberPattern);
}


Result Client::changeName(const string &newName) {
    if (this->isNameValid(newName)) {
        this->name = newName;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent name.");
}

Result Client::changeIdNumber(const optional<std::string> &idNumber) {
    if (this->isIdNumberValid(idNumber)) {
        this->idNumber = idNumber;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent ID Number.");
}

Result Client::changeTif(const string &newTif) {
    if (this->isTifValid(newTif)) {
        this->tif = newTif;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent phone number.");
}


Result Client::changeEmail(const string &newEmail) {
    if (this->isEmailValid(newEmail)) {
        this->email = newEmail;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent email address.");
}

Result Client::changePhoneNumber(const string &newPhoneNumber) {
    if (this->isPhoneNumberValid(newPhoneNumber)) {
        this->phoneNumber = newPhoneNumber;
        return Result::OK();
    }
    return Result::NOK(L"Invalid agent phone number.");
}