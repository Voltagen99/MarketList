//
// Created by fraer on 03/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"
#include "../ShoppingList.h"

class ListTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (int i = 1; i <= 9; i++) {
            l.addArticle(s);
        }
        l.setListCategory("");
    }
    void TearDown() override {}
    ShoppingList l;
    ShoppingItem s;
};

TEST_F(ListTest, TestListCategory) {
    ASSERT_FALSE(l.isListCategory());
    l.setListCategory("ListBase");
    ASSERT_EQ("ListBase", l.getListCategory());
}

TEST_F(ListTest, TestListSize) {
    ASSERT_EQ(9, l.getShoppingListSize());
    l.addArticle(s);
    ASSERT_EQ(10, l.getShoppingListSize());
    l.removeArticle(s);
    ASSERT_EQ(9, l.getShoppingListSize());
}