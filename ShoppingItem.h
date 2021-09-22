//
// Created by fraer on 22/09/2021.
//

#ifndef MARKETLIST_SHOPPINGITEM_H
#define MARKETLIST_SHOPPINGITEM_H

#include <iostream>
#include <string>
using namespace std;

class ShoppingItem {
public:
    explicit ShoppingItem(string itemName = "", string category = "", float price = 0, int quantity = 1) :
    itemName(std::move(itemName)), category(std::move(category)), price(price), quantity(quantity) {}

    bool operator==(const ShoppingItem& other) {
        return itemName == other.itemName;
    }

    const string &getItemName() const {
        return itemName;
    }

    const string &getCategory() const {
        return category;
    }

    float getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setPrice(float p) {
        std::cout.precision(2);
        this->price = p;
    }

    void setQuantity(int q) {
        this->quantity = q;
    }

private:
    string itemName, category;
    float price;
    int quantity;
};


#endif //MARKETLIST_SHOPPINGITEM_H
