//
// Created by siulo on 06/01/2025.
//

#ifndef DHMS_WELCOMEVIEW_H
#define DHMS_WELCOMEVIEW_H

#include "MenuView.h"

class WelcomeView :public MenuView{
public:
    WelcomeView();

    int processMenuOption(int option);
};

#endif //DHMS_WELCOMEVIEW_H
