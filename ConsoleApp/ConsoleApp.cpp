#include <iostream>

#include "controllers/Company.h"
#include "domain/model/House.h"
#include "domain/services/ClientService.h"
#include "headers/WelcomeView.h"
#include "domain/model/House.h"


using namespace std;

int main() {

    shared_ptr<ClientService> clientService = Company::GetInstance()->getClientService();
    shared_ptr<Client> client = clientService->create(L"1", "Joao", "1", "1230129", "Joao@gmail.com", "933455676");
    clientService->addOrUpdate(client);

    shared_ptr<StoreService> storeService = Company::GetInstance()->getStoreService();
    shared_ptr<Store> store1 = storeService->create(L"B5000", "Loja", "Rua", "12:00", "18:00");
    storeService->addOrUpdate(store1);

    shared_ptr<Store> store2 = storeService->create(L"B5001", "Loja2", "Rua", "12:00", "18:00");
    storeService->addOrUpdate(store2);

    shared_ptr<AgentService> agentService = Company::GetInstance()->getAgentService();
    shared_ptr<Agent> agent1 = agentService->create("Joana", "2", "Joana@gmail.com", "933444555", store1);
    agentService->addOrUpdate(agent1);

    shared_ptr<Agent> agent2 = agentService->create("Manuel", "5", "Manuel@gmail.com", "932444555", store2);
    agentService->addOrUpdate(agent2);

    shared_ptr<Property> property1 = make_shared<Property>(200, L"Porto", L"1 km", L"hwasycalkoa");
    shared_ptr<Property> property2 = make_shared<Property>(230, L"Lisboa", L"2 km", L"hwasycalkoa");
    shared_ptr<Property> property3 = make_shared<Property>(180, L"Coimbra", L"5 km", L"hwasycalkoa");
    shared_ptr<Property> property4 = make_shared<Property>(350, L"Porto", L"10 km", L"hwasycalkoa");
    shared_ptr<Property> property5 = make_shared<Property>(300, L"Lisboa", L"", L"hwasycalkoa");
    shared_ptr<Property> property6 = make_shared<House>(120.5, L"Downtown", L"500m", L"https://example.com/image.jpg", 3 , 2 , 1, L"Fully furnished", true, false, true);

    shared_ptr<Advertisement> advertisement1 = make_shared<Advertisement>("Land", "Sale", 100000, property1, client, agent1);
    shared_ptr<Advertisement> advertisement2 = make_shared<Advertisement>("Land", "Sale", 250000, property2, client, agent1);
    shared_ptr<Advertisement> advertisement3 = make_shared<Advertisement>("Land", "Rent", 374000, property3, client, agent1);
    shared_ptr<Advertisement> advertisement4 = make_shared<Advertisement>("Land", "Sale", 302000, property4, client, agent2);
    shared_ptr<Advertisement> advertisement5 = make_shared<Advertisement>("Land", "Rent", 8000, property5, client, agent2);
    shared_ptr<Advertisement> advertisement6 = make_shared<Advertisement>("House","Sale", 250000, property6, client, agent1);

    advertisement6->setVisibility(true);
    shared_ptr<AdvertisementService> advertisementService = Company::GetInstance()->getAdvertisementService();
    advertisement2->setSoldStatus(true);
    advertisement3->setSoldStatus(true);
    advertisement4->setSoldStatus(true);
    advertisement5->setSoldStatus(true);
    advertisementService->addOrUpdate(advertisement1);
    advertisementService->addOrUpdate(advertisement2);
    advertisementService->addOrUpdate(advertisement3);
    advertisementService->addOrUpdate(advertisement4);
    advertisementService->addOrUpdate(advertisement5);
    advertisementService->addOrUpdate(advertisement6);


    WelcomeView view;
    view.show();
    return 0;
}