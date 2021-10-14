//
// Created by fraer on 21/09/2021.
//

#ifndef MARKETLIST_SHOPPINGLIST_H
#define MARKETLIST_SHOPPINGLIST_H

#include <list>
#include <map>
#include <algorithm>
#include "ShoppingItem.h"
#include "Subject.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(string listName = "") : listName(move(listName)) {}
    ~ShoppingList() override = default;

    string toString() const;

    void registerObserver(Observer* o) override;

    void removeObserver(Observer* o) override;

    void notify() override;

    bool addArticle(const ShoppingItem& newArticle);

    void removeArticle(const ShoppingItem& toDelete);

    void buyChangeState(const ShoppingItem& toChange);

    float getTotalListPrice() const;

    size_t getShoppingListSize() const {
        return spesaList.size();
    }

    size_t getUsersNumber() const {
        return users.size();
    }

    int getBoughtItems() const;

    int getUnboughtItems() const;

    const string &getListName() const {
        return listName;
    }

    void setListName(const string &c) {
        this->listName = c;
    }

    bool isListName() const;

private:
    multimap<string,ShoppingItem> spesaList;
    list<Observer*> users;
    string listName;
};

#endif //MARKETLIST_SHOPPINGLIST_H
