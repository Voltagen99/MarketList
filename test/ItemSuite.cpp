//
// Created by fraer on 02/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"
#include "../ShoppingItem.cpp"

class ItemTest : public ::testing::Test {
protected:
    void SetUp() override {
        s.setItemName("");
        s.setCategory("");
        s.setPrice(0);
        s.setQuantity(1);
    }
    void TearDown() override {}
    ShoppingItem s;
};

TEST_F(ItemTest, TestPriceCalc) {
    ASSERT_EQ(0, s.getTotalPrice());
    s.setPrice(5);
    s.setQuantity(2);
    ASSERT_EQ(10, s.getTotalPrice());
}

TEST_F(ItemTest, TestCategory) {
    ASSERT_FALSE(s.isCategory());
    s.setCategory("Base");
    ASSERT_EQ("Base", s.getCategory());
}

TEST_F(ItemTest, TestPriceException) {
    ASSERT_THROW({
        try {
            s.setPrice(-1);
        }
        catch (const invalid_argument& e) {
            ASSERT_STREQ("ERROR! Invalid price input.", e.what());
            throw;
        }
        }, invalid_argument );
}

TEST_F(ItemTest, TestQuantityException) {
    ASSERT_THROW({
        try {
            s.setQuantity(-2);
        }
        catch (const invalid_argument& e) {
            ASSERT_STREQ("ERROR! Invalid quantity input.", e.what());
            throw;
        }
        }, invalid_argument );
}
