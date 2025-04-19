//
// Created by Rui Pedro Monteiro on 14/11/2024.
//

#include "NetworkManager.h"
#include <iostream>
#include <vector>

NetworkManager::NetworkManager(GetAgentListController& controller)
        : controller(controller) {}

NetworkManager::~NetworkManager() {}

void NetworkManager::getAgentsList() {
    std::vector<Agent> agents = controller.fetchAgents();

    std::string currentStore;
    for (const auto& agent : agents) {
        if (agent.getStore()->getDesignation() != currentStore) {
            currentStore = agent.getStore()->getDesignation();
            std::cout << "Store: " << currentStore << std::endl;
        }
        std::cout << "  Agent: " << agent.getName() << std::endl;
    }
}