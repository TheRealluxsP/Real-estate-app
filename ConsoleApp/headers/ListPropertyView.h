//
// Created by siulo on 06/01/2025.
//

#ifndef DHMS_LISTPROPERTYVIEW_H
#define DHMS_LISTPROPERTYVIEW_H


#include "BaseView.h"
#include "controllers/ListPropertyController.h"

class ListPropertyView : public BaseView {
private:
    unique_ptr<ListPropertyController> ctrl;

public:
    ListPropertyView();

protected:
    int renderBody();
};

#endif //DHMS_LISTPROPERTYVIEW_H
