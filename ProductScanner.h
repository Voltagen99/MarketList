//
// Created by fraer on 27/09/2021.
//

#ifndef MARKETLIST_PRODUCTSCANNER_H
#define MARKETLIST_PRODUCTSCANNER_H

#include "Observer.h"
#include "Subject.h"
#include "ShoppingList.h"

class ProductScanner {
public:
    explicit ProductScanner(ShoppingList* shoppingList) : shoppingList(shoppingList) {
        shoppingList->registerObserver(this);
    }
    ~ProductScanner() override {
        shoppingList->removeObserver(this);
    }

    void update() override {
        // int newQuantity = shoppingList->lastEmail().getTitle();
        // unfinished method
    }

private:
    ShoppingList* shoppingList;
};


#endif //MARKETLIST_PRODUCTSCANNER_H
