//
// Created by siulo on 06/01/2025.
//

#ifndef DHMS_LISTDEALSVIEW_H
#define DHMS_LISTDEALSVIEW_H


#include <memory>

#include "BaseView.h"
#include "controllers/ListDealsController.h"

class ListDealsView : public BaseView{
private:
    unique_ptr<ListDealsController> ctrl;
public:
    ListDealsView();
protected:
    int renderBody();
};

#endif //DHMS_LISTDEALSVIEW_H
