//
// Created by Utilizador on 17/11/2024.
//

#include "controllers/RegisterStoreController.h"

#include <memory>

#include "headers/domain/model/Store.h"
#include "controllers/Company.h"

//Constructor
RegisterStoreController::RegisterStoreController() = default;

Result RegisterStoreController::registerStore(wstring code, string designation, string address, string openingTime, string closingTime) {

    this->service = Company::GetInstance()->getStoreService();
    return service->createAndSaveStore(code, designation, address, openingTime, closingTime);
    
}


