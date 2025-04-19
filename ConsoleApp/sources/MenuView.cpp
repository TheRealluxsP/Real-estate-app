//
// Created by siulo on 06/01/2025.
//

#include "../headers/MenuView.h"

MenuView::MenuView() : BaseView() {
    cancelMenuMsg = L"Return to previous";
}

int MenuView::renderBody() {
    bool exit = false;
    do {
        optional<int> userOption = this->utils.doSelection(L"Select your option", menuOptions, true, cancelMenuMsg);
        if (userOption.has_value()) {
            int option = userOption.value() + 1;
            if (option == 0) { // Exit/Cancel/Return
                exit = true;
            } else { // Delegating to subclasses
                int result = processMenuOption(option);
                if (result < 0) {
                    utils.printLine(L"Selected option is not developed yet.");
                    utils.readEnterToContinue();
                }
                this->renderHeader();
            }
        }
    } while (!exit);

    return 0;
}