
//
// Created by Angelo on 04/01/2025.
//

#ifndef DHMS_PURCHASEOFFERCONTROLLER_H
#define DHMS_PURCHASEOFFERCONTROLLER_H



#include "domain/model/PurchaseOffer.h"
#include "memory"
#include "domain/services/AdvertisementService.h"
#include "domain/services/PurchaseOfferService.h"
#include "domain/services/ClientService.h"

class PurchaseOfferController {

private:
    shared_ptr<PurchaseOffer> purchaseOffer;
    shared_ptr<Advertisement> adv;
    shared_ptr<AdvertisementService> advService;
    shared_ptr<PurchaseOfferService> purchaseOfferService;
    shared_ptr<ClientService> clientService;
    shared_ptr<Client> client;

public:


    PurchaseOfferController();
    shared_ptr<Advertisement> getAdvByCode(const wstring& code);
    Result createOffer(float value, const wstring& advCode, const wstring& clientCode);

};


#endif //DHMS_PURCHASEOFFERCONTROLLER_H

