//
// Created by Angelo on 11/11/2024.
//

#include "headers/domain/model/Store.h"
#include <regex>
#include <stdexcept>


// Constructor with parameters and validation
Store::Store(const wstring &code, const string &designation, const string &address, const string &openingTime,
             const string &closingTime) : Entity(make_shared<StoreId>(code)) {
    setDesignation(designation);
    setAddress(address);
    setOpeningTime(openingTime);
    setClosingTime(closingTime);
    revenue = 0;
}

// Destructor
Store::~Store() = default;

// Getters
const wstring &Store::getCode() const { return this->id->getValue(); }
const string Store::getDesignation() const { return designation; }
const string Store::getAddress() const { return address; }
const string Store::getOpeningTime() const { return openingTime; }
const string Store::getClosingTime() const { return closingTime; }
const float Store::getRevenue() const {return revenue;}

// Setters with validation

void Store::setDesignation(const string &designation) {
    if (!isDesignationValid(designation)) {
        throw std::invalid_argument("designation is empty");
    }
    this->designation = designation;
}

void Store::setAddress(const string &address) {
    if (!isAddressValid(address)) {
        throw std::invalid_argument("address is empty");
    }
    this->address = address;
}

void Store::setOpeningTime(const string &openingTime) {
    if (!isValidTime(openingTime)) {
        throw invalid_argument("Opening time must be in the format hh:mm.");
    }
    this->openingTime = openingTime;
}

void Store::setClosingTime(const string &closingTime) {
    if (!isValidTime(closingTime)) {
        throw invalid_argument("Closing time must be in the format hh:mm.");
    }
    this->closingTime = closingTime;
}

void Store::setRevenue(float revenue) {
    if (revenue < 0){
        throw invalid_argument("revenue cannot be less than 0");
    }
    this->revenue = revenue;
}

// Helper function to validate the code format
bool Store::isValidCode(const string &code) const {
    return regex_match(code, regex("^[A-Za-z0-9]{5}$"));
}

// Helper function to validate the time format (hh:mm)
bool Store::isValidTime(const string &time) const {
    return regex_match(time, regex("^(?:[01]\\d|2[0-3]):[0-5]\\d$"));
}

bool Store::isDesignationValid(const std::string &designation) {
    return !(designation.empty());
}

bool Store::isAddressValid(const std::string &address) {
    return !(address.empty());
}



bool Store::hasCode(const wstring &code) const {
    return this->id->getValue() == code;
}

Result Store::changeDesignation(const string &newDesignation) {
    if (this->isDesignationValid(newDesignation)) {
        this->designation = newDesignation;
        return Result::OK();
    }
    return Result::NOK(L"Invalid store designation.");
}

Result Store::changeAddress(const string &newAddress) {
    if (this->isAddressValid(newAddress)) {
        this->address = newAddress;
        return Result::OK();
    }
    return Result::NOK(L"Invalid store address.");
}

Result Store::changeOpeningTime(const string &newOpeningTime) {
    if (this->isValidTime(newOpeningTime)) {
        this->openingTime = newOpeningTime;
        return Result::OK();
    }
    return Result::NOK(L"Invalid store opening time.");
}

Result Store::changeClosingTime(const string &newClosingTime) {
    if (this->isValidTime(newClosingTime)) {
        this->closingTime = newClosingTime;
        return Result::OK();
    }
    return Result::NOK(L"Invalid store closing time.");
}

