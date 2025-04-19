project(ConsoleApp)

add_executable(ConsoleApp ConsoleApp.cpp
        sources/RegisterAgentView.cpp
        headers/RegisterAgentView.h
        sources/RegisterStoreView.cpp
        headers/RegisterStoreView.h
        sources/PurchaseOfferView.cpp
        headers/PurchaseOfferView.h
        headers/BaseView.h
        headers/Utils.h
        sources/Utils.cpp
        sources/BaseView.cpp
        headers/MenuView.h
        sources/MenuView.cpp
        headers/WelcomeView.h
        sources/WelcomeView.cpp
        headers/AuthMenuView.h
        sources/AuthMenuView.cpp
        headers/ListPropertyView.h
        sources/ListPropertyView.cpp
        headers/ListDealsView.h
        sources/ListDealsView.cpp
        sources/DisplayedListedPropertiesView.cpp
        headers/DisplayedListedPropertiesView.h)

target_link_libraries(ConsoleApp Core)