//
// Created by Utilizador on 12/01/2025.
//

#include "controllers/ListDealsController.h"

#include "controllers/Company.h"
#include "controllers/restapi/mappers/AdvertisementMapper.h"
#include "domain/services/AdvertisementService.h"

map<shared_ptr<StoreDTO>, map<string, list<shared_ptr<AdvertisementDTO>>>> ListDealsController::getAllDealsGroupedByStore() {
    shared_ptr<AdvertisementService> service = Company::GetInstance()->getAdvertisementService();
    list<shared_ptr<Advertisement>> soldAdvList = service->getAllDealsMade();
    list<shared_ptr<AdvertisementDTO>> soldAdvListDTO = AdvertisementMapper::toDTO(soldAdvList);

    return service->getAllDealsGroupedByStore(soldAdvListDTO);
}
