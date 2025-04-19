//
// Created by siulo on 06/01/2025.
//

#include "../headers/ListDealsView.h"

#include "StringUtils.h"

ListDealsView::ListDealsView() {
    this->headers={L"Listing all deals made!"};
    this->ctrl = make_unique<ListDealsController>();
}

int ListDealsView::renderBody() {

    int i = 0;
    try {
        map<shared_ptr<StoreDTO>, map<string, list<shared_ptr<AdvertisementDTO>>>> storeGroupedAdsDTO = ctrl->getAllDealsGroupedByStore();

        for (const auto &storeEntry : storeGroupedAdsDTO) {
            utils.printEmptyLines(5);
            shared_ptr<StoreDTO> store = storeEntry.first;
            const map<string, list<shared_ptr<AdvertisementDTO>>> &typeBusinessMap = storeEntry.second;

            utils.printLine("Store: ");
            utils.printLine(L"Code: " + store->code);
            utils.printLine("Designation: " + store->designation);
            utils.printLine("revenue: " + to_string(store->revenue));
            utils.printEmptyLine();

            for (const auto &typeEntry : typeBusinessMap) {
                const string &typeBusiness = typeEntry.first;
                const list<shared_ptr<AdvertisementDTO>> &advertisements = typeEntry.second;

                utils.printLine("Type of Business: " + typeBusiness);
                utils.printEmptyLine();

                for(const auto &adv : advertisements) {
                    utils.printEmptyLine();
                    ++i;
                    utils.printLine("Sold advertisement number "+to_string(i) + ": " + adv->typeProperty + "{price: " + to_string(adv->price) + ", commission: " + (adv->isPercentageValue ? to_string(adv->price*adv->commission) : to_string(adv->commission ))+"}");
                    utils.printLine("Property sold: "+ adv->typeProperty + "{property code: " + StringUtils::toString(adv->propertyDto->code) + ", property area: "+ to_string(adv->propertyDto->area) + ", location: " + StringUtils::toString(adv->propertyDto->location) + ", distance from city center: "+ StringUtils::toString(adv->propertyDto->distanceCenter) + ", photograph: " + StringUtils::toString(adv->propertyDto->photograph) + "}");

                }
            }
        }
        utils.readEnterToContinue();
    }catch (invalid_argument e) {
        string strMsg = "Error: ";
        strMsg.append(e.what());
        utils.printLine(strMsg);
        utils.readEnterToContinue();
    }

    return 0;
}