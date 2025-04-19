//
// Created by Utilizador on 04/01/2025.
//

#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include "Property.h"
#include "AdvertisementId.h"
#include "Agent.h"
#include "Client.h"
#include "Entity.h"

// Advertisement class represents an advertisement with various properties.
class Advertisement : public Entity<AdvertisementId> {
private:
    string typeProperty;       // Type of property (e.g., House, Apartment, Land)
    string typeBusiness;       // Type of business (e.g., Sale, Rent)
    float price;               // Price of the advertisement
    shared_ptr<Property> property; // Associated property
    shared_ptr<Client> client; // Associated client
    shared_ptr<Agent> agent;   // Associated agent
    bool isSold;               // Status whether the advertisement is sold
    bool visibility;           // Visibility status of the advertisement
    float commission;          // Commission associated with the advertisement
    bool isPercentageValue = false;    // Flag to know if the comission is a percentage value or not
    static int code;
    static int assignedAgent;

public:
    // Constructor with code and full advertisement data
    Advertisement(const string& typeProperty, const string& typeBusiness, float price,
                  const shared_ptr<Property>& property, const shared_ptr<Client>& client,  shared_ptr<Agent>& agent);

    // Default constructor
    Advertisement();

    // Destructor
    ~Advertisement();

    // Getter methods
    const wstring& getCode() const;
    const string& getTypeProperty() const;
    const string& getTypeBusiness() const;
    float getPrice() const;
    const shared_ptr<Property>& getProperty() const;
    const shared_ptr<Client>& getClient() const;
    const shared_ptr<Agent>& getAgent() const;
    const shared_ptr<Store>& getStoreByAgent() const;
    bool isAdvertisementSold() const;
    bool isAdvertisementVisible() const;
    float getCommission() const;
    bool getIsPercentageValue() const;

    // Setter methods
    void setTypeProperty(const string& typeProperty);
    void setTypeBusiness(const string& typeBusiness);
    void setPrice(float price);
    void setSoldStatus(bool isSold);
    void setVisibility(bool visibility);
    void setCommission(float commission);
    void setId(const wstring& id); // Set the advertisement ID
    void setIsPercentageValue(bool isPercentageValue);
    void setProperty(const shared_ptr<Property> &property);
    void setAgent(shared_ptr<Agent> &agent);
    void setClient(const shared_ptr<Client> &client);

    // Helper functions for validation
    bool hasCode(const wstring &code) const;

    // Helper functions to update advertisement details
    Result changePrice(float newPrice);
    Result changeCommission(float newCommission);
    Result changeProperty(const shared_ptr<Property>& newProperty);
    Result changeClient(const shared_ptr<Client>& newClient);
    Result changeAgent(const shared_ptr<Agent>& newAgent);
    Result changeSoldStatus(bool newStatus);
    Result changeVisibility(bool newVisibility);
};

#endif //ADVERTISEMENT_H