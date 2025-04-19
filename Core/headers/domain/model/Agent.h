//
// Created by Angelo on 11/11/2024.
//

#ifndef DHMS_AGENT_H
#define DHMS_AGENT_H

#include <string>
#include <memory>
#include <optional>
#include "Store.h"
#include "Entity.h"
#include "Result.h"
#include "AgentId.h"
#include "StoreId.h"

using namespace std;

class Agent : public Entity<AgentId>{
private:
    string name;
    optional<string> idNumber;
    string email;
    string phoneNumber;
    shared_ptr<Store> store;
    static int code;

public:
    //Constructor
    Agent();
    Agent(const string &name, const optional<string> &idNumber,const string &email,const string &phoneNumber, const shared_ptr<Store> &store);

    //Destructor
    virtual ~Agent();

    //Getters
    const wstring &getCode() const;
    const string &getName() const;
    const optional<string>& getIdNumber() const;
    const string &getPhoneNumber() const;
    const shared_ptr<Store> &getStore() const;
    const string &getEmail() const;


    //Setters
    void setName(const string &name);
    void setIdNumber(const optional<string>& idNumber);
    void setEmail(const string &email);
    void setPhoneNumber(const string &phoneNumber);
    void setStore(const shared_ptr<Store> &store);

    // Helper functions for validation
    bool isValidCode(const string &code) const;
    bool hasCode(const wstring &code) const;
    bool isNameValid(const string &name);
    bool isIdNumberValid(const optional<string>& idNumber);
    bool isEmailValid(const string &email);
    bool isPhoneNumberValid(const string &phoneNumber);
    bool isStoreValid(const shared_ptr<Store> &store);


    //Helper functions for put request
    Result changeName(const string &newName);
    Result changeIdNumber(const optional<string>& idNumber);
    Result changeEmail(const string &newEmail);
    Result changePhoneNumber(const string& newPhoneNumber);
    Result changeStore(const shared_ptr<Store> newStore);


};


#endif //DHMS_AGENT_H
