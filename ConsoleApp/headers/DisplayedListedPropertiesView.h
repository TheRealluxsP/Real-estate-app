//
// Created by Angelo on 12/01/2025.
//

#ifndef DHMS_DISPLAYEDLISTEDPROPERTIESVIEW_H
#define DHMS_DISPLAYEDLISTEDPROPERTIESVIEW_H

#include "BaseView.h"
#include "controllers/DisplayListedPropertiesController.h"

class DisplayListedPropertiesView : public BaseView {
private:
    unique_ptr<DisplayListedPropertiesController> ctrl;

public:
    DisplayListedPropertiesView();

protected:
    int renderBody();
};


#endif //DHMS_DISPLAYEDLISTEDPROPERTIESVIEW_H
