//
// Created by fraer on 07/10/2021.
//

#include "ProductVisualizer.h"

void ProductVisualizer::update() {
    if (shoppingList->getListName().empty())
        cout << "\nMarket ";
    else
        cout << "\n" << shoppingList->getListName() << " ";
    cout << "List updated!" << endl;
    cout << "Number of enlisted elements: " << shoppingList->getShoppingListSize() << endl;
    shoppingList->printList();
    // FIXME Rewrite printList and displayItem methods here
    // TODO Update items bought/not bought log
}
