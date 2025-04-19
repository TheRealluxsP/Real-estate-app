//
// Created by Angelo on 11/11/2024.
//

#ifndef DHMS_USER_H
#define DHMS_USER_H

#include <string>

using namespace std;

class User {
protected:
    string username;
    string password;
    string email;
    string name;
    unsigned int contactNumber;

public:
    User();

    User(const string &username, const string &password, const string &email, const string &name,
         unsigned int contactNumber);

    virtual ~User();

    const string &getUsername() const;
    const string &getPassword() const;
    const string &getEmail() const;
    const string &getName() const;
    unsigned int getContactNumber() const;

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setEmail(const string &email);
    void setName(const string &name);
    void setContactNumber(unsigned int contactNumber);


};


#endif //DHMS_USER_H
