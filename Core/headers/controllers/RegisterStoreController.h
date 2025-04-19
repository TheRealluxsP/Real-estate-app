//
// Created by Utilizador on 17/11/2024.
//

#ifndef REGISTERSTORECONTROLLER_H
#define REGISTERSTORECONTROLLER_H
#include <memory>

#include "Result.h"
#include "domain/model/Store.h"
#include "domain/services/StoreService.h"

using namespace std;

class RegisterStoreController {
private:
    shared_ptr<StoreService> service;

public:
    //Constructor
    RegisterStoreController();

    Result registerStore(wstring code, string designation, string address, string openingTime, string closingTime);
};

#endif //REGISTERSTORECONTROLLER_H
