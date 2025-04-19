//
// Created by Rui Pedro Monteiro on 16/11/2024.
//

#ifndef DHMS_GETAGENTLISTCONTROLLER_H
#define DHMS_GETAGENTLISTCONTROLLER_H

#include <vector>
#include <memory>

class GetAgentListController {
public:
    explicit GetAgentListController(StoreContainer& storeContainer);

    // Fetch the list of agents grouped by store and sorted alphabetically
    std::vector<Agent> fetchAgents();

private:
};

#endif // DHMS_GETAGENTLISTCONTROLLER_H