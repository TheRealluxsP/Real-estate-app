//
// Created by Rui Pedro Monteiro on 16/11/2024.
//

#include "GetAgentListController.h"
#include <algorithm>
#include <list>

GetAgentListController::GetAgentListController(StoreContainer& storeContainer)
        : storeContainer(storeContainer) {}

std::vector<Agent> GetAgentListController::fetchAgents() {
    // Retrieve all stores
    std::list<std::shared_ptr<Store>> stores = storeContainer.getAll();
    std::vector<Agent> allAgents;

    // Iterate through each store in the container (as per the SD)
    for (const auto& store : stores) {
        if (store == nullptr) continue; // Avoid issues with null shared_ptr

        // Retrieve agents from the store
        std::vector<Agent> storeAgents = store->getAgentContainer()->getAll();
        // Assumes `getAgentContainer` returns a pointer to `AgentContainer`

        // Associate the store with the agent
        for (auto& agent : storeAgents) {
            agent.setStore(store.get()); // Link the agent with the store
        }

        // Add the agents from this store to the overall list
        allAgents.insert(allAgents.end(), storeAgents.begin(), storeAgents.end());
    }

    // Sort agents by store name and then by agent name (as per the SD)
    std::sort(allAgents.begin(), allAgents.end(), [](const Agent& a, const Agent& b) {
        if (a.getStore()->getDesignation() == b.getStore()->getDesignation()) {
            return a.getName() < b.getName(); // Compare by agent name
        }
        return a.getStore()->getDesignation() < b.getStore()->getDesignation(); // Compare by store name
    });

    return allAgents;
}