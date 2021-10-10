//
// Created by fraer on 07/10/2021.
//

#include "ProductVisualizer.h"

ProductVisualizer::~ProductVisualizer() {
    shoppingList->removeObserver(this);
}

void ProductVisualizer::update() {
    if (shoppingList->getListName().empty())
        cout << "\nMarket ";
    else
        cout << "\n" << shoppingList->getListName() << " ";
    cout << "List updated!" << endl;
    cout << "Number of enlisted elements: " << shoppingList->getShoppingListSize() << endl;
    // TODO Tostring method; type string, returns a string

    // TODO Method is being rewritten, coming soon in a future update
    /*int i, bought = 0, unbought = static_cast<int>(shoppingList->getShoppingListSize());
    for (i = 1; i <= shoppingList->getShoppingListSize(); i++) {
        cout << "---" << i << ") ";
        cout << "[ITEM: " << getItemName() << "] ";
        cout << "[CATEGORY: ";
        if (it.getCategory().empty())
            cout << "Not specified]" << endl;
        else
            cout << it.getCategory() << "]" << endl;
        cout << "[" << it.getQuantity() << "] ";
        cout << "[TOTAL PRICE: ";
        if (!it.isPrice())
            cout << "Not specified]" << endl;
        else
            cout << it.getTotalPrice() << " Euro]" << endl;
        cout << "[BOUGHT: ";
        if (it.isBought())
            cout << "Yes]" << endl;
        else
            cout << "No]" << endl;
        if (it.isBought()) {
            bought++;
            unbought--;
        }
    }
    cout << "You have bought " << bought << "items." << endl;
    cout << "You still have to buy " << unbought << "items." << endl;
    */
}
