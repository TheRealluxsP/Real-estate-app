//
// Created by siulo on 06/01/2025.
//

#ifndef DHMS_AUTHMENUVIEW_H
#define DHMS_AUTHMENUVIEW_H

#include "MenuView.h"

class AuthMenuView : public MenuView {
protected:
    wstring userToken;

    virtual int processMenuOption(int option);

public:
    AuthMenuView(const wstring &userToken);
};

#endif //DHMS_AUTHMENUVIEW_H
