//
// Created by Rui Pedro Monteiro on 14/11/2024.
//

#ifndef DHMS_NETWORKMANAGER_H
#define DHMS_NETWORKMANAGER_H

#include "GetAgentListController.h"

class NetworkManager {
public:
    explicit NetworkManager(GetAgentListController& controller);
    ~NetworkManager();

    void getAgentsList();

private:
    GetAgentListController& controller;
};

#endif // DHMS_NETWORKMANAGER_H