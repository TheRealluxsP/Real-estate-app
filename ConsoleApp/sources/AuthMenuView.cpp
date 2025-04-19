//
// Created by siulo on 06/01/2025.
//

#include "../headers/AuthMenuView.h"
#include "../headers/ListPropertyView.h"
#include "../headers/ListDealsView.h"
#include "../headers/RegisterStoreView.h"
#include "../headers/RegisterAgentView.h"
#include "../headers/DisplayedListedPropertiesView.h"

AuthMenuView::AuthMenuView(const std::wstring &userToken) {
    this->userToken = userToken;
    if(this->userToken == L"Client"){
        this->headers ={L"Client Options!"};

        this->menuOptions = {
            L"Request to list a property for sale or rent"
        };
    }
    else if(this->userToken == L"SysAdmin") {
        this->headers = {L"System Administrator Options!"};
        this->menuOptions = {
            L"Register new Store",
            L"Register new Agent"
        };
    }
    else if(this->userToken == L"NetManager"){
        this->headers = {L"Network Manager options!"};

        this->menuOptions = {
                L"List all deals made"
        };
    }
    else if(this->userToken == L"Unregistered"){
        this->headers = {L"Unregistered options!"};

        this->menuOptions = {
                L"Display listed properties"
        };
    }

    this-> cancelMenuMsg = L"Return";
}

int AuthMenuView::processMenuOption(int option) {
    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            if(this->userToken == L"Unregistered"){
                view = new DisplayListedPropertiesView(); // Open DisplayListedPropertiesView
                view->show();
                break;
            }
            if(this->userToken == L"Client"){
                view = new ListPropertyView();
                view->show();
                break;
            }
            if(this->userToken == L"SysAdmin") {
                view = new RegisterStoreView();
                view->show();
                break;
            }
            if(this->userToken==L"NetManager"){
                view = new ListDealsView();
                view->show();
                break;
            }

        case 2:
            if(this->userToken==L"SysAdmin"){
                view = new RegisterAgentView();
                view->show();
                break;
            }
        default:
            result=-1;
            break;
    }
    return result;
}