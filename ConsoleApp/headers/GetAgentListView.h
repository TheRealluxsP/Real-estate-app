//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_GETAGENTLISTVIEW_H
#define DHMS_GETAGENTLISTVIEW_H

#include "NetworkManager.h"

class GetAgentListView {
public:
    explicit GetAgentListView(NetworkManager& networkManager);
    ~GetAgentListView();

    void displayAgentList();

private:
    NetworkManager& networkManager;
};

#endif // DHMS_GETAGENTLISTVIEW_H

