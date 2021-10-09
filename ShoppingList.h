//
// Created by fraer on 21/09/2021.
//

#ifndef MARKETLIST_SHOPPINGLIST_H
#define MARKETLIST_SHOPPINGLIST_H

#include <list>
#include <vector>
#include <algorithm>
#include "ShoppingItem.h"
#include "Subject.h"
#define MAX_SIZE 50

class ShoppingList : public Subject {
public:
    explicit ShoppingList(string listName = "") : listName(move(listName)) {}
    ~ShoppingList() override = default;

    void registerObserver(Observer* o) override;

    void removeObserver(Observer* o) override;

    void notify() override;

    void addArticle(const ShoppingItem& newArticle);

    void removeArticle(const ShoppingItem& toDelete);

    void buyItem(ShoppingItem toBuy);

    void unBuyItem(ShoppingItem toUnBuy);

    const string &getListName() const {
        return listName;
    }

    void setListName(const string &c) {
        this->listName = c;
    }

    bool isListName() const {
        if (this->getListName().empty())
            return false;
        else
            return true;
    }

    size_t getShoppingListSize() const {
        return spesaList.size();
    }

    size_t getUsersNumber() const {
        return users.size();
    }

private:
    vector<ShoppingItem> spesaList;
    list<Observer*> users;
    string listName;
};

#endif //MARKETLIST_SHOPPINGLIST_H
