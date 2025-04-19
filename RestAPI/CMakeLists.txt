project(RestAPI)

add_executable(RestAPI RestAPI.cpp
        headers/Server.h
        headers/RouterConfig.h
        headers/ServerStatusRouter.h
        headers/StoreRouter.h
        sources/RouterConfig.cpp
        sources/Server.cpp
        sources/ServerStatusRouter.cpp
        sources/StoreRouter.cpp
        sources/AgentRouter.cpp
        sources/AdvertisementRouter.cpp
        headers/AdvertisementRouter.h
        headers/AgentRouter.h
        headers/ClientRouter.h
        sources/ClientRouter.cpp)

target_link_libraries(RestAPI Core)

# We need to link our application to ws2_32 on windows for the implementation of winsock2.h
if(WIN32)
    target_link_libraries(RestAPI ws2_32)
endif()
# WIN32