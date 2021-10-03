//
// Created by fraer on 27/09/2021.
//

#ifndef MARKETLIST_PRODUCTSCANNER_H
#define MARKETLIST_PRODUCTSCANNER_H

#include "Observer.h"
#include "ShoppingList.h"

class ProductScanner : public Observer {
public:
    explicit ProductScanner(ShoppingList* shoppingList) : shoppingList(shoppingList) {
        shoppingList->registerObserver(this);
    }
    ~ProductScanner() override {
        shoppingList->removeObserver(this);
    }

    void update() override {
        if (shoppingList->getListCategory().empty())
            cout << "\nMarket ";
        else
            cout << "\n" << shoppingList->getListCategory() << " ";
        cout << "List updated!" << endl;
        cout << "Number of enlisted elements: " << shoppingList->getShoppingListSize() << endl;
        shoppingList->printList();
    }

private:
    ShoppingList* shoppingList;
};

#endif //MARKETLIST_PRODUCTSCANNER_H
