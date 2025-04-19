//
// Created by Utilizador on 12/01/2025.
//

#ifndef RESIDENCYMAPPER_H
#define RESIDENCYMAPPER_H
#include "domain/model/Residency.h"

class ResidencyMapper {
public:
    static shared_ptr<Residency> toModel(const shared_ptr<ResidencyDTO>& resDTO);
};


#endif //RESIDENCYMAPPER_H
