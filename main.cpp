#include "ProductVisualizer.h"
#include "version.h"

int main() {
    cout << "PROJECT: Market List\nVERSION: " << VERSION << endl;
    ShoppingItem item1("Milk", "Dairy", 1.50);
    ShoppingItem item2("Mozzarella Cheese","Dairy", 1.20);
    ShoppingItem item3("Chicken Wings","Animal Products", 2);
    ShoppingItem item4("Grana Padano Cheese", "Dairy", 10);
    ShoppingItem item5("Napisan");

    ShoppingList list1;
    ShoppingList list2;
    list2.setListName("Dairy");

    ProductVisualizer general(&list1);
    ProductVisualizer dairy(&list2);

    list1.addArticle(item1);
    list1.addArticle(item2);
    list1.addArticle(item3);
    list1.addArticle(item4);
    list1.addArticle(item5);
    list1.removeArticle(item5);
    item5.setCategory("Housecare");
    item5.setPrice(6.20);
    item5.setQuantity(1);
    list1.addArticle(item5);
    list2.addArticle(item1);
    list2.addArticle(item2);
    list2.addArticle(item3);
    list2.removeArticle(item2);
    return 0;
}
