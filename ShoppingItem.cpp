//
// Created by fraer on 08/10/2021.
//

#include "ShoppingItem.h"

void ShoppingItem::setPrice(float p) {
    if (p > 0) {
        if (p != this->getPrice()) {
            std::cout.precision(3);
            this->price = p;
        }
        else
            cerr << "Input and Current prices are equal." << endl;
    }
    else
        throw invalid_argument("ERROR! Invalid price input.");
}

void ShoppingItem::setQuantity(int q) {
    if (q > 0) {
        if (q != this->getQuantity())
            this->quantity = q;
        else
            cerr << "Input and Current quantities and equal." << endl;
    }
    else
        throw invalid_argument("ERROR! Invalid quantity input.");
}
