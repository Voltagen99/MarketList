#include "ShoppingList.h"

int main() {
    ShoppingItem item1 = ShoppingItem("Latte", "Latticini");
    ShoppingItem item2 = ShoppingItem("Mozzarella di bufala","Latticini");
    ShoppingItem item3 = ShoppingItem("Petto di pollo","Prodotti animali");
    ShoppingList lista1 = ShoppingList("");
    ShoppingList lista2 = ShoppingList("Latticini");
    lista1.addArticle(item1);
    lista1.addArticle(item2);
    lista1.printList();
    lista2.addArticle(item1);
    lista2.addArticle(item3);
    lista2.printList();
    return 0;
}
