//
// Created by fraer on 03/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"

TEST(ShoppingItem, DefaultConstructor) {
    ShoppingItem s;
    ASSERT_FALSE(s.isName());
    ASSERT_EQ(1, s.getQuantity());
}

