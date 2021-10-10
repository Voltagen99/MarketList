//
// Created by fraer on 03/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"
#include "../ShoppingList.h"
#include "../ShoppingList.cpp"

TEST(ShoppingItem, DefaultConstructor) {
    ShoppingItem s;
    ASSERT_FALSE(s.isName());
    ASSERT_FALSE(s.isCategory());
    ASSERT_EQ(0, s.getPrice());
    ASSERT_EQ(1, s.getQuantity());
}

TEST(ShoppingList, DefaultConstructor) {
    ShoppingList l;
    ASSERT_FALSE(l.isListName());
}

