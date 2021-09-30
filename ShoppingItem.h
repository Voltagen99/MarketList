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
    explicit ShoppingItem(string itemName, string category = "", float price = 0, int quantity = 1) :
    itemName(move(itemName)), category(move(category)), price(price), quantity(quantity) {}

    ~ShoppingItem() = default;

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
        std::cout.precision(3);
        return price;
    }

    void setPrice(float p) {
        std::cout.precision(3);
        this->price = p;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q) {
        this->quantity = q;
    }

    void setCategory(const string &c) {
        this->category = c;
    }

    bool isPrice() const {
        return this->getTotalPrice() != 0;
    }

    float getTotalPrice() const {
        std::cout.precision(3);
        return (this->getPrice())*(static_cast<float>(this->getQuantity()));
    }

    void displayItem() {
        cout << "[ITEM: " << itemName << "] ";
        cout << "[" << quantity << "] ";
        cout << "[TOTAL PRICE: ";
        if (!this->isPrice())
            cout << "Not specified" << endl;
        else
            cout << this->getTotalPrice() << " Euro]" << endl;
    }

private:
    string itemName, category;
    float price;
    int quantity;
};

#endif //MARKETLIST_SHOPPINGITEM_H
