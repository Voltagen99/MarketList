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

bool ShoppingList::addArticle(const ShoppingItem& newArticle) {
    string name = newArticle.getItemName();
    bool match = false;
    if (newArticle.getCategory() == ShoppingList::getListName() && spesaList.size() <= MAX_SIZE) {
        for (const auto& it : spesaList) {
            if (it.first == name)
                return false;
        }
        spesaList.insert(make_pair(name,newArticle));
        match = true;
    }
    else {
        if (ShoppingList::getListName().empty()) {
            for (const auto& it : spesaList) {
                if (it.first == name)
                    return false;
            }
            spesaList.insert(make_pair(name,newArticle));
            match = true;
        }
    }
    if (match)
        notify();
    return match;
}

void ShoppingList::removeArticle(const ShoppingItem& toDelete) {
    auto it = spesaList.begin();
    while (it != spesaList.end()) {
        if (it->second == toDelete) {
            spesaList.erase(it);
            notify();
            break;
        }
        else
            it++;
    }
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
        total += it.second.getTotalPrice();
    return total;
}
