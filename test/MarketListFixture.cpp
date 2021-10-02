//
// Created by fraer on 02/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"

class ItemTest : public ::testing::Test {
protected:
    void SetUp() override {
        s.getItemName();
        s.setCategory("");
        s.setPrice(5.5);
        s.setQuantity(1);
    }

    void TearDown() override {}
    ShoppingItem s;
};

TEST_F(ItemTest, TestPriceCalc) {
    s.setQuantity(2);
    ASSERT_EQ(11, s.getTotalPrice());
}



