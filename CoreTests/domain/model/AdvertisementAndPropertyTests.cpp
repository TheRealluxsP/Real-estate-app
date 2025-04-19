//
// Created by Utilizador on 05/01/2025.
//

#include "gtest/gtest.h"
#include <headers/domain/model/Advertisement.h>
#include <headers/domain/shared/Result.h>

#include "controllers/Company.h"
#include "domain/model/House.h"
#include "domain/services/ClientService.h"

class AdvertisementFixture : public ::testing::Test {
protected:
    // Declare shared_ptrs as member variables
    shared_ptr<Client> client;
    shared_ptr<Agent> agent1;
    shared_ptr<Agent> agent2;
    shared_ptr<Property> property1;
    shared_ptr<Property> property2;
    shared_ptr<Property> property3;
    shared_ptr<Property> property4;
    shared_ptr<Property> property5;
    shared_ptr<Property> houseProperty;

    virtual void SetUp() override {
        shared_ptr<ClientService> clientService = Company::GetInstance()->getClientService();
        client = clientService->create(L"1", "Joao", "1", "1230129", "Joao@gmail.com", "933455676");
        clientService->addOrUpdate(client);

        shared_ptr<StoreService> storeService = Company::GetInstance()->getStoreService();
        shared_ptr<Store> store1 = storeService->create(L"B5000", "Loja", "Rua", "12:00", "18:00");
        storeService->addOrUpdate(store1);

        shared_ptr<Store> store2 = storeService->create(L"B5001", "Loja2", "Rua", "12:00", "18:00");
        storeService->addOrUpdate(store2);

        shared_ptr<AgentService> agentService = Company::GetInstance()->getAgentService();
        agent1 = agentService->create("Joana", "2", "Joana@gmail.com", "933444555", store1);
        agentService->addOrUpdate(agent1);

        agent2 = agentService->create("Manuel", "5", "Manuel@gmail.com", "932444555", store2);
        agentService->addOrUpdate(agent2);

        property1 = make_shared<Property>(200, L"Porto", L"1 km", L"hwasycalkoa");
        property2 = make_shared<Property>(230, L"Lisboa", L"2 km", L"hwasycalkoa");
        property3 = make_shared<Property>(180, L"Coimbra", L"5 km", L"hwasycalkoa");
        property4 = make_shared<Property>(350, L"Porto", L"10 km", L"hwasycalkoa");
        property5 = make_shared<Property>(300, L"Lisboa", L"", L"hwasycalkoa");
        houseProperty = make_shared<House>(120.5, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished", true, false, true);
    }

    virtual void TearDown() override {
        // Optionally reset member variables to release resources explicitly
        client.reset();
        agent1.reset();
        agent2.reset();
        property1.reset();
        property2.reset();
        property3.reset();
        property4.reset();
        property5.reset();
        houseProperty.reset();
    }
};


TEST_F(AdvertisementFixture, CreateAdvertisementWithInvalidPropertyType) {
    EXPECT_THROW(new Advertisement("Casa", "Sale", 100000, property1, client, agent1), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateAdvertisementWithInvalidTypeBusiness) {
    EXPECT_THROW(new Advertisement("Land", "Venda", 100000, property1, client, agent1), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateAdvertisementWithInvalidPrice) {
    EXPECT_THROW(new Advertisement("Land", "Sale", -100000, property1, client, agent1), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateValidAdvertisement) {
    EXPECT_NO_THROW(new Advertisement("Land", "Sale", 100000, property1, client, agent1));
}

TEST_F(AdvertisementFixture, CreatePropertyWithInvalidArea) {
    EXPECT_THROW(new Property(0, L"Lisboa", L"", L"hwasycalkoa"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreatePropertyWithInvalidLocation) {
    EXPECT_THROW(new Property(80, L"", L"", L"hwasycalkoa"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreatePropertyWithInvalidPhotograph) {
    EXPECT_THROW(new Property(200, L"Lisboa", L"", L""), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateValidProperty) {
    EXPECT_NO_THROW(new Property(200, L"Lisboa", L"", L"jasdoija"));
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidArea) {
    EXPECT_THROW(new Residency(0, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidLocation) {
    EXPECT_THROW(new Residency(200, L"", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidPhotograph) {
    EXPECT_THROW(new Residency(200, L"Downtown", L"500m", L"", 3, 2, 1, L"Fully furnished"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidNumBedrooms) {
    EXPECT_THROW(new Residency(200, L"Downtown", L"500m", L"https://example.com/image.jpg", -1, 2, 1, L"Fully furnished"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidNumBathrooms) {
    EXPECT_THROW(new Residency(200, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 0, 1, L"Fully furnished"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidParkingSpaces) {
    EXPECT_THROW(new Residency(150, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, -1, L"Fully furnished"), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateResidencyWithInvalidAvailableEquipment) {
    EXPECT_THROW(new Residency(200, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, -1, L""), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateValidResidency) {
    EXPECT_NO_THROW(new Residency(200, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished"));
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidArea) {
    EXPECT_THROW(new House(0, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidLocation) {
    EXPECT_THROW(new House(200, L"", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidPhotograph) {
    EXPECT_THROW(new House(200, L"Downtown", L"500m", L"", 3, 2, 1, L"Fully furnished", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidNumBedrooms) {
    EXPECT_THROW(new House(200, L"Downtown", L"500m", L"https://example.com/image.jpg", -1, 2, 1, L"Fully furnished", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidNumBathrooms) {
    EXPECT_THROW(new House(200, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 0, 1, L"Fully furnished", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidParkingSpaces) {
    EXPECT_THROW(new House(150, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, -1, L"Fully furnished", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateHouseWithInvalidAvailableEquipment) {
    EXPECT_THROW(new House(0, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"", true, true, true), std::invalid_argument);
}

TEST_F(AdvertisementFixture, CreateValidHouse) {
    EXPECT_NO_THROW(new House(200, L"Downtown", L"500m", L"https://example.com/image.jpg", 3, 2, 1, L"Fully furnished", true, true, true));
}

TEST_F(AdvertisementFixture, GetAdvertisementDataAfterCreation) {
    Advertisement adv("Land", "Rent", 100000, property1, client, agent1);
    EXPECT_EQ(adv.getCode(), L"1");
    EXPECT_EQ(adv.getTypeProperty(), "Land");
    EXPECT_EQ(adv.getTypeBusiness(), "Rent");
    EXPECT_EQ(adv.getPrice(), 100000);
    EXPECT_EQ(adv.getProperty(), property1);
    EXPECT_EQ(adv.getClient(), client);
    EXPECT_EQ(adv.getAgent(), agent1);
}