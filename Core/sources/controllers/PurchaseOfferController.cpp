//
// Created by Angelo on 04/01/2025.
//

/*#include "headers/controllers/PurchaseOfferController.h"
#include "controllers/Company.h"

PurchaseOfferController::PurchaseOfferController() {
    this->advService = Company::GetInstance()->getAdvertisementService();
    this->purchaseOfferService = Company::GetInstance()->getPurchaseOfferService();
}

// Method to get an advertisement by code
shared_ptr<Advertisement> PurchaseOfferController::getAdvByCode(const wstring& code) {
    auto advOpt = this->advService->getByCode(code);
    if (advOpt.has_value()) {
        return advOpt.value();
    }
    throw invalid_argument("Advertisement not found with the given code.");
}

// Method to create a purchase offer
Result PurchaseOfferController::createOffer(float value, const wstring& advCode, const wstring& clientCode) {
    try {
        // Retrieve the advertisement by code
        this->adv = getAdvByCode(advCode);

        // Create the purchase offer using the PurchaseOfferService
        this->purchaseOffer = this->purchaseOfferService->create(value, this->adv, clientCode);

        // Validate the purchase offer
        Result validationResult = this->purchaseOffer->validate();
        if (!validationResult.isOK()) {
            return validationResult;
        }

        // Save the purchase offer
        return this->purchaseOfferService->addOrUpdate(this->purchaseOffer);

    } catch (const invalid_argument& e) {
        return Result::NOK(L"Error: " + utils::toWString(e.what()));
    } catch (const exception& e) {
        return Result::NOK(L"Unexpected error occurred while creating the purchase offer.");
    }
}
 */