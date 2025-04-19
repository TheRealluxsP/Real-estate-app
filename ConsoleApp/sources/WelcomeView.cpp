//
// Created by siulo on 06/01/2025.
//

#include "../headers/WelcomeView.h"
#include "../headers/AuthMenuView.h"
#include "controllers/Company.h"
#include "domain/model/Client.h"
#include "domain/services/ClientService.h"

using namespace std;

WelcomeView::WelcomeView() : MenuView(){
    this->headers = {
        L"Welcome to the DHMS Console App", L"",
        L"\t Please notice that no real user authentication process is implemented.",
        L"\t Thus, the authentication process is being simulated by a user role selection."
    };

    this->menuOptions = {
            L"Anonymous (unregistered)",
            L"Registered (regular client)",
            L"Agent",
            L"System Administrator",
            L"Network Manager"

    };

    this->cancelMenuMsg = L"Exit App";
}

int WelcomeView::processMenuOption(int option) {


    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            view = new AuthMenuView(L"Unregistered");
            view->show();
            break;
        case 2:
            view = new AuthMenuView(L"Client");
            view->show();
            break;
        case 3:
            break;
        case 4:
            view = new AuthMenuView(L"SysAdmin");
            view->show();
            break;
        case 5:
            view = new AuthMenuView(L"NetManager");
            view->show();
            break;
        default:
            result = -1;
            break;
    }

    return result;
}