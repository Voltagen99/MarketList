//
// Created by fraer on 02/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"

class ItemTest : public ::testing::Test {
protected:
    void SetUp() override {
        if (s.isName()) {
            s.setCategory("");
            s.setPrice(0);
            s.setQuantity(1);
        }
    }

    void TearDown() override {}
    ShoppingItem s;
};

TEST_F(ItemTest, TestPriceCalc) {
    s.setPrice(5);
    s.setQuantity(2);
    ASSERT_EQ(10, s.getTotalPrice());
}

TEST_F(ItemTest, TestCategory) {
    s.setCategory("Base");
    ASSERT_EQ("Base", s.getCategory());
}





