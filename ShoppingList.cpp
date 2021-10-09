//
// Created by fraer on 07/10/2021.
//

#include "ShoppingList.h"

void ShoppingList::registerObserver(Observer *o) {
    users.emplace_back(o);
}

void ShoppingList::removeObserver(Observer *o) {
    users.remove(o);
}

void ShoppingList::notify() {
    for(const auto & it : users)
        it->update();
}

void ShoppingList::addArticle(const ShoppingItem &newArticle) {
    bool match = false;
    if (newArticle.getCategory() == ShoppingList::getListName() &&
        spesaList.size() <= MAX_SIZE) {
        spesaList.emplace_back(newArticle);
        match = true;
    }
    else {
        if (ShoppingList::getListName().empty()) {
            spesaList.emplace_back(newArticle);
            match = true;
        }
    }
    if (match)
        notify();
    // TODO Change vector to multimap filled with ShoppingItems (add and remove the articles by confronting the name)
}

void ShoppingList::removeArticle(const ShoppingItem &toDelete) {
    vector<ShoppingItem>::iterator it;
    it = find(spesaList.begin(), spesaList.end(), toDelete);
    if (it != spesaList.end()) {
        spesaList.erase(it);
        notify();
    }
    // TODO Change vector to multimap filled with ShoppingItems (add and remove the articles by confronting the name)
}

void ShoppingList::buyItem(ShoppingItem toBuy) {
    if (!toBuy.isBought()) {
        toBuy.setBought(true);
        notify();
    }
}

void ShoppingList::unBuyItem(ShoppingItem toUnBuy) {
    if (toUnBuy.isBought()) {
        toUnBuy.setBought(false);
        notify();
    }
}

bool ShoppingList::isListName() const {
    if (this->getListName().empty())
        return false;
    else
        return true;
}

float ShoppingList::getTotalListPrice() const {
    float total = 0;
    for (const auto& it : spesaList)
        total += it.getTotalPrice();
    return total;
}
