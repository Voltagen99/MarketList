#include "ProductVisualizer.h"
#include "version.h"

int main() {
    cout << "PROJECT: Market List\nVERSION: " << VERSION << endl;
    ShoppingItem item1("Chicken Wings","Animal Products", 2, true);
    ShoppingItem item2("Grana Padano Cheese", "Dairy", 10,false);
    ShoppingItem item3("Milk", "Dairy", 1.50, true);
    ShoppingItem item4("Mozzarella","Dairy", 1.20,true);
    ShoppingItem item5("Napisan");

    ShoppingList list1;
    ShoppingList list2;
    list2.setListName("Dairy");

    ProductVisualizer general(&list1);
    ProductVisualizer dairy(&list2);

    list1.addArticle(item1); // Adding articles
    list1.addArticle(item2);
    list1.addArticle(item3);
    list1.addArticle(item4);
    list1.addArticle(item5);
    list1.removeArticle(item5); // Testing setters
    item5.setCategory("Housecare");
    item5.setBought(true);
    item5.setPrice(6.20);
    item5.setQuantity(1);
    list1.addArticle(item5);
    list2.addArticle(item1); // Adding articles (custom list)
    list2.addArticle(item2);
    list2.addArticle(item3);
    item2.setBought(true);
    list2.removeArticle(item2);
    list1.buyItem(item2);
    list2.buyItem(item2);
    list2.unBuyItem(item2);
    return 0;
}
