#include "ShoppingList.h"

int main() {
    auto lista1 = new ShoppingList();
    lista1->addArticle("Latte");
    lista1->addArticle("Uova");
    lista1->printList();
    lista1->removeArticle("Uova");
    lista1->printList();
    return 0;
}
