//
// Created by fraer on 07/10/2021.
//

#include "ProductVisualizer.h"

ProductVisualizer::~ProductVisualizer() {
    shoppingList->removeObserver(this);
}

void ProductVisualizer::update() {
    ostringstream updating;
    if (shoppingList->getListName().empty())
        updating << "\nMarket ";
    else
        updating << "\n" << shoppingList->getListName() << " ";
    updating << "List updated!\n";
    updating << "Number of enlisted elements: " << to_string(shoppingList->getShoppingListSize()) << endl;
    updating << shoppingList->printList();
    updating << "You have bought " << shoppingList->getBoughtItems();
    if (shoppingList->getBoughtItems() != 1)
        updating << " items.\n";
    else
        updating << " item.\n";
    updating << "You still have to buy " << shoppingList->getUnboughtItems();
    if (shoppingList->getUnboughtItems() != 1)
        updating << " items.\n";
    else
        updating << " item.\n";
    updating << "Current total price of your list (bought items only): " << shoppingList->getTotalListPrice() << " Euro\n";
    cout << updating.str();
}
