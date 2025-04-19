//
// Created by siulo on 06/01/2025.
//

#ifndef DHMS_MENUVIEW_H
#define DHMS_MENUVIEW_H

#include "BaseView.h"

class MenuView : public BaseView {
protected:
    vector<wstring> menuOptions;
    wstring cancelMenuMsg;

    int renderBody();

    void renderMenuOptions();

    virtual int processMenuOption(int option) = 0;

public:
    MenuView();
};

#endif //DHMS_MENUVIEW_H
