//
// Created by Angelo on 11/11/2024.
//

#include "headers/domain/shared/User.h"


//Constructors
User::User() {}

User::User(const string &username, const string &password, const string &email, const string &name,
           unsigned int contactNumber)  {
    setUsername(username);
    setName(name);
    setPassword(password);
    setEmail(email);
    setContactNumber(contactNumber);
}

//Destructor
User::~User() {

}
//Getters and Setters
const string &User::getUsername() const {
    return username;
}

void User::setUsername(const string &username) {
    User::username = username;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}

const string &User::getEmail() const {
    return email;
}

void User::setEmail(const string &email) {
    User::email = email;
}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

unsigned int User::getContactNumber() const {
    return contactNumber;
}

void User::setContactNumber(unsigned int contactNumber) {
    User::contactNumber = contactNumber;
}
