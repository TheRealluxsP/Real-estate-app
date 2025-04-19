//
// Created by siulo on 06/01/2025.
//

#ifndef DHMS_BASEVIEW_H
#define DHMS_BASEVIEW_H

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class BaseView{
protected:
    Utils utils;
    vector<wstring> headers;

    void renderHeader();

    virtual int renderBody() = 0;
public:
    BaseView();

    int show();
};

#endif //DHMS_BASEVIEW_H
