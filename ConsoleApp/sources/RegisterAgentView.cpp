
#include "../headers/RegisterAgentView.h"

RegisterAgentView::RegisterAgentView()  {
    this->headers = {L"Registering a Store!"};
    this->ctrl = make_unique<RegisterAgentController>();
}

int RegisterAgentView::renderBody() {
    bool exit = false;
    do {
        // Fetch and display the list of stores
        auto storeList = ctrl->getAllStores();
        if (storeList.empty()) {
            utils.printLine(L"No stores available. Unable to register agent.");
            utils.readEnterToContinue();
            return 0;
        }

        utils.printLine(L"Available Stores:");
        for (const auto& store : storeList) {
            utils.printLine(L"Code: " + store->getCode() + L", Designation: " + utils.string2wstring(store->getDesignation()));
        }

        // Ask for store code
        wstring storeCode = utils.readNonEmptyLine(L"Enter the store code:");


        // Ask for agent details
        wstring wname = utils.readNonEmptyLine(L"Enter agent name");
        string name(wname.begin(), wname.end());
        wstring widNumber = utils.readLine(L"Enter agent ID number (optional)");
        optional<string> idNumber = widNumber.empty() ? nullopt : make_optional<string>(string(widNumber.begin(), widNumber.end()));
        wstring wemail = utils.readNonEmptyLine(L"Enter agent email:");
        string email(wemail.begin(), wemail.end());
        wstring wphoneNumber = utils.readNonEmptyLine(L"Enter agent phone number");
        string phoneNumber(wphoneNumber.begin(), wphoneNumber.end());

        try {
            // Attempt to register the agent
            Result result = ctrl->registerAgent(name, idNumber, email, phoneNumber, storeCode);

            if (result.isOK()) {
                utils.printLine(L"Agent successfully registered!");
                utils.readEnterToContinue();
                exit = true;
            } else {
                utils.printLine(L"Error: " + result.getMessage() + L" Please try again.");
            }
        } catch (invalid_argument& e) {
            string strMsg = "Error: ";
            strMsg.append(e.what());
            utils.printLine(strMsg);
            exit = !utils.readBoolean(L"Do you want to retry?");
        }

    } while (!exit);
    return 0;
}