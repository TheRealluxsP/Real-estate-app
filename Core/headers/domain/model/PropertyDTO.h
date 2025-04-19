//
// Created by siulo on 10/01/2025.
//

#ifndef DHMS_PROPERTYDTO_H
#define DHMS_PROPERTYDTO_H

#include <string>

using namespace std;

class PropertyDTO{
public:
    wstring code;
    double area;
    wstring location;
    wstring distanceCenter;
    wstring photograph;
    PropertyDTO(double area,const wstring location, const wstring distanceCenter, const wstring photograph);
    PropertyDTO(const wstring &code, double area,const wstring location, const wstring distanceCenter, const wstring photograph)
        : code(code), area(area), location(location), distanceCenter(distanceCenter), photograph(photograph) {};


};

#endif //DHMS_PROPERTYDTO_H
