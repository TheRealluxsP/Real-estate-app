//
// Created by Angelo on 15/11/2024.
//

#ifndef DHMS_REGISTERAGENTVIEW_H
#define DHMS_REGISTERAGENTVIEW_H



#include <iostream>
#include <memory>
#include "controllers/RegisterAgentController.h"
#include "BaseView.h"


using namespace std;

class RegisterAgentView : public BaseView{
private:
    unique_ptr<RegisterAgentController> ctrl;
protected:
    int renderBody();
public:

    //Constructor
    RegisterAgentView();
};

#endif // DHMS_REGISTERAGENTVIEW_H


