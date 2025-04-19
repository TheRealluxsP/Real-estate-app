//
// Created by Angelo on 04/01/2025.
//


#ifndef DHMS_PURCHASEOFFER_H
#define DHMS_PURCHASEOFFER_H



#include <string>
#include <stdexcept>
#include <list>
#include <memory>
#include "PurchaseOfferId.h"
#include "Entity.h"
#include "Result.h"
#include "Advertisement.h"
#include "Client.h"

using namespace std;

class PurchaseOffer : public Entity<PurchaseOfferId>{
private:
    float value;
    shared_ptr<Advertisement> adv;
    shared_ptr<Client> client;
    static int code;
public:
    PurchaseOffer( float value , const shared_ptr<Advertisement>& adv, const shared_ptr<Client>& client);

    //Setters

    void setValue(float value);
    void setAdv(const shared_ptr<Advertisement> &adv);
    void setClient(const shared_ptr<Client> &client);

    //Getters
    const wstring &getCode() const;
    float getValue() const;
    const shared_ptr<Advertisement> &getAdv() const;
    const shared_ptr<Client> &getClient() const;
    bool hasCode(const wstring &code) const;


};



#endif //DHMS_PURCHASEOFFER_H
