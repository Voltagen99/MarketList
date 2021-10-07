//
// Created by fraer on 21/09/2021.
//

#ifndef MARKETLIST_SHOPPINGLIST_H
#define MARKETLIST_SHOPPINGLIST_H

#include <list>
#include <utility>
#include <vector>
#include <algorithm>
#include <exception>
#include "ShoppingItem.h"
#include "Subject.h"
#define MAX_SIZE 50

class ShoppingList : public Subject {
public:
    explicit ShoppingList(string listName = "") : listName(move(listName)) {}
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
    }

    void removeArticle(const ShoppingItem& toDelete) {
        vector<ShoppingItem>::iterator it;
        it = find(spesaList.begin(), spesaList.end(), toDelete);
        if (it != spesaList.end()) {
            spesaList.erase(it);
            notify();
        }
        // TODO Change vector to multimap (delete by searching the name)
    }

    void printList() {
        if (this->getListName().empty())
            cout << "---Market List:" << endl;
        else
            cout << "---" << this->getListName() << " List: " << endl;
        int i = 1;
        for (ShoppingItem &it : spesaList) {
            cout << "---" << i << ") ";
            it.displayItem();
            i++;
        }
    }

    // TODO Add function to tell that article has been bought

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
    // TODO Move methods to cpp file for each class
};

#endif //MARKETLIST_SHOPPINGLIST_H
