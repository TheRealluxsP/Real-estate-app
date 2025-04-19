//
// Created by Rui Pedro Monteiro on 04/12/2024.
//

#ifndef DHMS_VISITMAPPER_H
#define DHMS_VISITMAPPER_H

#include "Visit.h"
#include "VisitDTO.h"

class VisitMapper {
public:
    static VisitDTO convertToDTO(const Visit& visit);
    static Visit convertToDomain(const VisitDTO& dto);
};

#endif // DHMS_VISITMAPPER_H

