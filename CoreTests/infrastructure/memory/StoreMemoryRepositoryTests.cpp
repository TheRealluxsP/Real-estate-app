//
// Created by Utilizador on 06/01/2025.
//

#include <gtest/gtest.h>

#include "headers/infrastructure/memory/StoreMemoryRepository.h"

class StoreMemoryRepositoryFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        repo = new StoreMemoryRepository();
    }

    virtual void TearDown() {}

    StoreMemoryRepository* repo;
};

TEST_F(StoreMemoryRepositoryFixture, AddingOneCategory) {
    EXPECT_TRUE(this->repo->isEmpty());
    shared_ptr<Store> store = make_shared<Store>(L"S0001", "Store One", "address", "12:33", "18:00");
    this->repo->save(store);
    EXPECT_FALSE(this->repo->isEmpty());
}