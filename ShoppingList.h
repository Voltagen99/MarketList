//
// Created by fraer on 21/09/2021.
//

#ifndef MARKETLIST_SHOPPINGLIST_H
#define MARKETLIST_SHOPPINGLIST_H

#include <list>
#include <vector>
#include <algorithm>
#include <exception>
#include "ShoppingItem.h"
#include "Subject.h"
#define MAX_SIZE 50

class ShoppingList : public Subject {
public:
    explicit ShoppingList(string category = "") : category(move(category)) {}
    ~ShoppingList() override = default;

    void registerObserver(Observer* o) override {
        users.emplace_back(o);
    }

    void removeObserver(Observer* o) override {
        users.remove(o);
    }

    void notify() override {
        for(const auto & it : users)
            it->update();
    }

    void addArticle(const ShoppingItem& newArticle) {
        bool match = false;
        if (newArticle.getCategory() == ShoppingList::getListCategory() &&
        spesaList.size() <= MAX_SIZE) {
            spesaList.emplace_back(newArticle);
            match = true;
        }
        else {
            if (ShoppingList::getListCategory().empty()) {
                spesaList.emplace_back(newArticle);
                match = true;
            }
        }
        if (match)
            notify();
    }

    void removeArticle(const ShoppingItem& toDelete) {
        vector<ShoppingItem>::iterator it;
        it = find(spesaList.begin(), spesaList.end(), toDelete);
        if (it != spesaList.end()) {
            spesaList.erase(it);
            notify();
        }
    }

    void printList() {
        if (this->getListCategory().empty())
            cout << "---Market List:" << endl;
        else
            cout << "---" << this->getListCategory() << " List: " << endl;
        int i = 1;
        for (ShoppingItem &it : spesaList) {
            cout << "---" << i << ") ";
            it.displayItem();
            i++;
        }
    }

    const string &getListCategory() const {
        return category;
    }

    void setListCategory(const string &c) {
        this->category = c;
    }

    void setShoppingListSize(size_t i) {
        if (i > 0)
           spesaList.reserve(i);
        else
            throw length_error("ERROR! Invalid list size.");
    }

    size_t getShoppingListSize() const {
        return spesaList.size();
    }

private:
    vector<ShoppingItem> spesaList;
    list<Observer*> users;
    string category;
};

#endif //MARKETLIST_SHOPPINGLIST_H
