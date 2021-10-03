//
// Created by fraer on 03/10/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingItem.h"
#include "../ShoppingList.h"

class ListTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (int i = 1; i <= 10; i++) {
            l.addArticle(s);
        }
    }
    void TearDown() override {}
    ShoppingList l;
    ShoppingItem s;
};