//
// Created by Utilizador on 12/01/2025.
//

#ifndef PROPERTYMAPPER_H
#define PROPERTYMAPPER_H
#include <domain/model/Property.h>
#include <thirdparty/SimpleJson.hpp>

using namespace std;
using json::JSON;

class PropertyMapper {
public:
    static shared_ptr<Property> toModel(const shared_ptr<PropertyDTO>& propertyDTO);

    static shared_ptr<PropertyDTO> toDTO(const shared_ptr<Property>& property);
};

#endif //PROPERTYMAPPER_H
