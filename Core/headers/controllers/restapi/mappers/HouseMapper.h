//
// Created by Utilizador on 12/01/2025.
//

#ifndef HOUSEMAPPER_H
#define HOUSEMAPPER_H
#include "domain/model/House.h"

class HouseMapper {
public:
    static shared_ptr<House> toModel(const shared_ptr<HouseDTO>& houseDTO);
};

#endif //HOUSEMAPPER_H
