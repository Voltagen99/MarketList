//
// Created by fraer on 07/10/2021.
//

#include "ShoppingList.h"

string ShoppingList::printList() const {
    ostringstream listing;
    int i = 1;
    if (this->isListName())
        listing << "\n" << this->getListName() << " List:\n";
    else
        listing << "\nMarket List:\n";
    for (const auto &it : spesaList) {
        listing << "---" << to_string(i) << ") ";
        listing << it.second.displayItem();
        i++;
    }
    return listing.str();
}

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
    auto it = spesaList.begin();
    while (it != spesaList.end()) {
        if (!toBuy.isBought() && it->second == toBuy) {
            toBuy.setBought(true);
            notify();
            break;
        }
        else
            it++;
    }
}

void ShoppingList::unBuyItem(ShoppingItem toUnBuy) {
    auto it = spesaList.begin();
    while (it != spesaList.end()) {
        if (toUnBuy.isBought() && it->second == toUnBuy) {
            toUnBuy.setBought(false);
            notify();
            break;
        }
        else
            it++;
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
        if (it.second.isBought())
            total += it.second.getTotalPrice();
    return total;
}

int ShoppingList::getBoughtItems() const {
    int b = 0;
    for (const auto &it : spesaList) {
        if (it.second.isBought())
            b++;
    }
    return b;
}

int ShoppingList::getUnboughtItems() const {
    int u = 0;
    for (const auto &it : spesaList) {
        if (!it.second.isBought())
            u++;
    }
    return u;
}
