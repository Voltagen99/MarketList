//
// Created by fraer on 07/10/2021.
//

#ifndef MARKETLIST_PRODUCTVISUALIZER_H
#define MARKETLIST_PRODUCTVISUALIZER_H

#include "Observer.h"
#include "ShoppingList.cpp"

class ProductVisualizer : public Observer {
public:
    explicit ProductVisualizer(ShoppingList* shoppingList) : shoppingList(shoppingList) {
        shoppingList->registerObserver(this);
    }
    ~ProductVisualizer() override {
        shoppingList->removeObserver(this);
    }

    void update() override;

private:
    ShoppingList* shoppingList{};
};


#endif //MARKETLIST_PRODUCTVISUALIZER_H
