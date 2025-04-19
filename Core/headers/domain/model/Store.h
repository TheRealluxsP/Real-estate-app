//
// Created by Angelo on 11/11/2024.
//

#ifndef DHMS_STORE_H
#define DHMS_STORE_H

#include <string>
#include <stdexcept>
#include <list>
#include <memory>
#include "StoreId.h"
#include "Entity.h"
#include "Result.h"

using namespace std;

class Store : public Entity<StoreId> {
private:
    string designation;
    string address;
    string openingTime;
    string closingTime;
    float revenue;
public:
    // Constructor and Destructor
    Store(const wstring& code, const string& designation, const string& address, const string& openingTime, const string& closingTime);
    virtual ~Store();

    // Getters
    const wstring &getCode() const;
    const string getDesignation() const;
    const string getAddress() const;
    const string getOpeningTime() const;
    const string getClosingTime() const;
    const float getRevenue() const;

    // Setters
    void setDesignation(const string &designation);
    void setAddress(const string &address);
    void setOpeningTime(const string &openingTime);
    void setClosingTime(const string &closingTime);
    void setRevenue(float revenue);

    // Helper functions for validation
    bool isValidCode(const string &code) const;
    bool isValidTime(const string &time) const;
    bool hasCode(const wstring &code) const;
    bool isDesignationValid(const string &designation);
    bool isAddressValid(const string &address);

    //Helper functions for put request
    Result changeDesignation(const string &newDesignation);
    Result changeAddress(const string &newAddress);
    Result changeOpeningTime(const string& newOpeningTime);
    Result changeClosingTime(const string& newClosingTime);
};

#endif // DHMS_STORE_H