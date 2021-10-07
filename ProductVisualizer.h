//
// Created by fraer on 07/10/2021.
//

#ifndef MARKETLIST_PRODUCTVISUALIZER_H
#define MARKETLIST_PRODUCTVISUALIZER_H

#include "Observer.h"
#include "ShoppingList.h"

class ProductVisualizer : public Observer {
public:
    explicit ProductVisualizer(ShoppingList* shoppingList) : shoppingList(shoppingList) {
            shoppingList->registerObserver(this);
    }
    ~ProductVisualizer() override {
        shoppingList->removeObserver(this);
    }

    void update() override {
        if (shoppingList->getListName().empty())
            cout << "\nMarket ";
        else
            cout << "\n" << shoppingList->getListName() << " ";
        cout << "List updated!" << endl;
        cout << "Number of enlisted elements: " << shoppingList->getShoppingListSize() << endl;
        shoppingList->printList();
        // FIXME Rewrite printList and displayItem methods here
        // TODO Add functionality to handle articles left to buy + bought in the update() method
    }

    // TODO Change class name to ProductVisualizer

private:
    ShoppingList* shoppingList;
};


#endif //MARKETLIST_PRODUCTVISUALIZER_H
