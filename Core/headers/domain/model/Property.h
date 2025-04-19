//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_GETAGENTLISTCONTROLLER_H
#define DHMS_GETAGENTLISTCONTROLLER_H

#include <string>
#include "Entity.h"
#include "PropertyDTO.h"
#include "PropertyId.h"

using namespace std;

class Property : public Entity<PropertyId>{
protected:
    double area;               // Area of the property in square meters
    wstring location;           // Location of the property
    wstring distanceCenter;     // Distance from the property to the city center
    wstring photograph;
    static int code;

public:
    // Constructor
    Property(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph);

    Property();

    static shared_ptr<Property> createProp(const shared_ptr<PropertyDTO> &propertyDTO);

    const wstring &getCode() const;

    double getArea() const;
    void setArea(double area);

    wstring getLocation() const;
    void setLocation(const wstring &location);

    wstring getDistanceCenter() const;
    void setDistanceCenter(const wstring &distanceCenter);

    wstring getPhotograph() const;
    void setPhotograph(const wstring &photograph);

};

#endif // DHMS_GETAGENTLISTCONTROLLER_H
