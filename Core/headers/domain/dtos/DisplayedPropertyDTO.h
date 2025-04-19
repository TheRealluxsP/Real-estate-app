//
// Created by Angelo on 12/01/2025.
//

#ifndef DHMS_DISPLAYEDPROPERTYDTO_H
#define DHMS_DISPLAYEDPROPERTYDTO_H

#ifndef DISPLAYED_PROPERTY_DTO_H
#define DISPLAYED_PROPERTY_DTO_H

#include <string>

class DisplayedPropertyDTO {
private:
    std::string typeBusiness;       // Sale, Rent, etc.
    std::string typeProperty;       // House, Apartment, etc.
    float price;                    // Price of the property
    double area;                    // Area in square meters
    std::wstring location;          // Location of the property
    int bedrooms;                   // Number of bedrooms
    int bathrooms;                  // Number of bathrooms
    int parkingSpaces;              // Number of parking spaces

public:
    // Constructor
    DisplayedPropertyDTO(const std::string& typeBusiness,
                         const std::string& typeProperty,
                         float price,
                         double area,
                         const std::wstring& location,
                         int bedrooms,
                         int bathrooms,
                         int parkingSpaces);

    // Getters
    const std::string& getTypeBusiness() const;
    const std::string& getTypeProperty() const;
    float getPrice() const;
    double getArea() const;
    const std::wstring& getLocation() const;
    int getBedrooms() const;
    int getBathrooms() const;
    int getParkingSpaces() const;

    // Setters
    void setTypeBusiness(const std::string& typeBusiness);
    void setTypeProperty(const std::string& typeProperty);
    void setPrice(float price);
    void setArea(double area);
    void setLocation(const std::wstring& location);
    void setBedrooms(int bedrooms);
    void setBathrooms(int bathrooms);
    void setParkingSpaces(int parkingSpaces);
};

#endif // DISPLAYED_PROPERTY_DTO_H

#endif //DHMS_DISPLAYEDPROPERTYDTO_H
