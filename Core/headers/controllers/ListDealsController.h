//
// Created by Utilizador on 12/01/2025.
//

#ifndef LISTDEALSCONTROLLER_H
#define LISTDEALSCONTROLLER_H
#include <map>

#include "domain/model/AdvertisementDTO.h"
#include "domain/model/StoreDTO.h"
#include <list>

using namespace std;

class ListDealsController {
public:
    map<shared_ptr<StoreDTO>, map<string, list<shared_ptr<AdvertisementDTO>>>> getAllDealsGroupedByStore();
};

#endif //LISTDEALSCONTROLLER_H
