//
// Created by Angelo on 12/01/2025.
//


#include "domain/dtos/DisplayedPropertyDTO.h"
#include "../headers/DisplayedListedPropertiesView.h"

// Constructor
DisplayListedPropertiesView::DisplayListedPropertiesView() {
    this->headers = {L"Display Listed Properties"};
    this->ctrl = make_unique<DisplayListedPropertiesController>();
}

// Method to render the body
int DisplayListedPropertiesView::renderBody() {
    bool exit = false;
    do {
        try {
            // Fetch listed properties from the controller
            list<shared_ptr<DisplayedPropertyDTO>> displayedProperties = ctrl->getListedProperties();

            if (displayedProperties.empty()) {
                utils.printLine(L"No properties available to display.");
                utils.readEnterToContinue();
                return 0;
            }

            // Display the listed properties
            utils.printLine(L"Available Properties:");
            for (const auto &property : displayedProperties) {
                utils.printLine(L"Type of Business: " + utils.string2wstring(property->getTypeBusiness()));
                utils.printLine(L"Type of Property: " + utils.string2wstring(property->getTypeProperty()));
                utils.printLine(L"Price: " + to_wstring(property->getPrice()));
                utils.printLine(L"Area: " + to_wstring(property->getArea()));
                utils.printLine(L"Location: " + property->getLocation());
                utils.printLine(L"Bedrooms: " + to_wstring(property->getBedrooms()));
                utils.printLine(L"Bathrooms: " + to_wstring(property->getBathrooms()));
                utils.printLine(L"Parking Spaces: " + to_wstring(property->getParkingSpaces()));
                utils.printLine(L"--------------------------");
            }

            utils.readEnterToContinue();
            exit = true;
        } catch (const exception &e) {
            string strMsg = "Error: ";
            strMsg.append(e.what());
            utils.printLine(utils.string2wstring(strMsg));
            exit = !utils.readBoolean(L"Do you want to retry?");
        }
    } while (!exit);

    return 0;
}
