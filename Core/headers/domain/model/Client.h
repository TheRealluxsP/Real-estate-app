//
// Created by Tiago Cunha on 08/01/2025.
//

#ifndef DHMS_CLIENT_H
#define DHMS_CLIENT_H

#include <string>
#include <memory>
#include <optional>
#include "Entity.h"
#include "Result.h"
#include "ClientId.h"

using namespace std;

class Client : public Entity<ClientId>{
private:
    string name;
    optional<string> idNumber;
    string tif;
    string email;
    string phoneNumber;

public:
    //Constructor
    Client();
    Client(const wstring& code, const string& name, const optional<string> &idNumber, const string& tif, const string& email, const string& phoneNumber);

    //Destructor
    virtual ~Client();

    //Getters
    const wstring &getCode() const;
    const string &getName() const;
    const optional<string>& getIdNumber() const;
    const string &getTif() const;
    const string &getEmail() const;
    const string &getPhoneNumber() const;


    //Setters
    void setName(const string &name);
    void setIdNumber(const optional<string>& idNumber);
    void setTif(const string &tif);
    void setEmail(const string &email);
    void setPhoneNumber(const string &phoneNumber);

    // Helper functions for validation
    bool isValidCode(const string &code) const;
    bool hasCode(const wstring &code) const;
    bool isNameValid(const string &name);
    bool isIdNumberValid(const optional<string>& idNumber);
    bool isTifValid(const string &tif);
    bool isEmailValid(const string &email);
    bool isPhoneNumberValid(const string &phoneNumber);

    //Helper functions for put request
    Result changeName(const string &newName);
    Result changeIdNumber(const optional<string>& idNumber);
    Result changeTif(const string &newTif);
    Result changeEmail(const string &newEmail);
    Result changePhoneNumber(const string& newPhoneNumber);

};

#endif //DHMS_CLIENT_H
