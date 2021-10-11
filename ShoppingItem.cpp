//
// Created by fraer on 08/10/2021.
//

#include "ShoppingItem.h"

string ShoppingItem::displayItem() const {
    ostringstream output;
    output << "[ITEM: " << this->getItemName() << "] " << "[CATEGORY: ";
    if (this->getCategory().empty())
        output << "Not specified]\n";
    else
        output << this->getCategory() << "]\n";
    output << "[" << to_string(this->getQuantity()) << "] ";
    output << "[TOTAL PRICE: ";
    if (!this->isPrice())
        output << "Not specified] ";
    else
        output << setprecision(3) << this->getTotalPrice() << " Euro] ";
    output << "[BOUGHT: " << (this->isBought() ? "Yes]\n" : "No]\n");
    return output.str();
}

void ShoppingItem::setPrice(float p) {
    if (p >= 0) {
        std::cout.precision(3);
        this->price = p;
    }
    else
        throw invalid_argument("ERROR! Invalid price input.");
    if (!this->isBought())
        this->price = 0;
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
