//
// Created by fraer on 21/09/2021.
//

#ifndef MARKETLIST_SHOPPINGLIST_H
#define MARKETLIST_SHOPPINGLIST_H

#include <list>
#include <algorithm>
#include "ShoppingItem.h"

class ShoppingList {
public:
    explicit ShoppingList(string category = "") : category(std::move(category)) {}
    ~ShoppingList() = default;

    void addArticle(const ShoppingItem& newArticle) {
        if (newArticle.getCategory() == ShoppingList::getCategory())
            spesaList.emplace_back(newArticle);
        else {
            if (ShoppingList::getCategory().empty())
                spesaList.emplace_back(newArticle);
        }
    }

    void removeArticle(const ShoppingItem& toDelete) {
        for (auto it = spesaList.begin(); it != spesaList.end(); ++it) {
            if (findArticle(toDelete))
                it = spesaList.erase(it);
        }
    }

    bool findArticle(const ShoppingItem& toFind) {
        auto it = find(spesaList.begin(), spesaList.end(), toFind);
        if (it != spesaList.end())
            return true;
        else
            return false;
    }

    void printList() {
        cout << "LISTA SPESA: " << ShoppingList::getCategory() << endl;
        for (const auto& it : spesaList)
            cout << it.getItemName() << endl;
        cout << endl;
    }

    const string &getCategory() const {
        return category;
    }

private:
    list<ShoppingItem> spesaList;
    string category;
};


#endif //MARKETLIST_SHOPPINGLIST_H