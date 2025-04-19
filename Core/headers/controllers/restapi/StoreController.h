//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_STORECONTROLLER_H
#define DHMS_STORECONTROLLER_H

#include "RestController.h"
#include "HttpResult.h"

class StoreController : public RestController{
protected:

public:
    StoreController(const wstring &userToken) : RestController(userToken){};

    HttpResult getAll();

    HttpResult getById(const wstring &code);

    HttpResult postStore(const wstring& code, const string& designation, const string& address, const string& openingTime, const string& closingTime);

    HttpResult putStore(const wstring& code, const string& designation, const string& address, const string& openingTime, const string& closingTime);

    HttpResult deleteStore(const wstring &code);
};

#endif //DHMS_STORECONTROLLER_H
