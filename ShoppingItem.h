//
// Created by fraer on 22/09/2021.
//

#ifndef MARKETLIST_SHOPPINGITEM_H
#define MARKETLIST_SHOPPINGITEM_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class ShoppingItem {
public:
    explicit ShoppingItem(string itemName = "", string category = "", float price = 0, int quantity = 1, bool bought = false) :
    itemName(move(itemName)), category(move(category)), price(price), quantity(quantity), bought(bought) {}

    ~ShoppingItem() = default;

    bool operator==(const ShoppingItem& other) {
        return itemName == other.itemName;
    }

    bool isName() const {
        if (this->getItemName().empty())
            return false;
        else
            return true;
    }

    void setItemName(const string &item) {
        this->itemName = item;
    }

    bool isCategory() const {
        if (this->category.empty())
            return false;
        else
            return true;
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

    void setPrice(float p);

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q);

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

    bool isBought() const {
        return bought;
    }

    void setBought(bool b) {
        this->bought = b;
    }

private:
    string itemName, category;
    float price;
    int quantity;
    bool bought;
};

#endif //MARKETLIST_SHOPPINGITEM_H
