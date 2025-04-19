//
// Created by Utilizador on 06/01/2025.
//

#include "gtest/gtest.h"
#include <headers/domain/model/Store.h>

class StoreFixture : public ::testing::Test {

protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(StoreFixture, CreateWithEmptyCode) {
    EXPECT_THROW(new Store(L"", "Store one", "address", "12:33", "18:00"), std::invalid_argument);
}

TEST_F(StoreFixture, CreateWithCodeHavingFourChars) {
    EXPECT_THROW(new Store(L"C001", "Store One", "address", "12:33", "18:00"), std::invalid_argument);
}

TEST_F(StoreFixture, CreateWithEmptyDesignation) {
    EXPECT_THROW(new Store(L"S0001", "", "address", "12:33", "18:00"), std::invalid_argument);
}

TEST_F(StoreFixture, CreateWithEmptyAddress) {
    EXPECT_THROW(new Store(L"S0001", "Store One", "", "12:33", "18:00"), std::invalid_argument);
}

TEST_F(StoreFixture, CreateWithOpeningTimeInWrongFormat) {
    EXPECT_THROW(new Store(L"S0001", "Store One", "address", "12:3", "18:00"), std::invalid_argument);
}

TEST_F(StoreFixture, CreateWithClosingTimeInWrongFormat) {
    EXPECT_THROW(new Store(L"S0001", "Store One", "address", "12:33", "18:0"), std::invalid_argument);
}

TEST_F(StoreFixture, CreateWithValidData) {
    EXPECT_NO_THROW(new Store(L"S0001", "Store One", "address", "12:33", "18:00"));
}

TEST_F(StoreFixture, CheckingSavingDataOnCreation) {
    Store store(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_EQ(store.getCode(), L"S0001");
    EXPECT_EQ(store.getDesignation(), "Store One");
    EXPECT_EQ(store.getAddress(), "address");
    EXPECT_EQ(store.getOpeningTime(), "12:33");
    EXPECT_EQ(store.getClosingTime(), "18:00");
    EXPECT_EQ(store.getRevenue(), 0.0);
}

TEST_F(StoreFixture, ChangingToInvalidDesignation) {
    Store store(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_THROW(store.setDesignation(""), std::invalid_argument);
}

TEST_F(StoreFixture, ChangingToInvalidDesignationWithChangeFunction) {
    Store store(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_TRUE(store.changeDesignation("").isNOK());
    EXPECT_EQ(store.getDesignation(), "Store One");
}

TEST_F(StoreFixture, ChangingToValidDesignation) {
    Store store(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_NO_THROW(store.setDesignation("Store Two"));
}

TEST_F(StoreFixture, ChangingToValidDesignationWithChangeFunction) {
    Store store(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_TRUE(store.changeDesignation("Changed Store").isOK());
    EXPECT_EQ(store.getDesignation(), "Changed Store");
}


TEST_F(StoreFixture, CheckingHasCode) {
    Store store(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_TRUE(store.hasCode(L"S0001"));
    EXPECT_FALSE(store.hasCode(L"s0001"));
}

TEST_F(StoreFixture, CheckingEqualOperatorUsingMemoryAddress) {
    Store store1(L"S0001", "Store One", "address", "12:33", "18:00");
    Store store2 = store1;
    EXPECT_TRUE(store1 == store2);
}

TEST_F(StoreFixture, CheckingEqualOperatorUsingSameCodeValue) {
    Store store1(L"S0001", "Store One", "address", "12:33", "18:00");
    Store store2(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_TRUE(store1 == store2);
}

TEST_F(StoreFixture, CheckingEqualOperatorUsingDistinctCodeValues) {
    Store store1(L"S0001", "Store One", "address", "12:33", "18:00");
    Store store2(L"S0002", "Store One", "address", "12:33", "18:00");
    EXPECT_FALSE(store1 == store2);
}

TEST_F(StoreFixture, CheckingEqualOperatorCaseSensitivity) {
    Store store1(L"S0001", "Store One", "address", "12:33", "18:00");
    Store store2(L"S0002", "Store One", "address", "12:33", "18:00");
    EXPECT_FALSE(store1 == store2);
}

TEST_F(StoreFixture, CheckingLessOperator) {
    Store store1(L"S0001", "Store One", "address", "12:33", "18:00");
    Store store2(L"S0002", "Store One", "address", "12:33", "18:00");
    Store store3(L"S0003", "Store One", "address", "12:33", "18:00");
    Store store4(L"S0001", "Store One", "address", "12:33", "18:00");
    EXPECT_TRUE(store1 < store2);
    EXPECT_TRUE(store2 < store3);
    EXPECT_TRUE(store4 < store3);
    EXPECT_FALSE(store1 < store4);
}