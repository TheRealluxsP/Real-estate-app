//
// Created by Tiago Cunha on 07/01/2025.
//

#ifndef DHMS_CLIENTCONTROLLER_H
#define DHMS_CLIENTCONTROLLER_H

#include "RestController.h"
#include "HttpResult.h"

class ClientController : public RestController{
protected:

public:
    ClientController(const wstring &userToken) : RestController(userToken){};

    HttpResult getAll();

    HttpResult getById(const wstring &code);

    HttpResult postClient(const wstring& code, const string& name, const optional<string> &idNumber, const string& tif, const string& email, const string& phoneNumber);

    HttpResult putClient(const wstring& code, const string& name, const optional<string> &idNumber, const string& tif, const string& email, const string& phoneNumber);

    HttpResult deleteClient(const wstring &code);
};


#endif //DHMS_CLIENTCONTROLLER_H