//
// Created by Angelo on 04/01/2025.
//



#include "headers/domain/model/PurchaseOffer.h"

int PurchaseOffer::code = 0;


PurchaseOffer::PurchaseOffer( float value, const shared_ptr<Advertisement> &adv,
                             const shared_ptr<Client> &client) : Entity (make_shared<PurchaseOfferId>(to_wstring(++code))) {
    setValue(value);
    setAdv(adv);
    setClient(client);
}

void PurchaseOffer::setValue(float value) {
    if (value < 0) {
        throw invalid_argument("Value cannot be negative.");
    }
    this->value = value;
}

void PurchaseOffer::setAdv(const shared_ptr<Advertisement> &adv) {
    if (!adv) {
        throw invalid_argument("Advertisement cannot be null.");
    }
    this->adv = adv;
}

void PurchaseOffer::setClient(const shared_ptr<Client> &client) {
    if (!client) {
        throw invalid_argument("Client cannot be null.");
    }
    this->client = client;
}

const wstring &PurchaseOffer::getCode() const {
    return this->id->getValue();
}

float PurchaseOffer::getValue() const {
    return value;
}

const shared_ptr<Advertisement> &PurchaseOffer::getAdv() const {
    return adv;
}

const shared_ptr<Client> &PurchaseOffer::getClient() const {
    return client;
}

bool PurchaseOffer::hasCode(const wstring &code) const {
    return this->id->getValue() == code;
}

