//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#include "GetAgentListView.h"
#include <iostream>

GetAgentListView::GetAgentListView(NetworkManager& networkManager)
        : networkManager(networkManager) {}

GetAgentListView::~GetAgentListView() = default;

void GetAgentListView::displayAgentList() {
    std::cout << "Fetching agent list..." << std::endl;

    // Trigger the fetch operation through the NetworkManager
    networkManager.getAgentsList();

    std::cout << "Agent list displayed successfully." << std::endl;
}
