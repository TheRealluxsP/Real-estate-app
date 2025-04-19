//
// Created by siulo on 02/01/2025.
//

#ifndef DHMS_RESTCONTROLLER_H
#define DHMS_RESTCONTROLLER_H


#include <string>
#include <memory>
#include "domain/repositories/RepositoryFactory.h"
#include "controllers/Company.h"

class RestController {
protected:
    wstring userToken;
    Company* company;

    bool ensureUserTokenIsValid();

    bool ensureUserHasRole(const wstring &role);

public:
    RestController(const wstring &userToken);

};

#endif //DHMS_RESTCONTROLLER_H
