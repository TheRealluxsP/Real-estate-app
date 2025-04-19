//
// Created by siulo on 02/01/2025.
//

#include "headers/controllers/restapi/RestController.h"
#include <stdexcept>
#include "headers/domain/shared/StringUtils.h"

RestController::RestController(const std::wstring &userToken) {
    this->userToken = StringUtils::trim(userToken);
    this->company = Company::GetInstance();

    if(!ensureUserTokenIsValid())
        throw invalid_argument("Invalid argument: userToken is not valid.");
}

bool RestController::ensureUserTokenIsValid() {
    return StringUtils::ensureNotNullOrEmpty(this->userToken);
}

bool RestController::ensureUserHasRole(const std::wstring &role) {
    return (StringUtils::trim(role) == StringUtils::trim(this->userToken));
}