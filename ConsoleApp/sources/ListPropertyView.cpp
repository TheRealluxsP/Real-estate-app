//
// Created by siulo on 06/01/2025.
//

#include "../headers/ListPropertyView.h"

#include "StringUtils.h"
#include "controllers/Company.h"
#include "domain/model/HouseDTO.h"
#include "domain/model/PropertyDTO.h"
#include "domain/model/ResidencyDTO.h"

ListPropertyView::ListPropertyView() {
    this ->headers = {L"List your Property for sale or rent!"};
    this->ctrl = make_unique<ListPropertyController>();
}

int ListPropertyView::renderBody() {
    bool exit = false;
    do{
        wstring internalCode = utils.readNonEmptyLine(L"Enter client code");

        try{
            Result clientExists=ctrl->getClientByCode(internalCode);

            if(clientExists.isOK()) {
                string typeProperty = StringUtils::toString(utils.readNonEmptyLine(L"Enter property type"));
                double area = utils.readDouble(L"Enter property area (in square meters)");
                wstring location = utils.readNonEmptyLine(L"Enter property location");
                wstring distanceCenter = utils.readLine(L"Enter the distance from the city center (press enter to ignore)");
                wstring photograph = utils.readNonEmptyLine(L"Enter a photograph (URL)");
                list<shared_ptr<AgentDTO>> agentsDTO;

                if(typeProperty == "Land"){
                    shared_ptr<PropertyDTO> propertyDTO = make_shared<PropertyDTO>(area, location, distanceCenter, photograph);
                    agentsDTO = ctrl->createLand(propertyDTO);
                }else if(typeProperty == "Apartment" || typeProperty == "House") {
                    int numberBedrooms = utils.readInteger(L"Enter number of bedrooms");
                    int numberBathrooms = utils.readInteger(L"Enter number of bathrooms");
                    int parkingSpaces = utils.readInteger(L"Enter number of parking spaces");
                    wstring availableEquipment = utils.readNonEmptyLine(L"Enter available equipment");
                    if(typeProperty == "Apartment") {
                        shared_ptr<ResidencyDTO> residencyDTO = make_shared<ResidencyDTO>(area, location, distanceCenter, photograph, numberBedrooms, numberBathrooms, parkingSpaces, availableEquipment);
                        agentsDTO = ctrl->createApartment(residencyDTO);
                    }else if(typeProperty == "House") {
                        bool existenceBasement = utils.readBoolean(L"Does the property have a basement?");
                        bool habittableAttic = utils.readBoolean(L"Does the property have an habittableAttic?");
                        bool sunExposure = utils.readBoolean(L"Does the property have sunExposure?");
                        shared_ptr<HouseDTO> houseDTO = make_shared<HouseDTO>(area, location, distanceCenter, photograph, numberBedrooms, numberBathrooms, parkingSpaces, availableEquipment, existenceBasement, habittableAttic, sunExposure);
                        agentsDTO = ctrl->createHouse(houseDTO);
                    }
                }


                string typeBusiness = StringUtils::toString(utils.readNonEmptyLine(L"Enter type of business(Sale or Rent)"));
                float price = utils.readDouble(L"Enter the price of the property");

                if(agentsDTO.empty()) {
                    utils.printLine(L"No agents available. Unable to publish advertisement.");
                    utils.readEnterToContinue();
                    return 0;
                }

                ctrl->saveAdvertisementData(typeProperty, typeBusiness, price);


                utils.printLine(L"Available agents:");
                for (shared_ptr<AgentDTO> agentDTO : agentsDTO) {
                    utils.printLine(L"Code: " + agentDTO->code + L", Name: " + utils.string2wstring(agentDTO->name));
                }
                wstring agentCode = utils.readLine(L"Enter an agent code (if you ignore this or choose a non-existent code, the system will automatically assign an agent)");
                Result operationSuccess = ctrl->getAgentByCode(agentCode);
                if(operationSuccess.isOK()) {
                    utils.printLine(L"Advertisement successfully published.");
                    shared_ptr<AdvertisementService> advService = Company::GetInstance()->getAdvertisementService();
                    optional<shared_ptr<Advertisement>> adv = advService->getByCode(L"1");
                    if(adv) {
                        utils.printLine(adv.value()->getTypeProperty());
                        utils.printLine(adv.value()->getTypeBusiness());
                        utils.printLine(adv.value()->getAgent()->getName());
                    }
                    utils.readEnterToContinue();
                    exit = true;
                }else {
                    utils.printLine(L"Unable to publish advertisement.");
                    exit = !utils.readBoolean(L"Do you want to retry?");
                }
            }else {
                utils.printLine(L"Please enter a valid client code.");
                exit = !utils.readBoolean(L"Do you want to retry?");
            }
        }catch (invalid_argument e){
            string strMsg = "Error: ";
            strMsg.append(e.what());
            utils.printLine(strMsg);
            exit = !utils.readBoolean(L"Do you want to retry?");
        }

    }while(!exit);
    return 0;
}