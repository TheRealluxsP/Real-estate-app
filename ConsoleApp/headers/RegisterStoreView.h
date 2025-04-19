//
// Created by Utilizador on 17/11/2024.
//

#ifndef REGISTERSTOREVIEW_H
#define REGISTERSTOREVIEW_H
#include <memory>

#include "BaseView.h"
#include "controllers/RegisterStoreController.h"

using namespace std;

class RegisterStoreView : public BaseView{
private:
    unique_ptr<RegisterStoreController> ctrl;
protected:
    int renderBody();
public:

    //Constructor
    RegisterStoreView();
};

#endif //REGISTERSTOREVIEW_H
