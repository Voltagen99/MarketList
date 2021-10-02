#include "ShoppingList.h"
#include "ProductScanner.h"

int main() {
    ShoppingItem item1("Milk", "Dairy", 1.50);
    ShoppingItem item2("Mozzarella Cheese","Dairy", 1.20);
    ShoppingItem item3("Chicken Wings","Animal Products", 2);
    ShoppingItem item4("Grana Padano Cheese", "Dairy", 10);
    ShoppingItem item5("Napisan", "Housecare");

    ShoppingList list1;
    ShoppingList list2;
    list2.setListCategory("Dairy");

    ProductScanner general(&list1);
    ProductScanner dairy(&list2);

    list1.addArticle(item1);
    list1.addArticle(item2);
    list1.addArticle(item3);
    list1.addArticle(item4);
    list1.addArticle(item5);
    list1.removeArticle(item5);
    item5.setPrice(6.20);
    list1.addArticle(item5);
    list2.addArticle(item1);
    list2.addArticle(item2);
    list2.addArticle(item3);
    list2.removeArticle(item2);
    return 0;
}
