//
// Created by fraer on 08/10/2021.
//

#include "ShoppingItem.h"

void ShoppingItem::setPrice(float p) {
    if (p >= 0) {
        std::cout.precision(3);
        this->price = p;
    }
    else
        throw invalid_argument("ERROR! Invalid price input.");
}

void ShoppingItem::setQuantity(int q) {
    if (q > 0)
        this->quantity = q;
    else
        throw invalid_argument("ERROR! Invalid quantity input.");
}

bool ShoppingItem::isName() const {
    if (this->getItemName().empty())
        return false;
    else
        return true;
}

bool ShoppingItem::isCategory() const {
    if (this->category.empty())
        return false;
    else
        return true;
}
