//
// Created by fraer on 03/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"
#include "../ShoppingList.h"

class ListTest : public ::testing::Test {
protected:
    void SetUp() override {
        l.setListName("");
        l.addArticle(s);
    }
    void TearDown() override {}
    ShoppingList l;
    ShoppingItem s;
};

TEST_F(ListTest, TestListSize) {
    ShoppingItem q("Item");
    ASSERT_EQ(1, l.getShoppingListSize());
    l.addArticle(q);
    ASSERT_EQ(2, l.getShoppingListSize());
    l.removeArticle(q);
    ASSERT_EQ(1, l.getShoppingListSize());
}

TEST_F(ListTest, TestListCategory) {
    ASSERT_FALSE(l.isListName());
    l.setListName("ListBase");
    ASSERT_EQ("ListBase", l.getListName());
}

TEST_F(ListTest, TestBoughtStatus) {
    ShoppingItem a("Test1");
    ShoppingItem b("Test2");
    ShoppingItem c("Test3");
    l.addArticle(a);
    l.addArticle(b);
    l.addArticle(c);
    ASSERT_EQ(l.getUnboughtItems(),4);
    ASSERT_EQ(l.getBoughtItems(),0);
    l.buyChangeStatus(a);
    l.buyChangeStatus(b);
    ASSERT_EQ(l.getBoughtItems(),2);
    l.buyChangeStatus(b);
    ASSERT_EQ(l.getUnboughtItems(),3);
    l.buyChangeStatus(b);
    l.buyChangeStatus(c);
    l.buyChangeStatus(s);
    ASSERT_EQ(l.getBoughtItems(),4);
    ASSERT_EQ(l.getUnboughtItems(),0);
}