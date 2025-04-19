//
// Created by Utilizador on 17/11/2024.
//

#include "../headers/RegisterStoreView.h"

RegisterStoreView::RegisterStoreView()  {
    this->headers = {L"Registering a Store!"};
    this->ctrl = make_unique<RegisterStoreController>();
}

int RegisterStoreView::renderBody() {
    bool exit = false;
    do {
        wstring code = utils.readNonEmptyLine(L"Enter store code");
        wstring wdesignation = utils.readNonEmptyLine(L"Enter store designation");
        string designation(wdesignation.begin(), wdesignation.end());
        wstring waddress = utils.readNonEmptyLine(L"Enter store address");
        string address(waddress.begin(), waddress.end());
        wstring wopeningTime = utils.readNonEmptyLine(L"Enter store opening time");
        string openingTime(wopeningTime.begin(), wopeningTime.end());
        wstring wclosingTime = utils.readNonEmptyLine(L"Enter store closing time");
        string closingTime(wclosingTime.begin(), wclosingTime.end());

        try {
            Result result = ctrl->registerStore(code, designation, address, openingTime, closingTime);

            if(result.isOK()){
                utils.printLine(L"Store successfully created!");
                utils.readEnterToContinue();
                exit = true;
            }else{
                utils.printLine(L"Error: " + result.getMessage() + L" Please try again.");
            }
        }
        catch (invalid_argument e) {
            string strMsg = "Error: ";
            strMsg.append(e.what());
            utils.printLine(strMsg);
            exit = !utils.readBoolean(L"Do you want to retry?");
        }

    } while (!exit);
    return 0;
}
