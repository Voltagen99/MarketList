//
// Created by fraer on 03/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"
#include "../ShoppingList.h"
#include "../ProductScanner.h"

TEST(ShoppingItem, DefaultConstructor) {
    ShoppingItem s;
    ASSERT_FALSE(s.isName());
    ASSERT_FALSE(s.isCategory());
    ASSERT_EQ(0, s.getPrice());
    ASSERT_EQ(1, s.getQuantity());
}

TEST(ShoppingList, DefaultConstructor) {
    ShoppingList l;
    ASSERT_FALSE(l.isListCategory());
}

TEST(ProductScanner, TestUsers) {
    ShoppingList l;
    ProductScanner st(&l);
    ASSERT_EQ(1, l.getUsersNumber());
    Observer* o;
    l.registerObserver(o);
    ASSERT_EQ(2, l.getUsersNumber());
    l.removeObserver(o);
    ASSERT_EQ(1, l.getUsersNumber());
}

