//
// Created by siulo on 03/01/2025.
//

#include "../headers/Server.h"
#include "../headers/ServerStatusRouter.h"
#include "../headers/StoreRouter.h"
#include "../headers/AgentRouter.h"
#include "../headers/ClientRouter.h"
#include "../headers/AdvertisementRouter.h"
#include <headers/domain/shared/StringUtils.h>
#include <iostream>
#include <stdexcept>

using namespace std;
using json::JSON;

Server::Server(){
    this->logger = &std::cout;
}

Server::Server(basic_ostream<char> *logger){
    if(logger == nullptr)
        this->logger = &std::cout;
    else
        this->logger = logger;
}

void Server::run(){
    this->run("0.0.0.0", 8080);
}

void Server::run(int port){
    this->run("0.0.0.0", port);
}

void Server::run(string host, int port){
    this->log("Welcome to the DHMS RestAPI Server");
    this->log("HTTP Server is being configured...");

    // ADDING ServerStatus Resource
    this->log("\t ... configuring server status resource...");
    ServerStatusRouter ssRouter;
    ssRouter.configure(this->svr);

    // ADDING Stores Resource
    this->log("\t ... configuring stores resource...");
    StoreRouter storeRouter;
    storeRouter.configure(this->svr);

    //Adding Agents Resource
    this->log("\t ... configuring agents resource...");
    AgentRouter agentRouter;
    agentRouter.configure(this->svr);

    //Adding Clients Resource
    this->log("\t ... configuring clients resource...");
    ClientRouter clientRouter;
    clientRouter.configure(this->svr);

    // ADDING Advertisement Resource
    this->log("\t ... configuring advertisement resource...");
    AdvertisementRouter advertisementRouter;
    advertisementRouter.configure(this->svr);


    //ADD HERE OTHER RESOURCE CONFIGURATIONS


    // START LISTENING HTTP REQUESTS
    this->log("HTTP Server is listening on port " + std::to_string(port) + ".");

    this->svr.listen(host.data(), port);
    // SERVER IS STOPPING
    this->log("HTTP Server is stopping.");
}

void Server::log(string message){
    (*this->logger) << message << std::endl;
}