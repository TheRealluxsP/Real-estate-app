//
// Created by Rui Pedro Monteiro on 02/12/2024.
//


#include "headers/domain/model/Property.h"
#include <stdexcept>
#include "StringUtils.h"
#include "controllers/restapi/mappers/PropertyMapper.h"

int Property::code = 0;

// Constructor
Property::Property(double area, const wstring &location, const wstring &distanceCenter, const wstring &photograph)
:Entity(make_shared<PropertyId>(to_wstring(++code)))
{
  	setArea(area);
    setLocation(location);
    setDistanceCenter(distanceCenter);
    setPhotograph(photograph);
}

Property::Property() :Entity(make_shared<PropertyId>(to_wstring(++code))){}

shared_ptr<Property> Property::createProp(const shared_ptr<PropertyDTO> &propertyDTO) {
    return PropertyMapper::toModel(propertyDTO);
}


const wstring &Property::getCode() const {
    return this->id->getValue();
}

double Property::getArea() const {
    return area;
}

void Property::setArea(double area) {
  if(area <= 0){
    throw invalid_argument("Area must be greater than zero");
  }
  this->area = area;
}

wstring Property::getLocation() const {
    return location;
}

void Property::setLocation(const wstring &location) {
  if(StringUtils::trim(location) == L""){
    throw invalid_argument("Location cannot be empty");
  }
    this->location = location;
}

wstring Property::getDistanceCenter() const {
    return distanceCenter;
}

void Property::setDistanceCenter(const wstring &distanceCenter) {
  if (StringUtils::trim(distanceCenter) == L"") {
    this->distanceCenter = L"Not specified";
    return;
  }
  this->distanceCenter = StringUtils::trim(distanceCenter);
}

wstring Property::getPhotograph() const {
    return photograph;
}

void Property::setPhotograph(const std::wstring &photograph) {
    if(StringUtils::trim(photograph) == L""){
        throw invalid_argument("Please provide a photograph.");
    }
    this->photograph = photograph;
}
