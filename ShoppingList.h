//
// Created by fraer on 21/09/2021.
//

#ifndef MARKETLIST_SHOPPINGLIST_H
#define MARKETLIST_SHOPPINGLIST_H

#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class ShoppingList {
public:
    ShoppingList() = default;
    ~ShoppingList() = default;

    void addArticle(const string& newArticle) {
        spesaList.push_back(newArticle);
    }

    void removeArticle(const string& toDelete) {
        for (auto it = spesaList.begin(); it != spesaList.end(); ++it)
            if (findArticle(toDelete))
                it = spesaList.erase(it);
    }

    bool findArticle(const string& toFind) {
        bool found = false;
        auto it = find(spesaList.begin(), spesaList.end(), toFind);
        if (it != spesaList.end())
            found = true;
        return found;
    }

    void printList() {
        cout << "LISTA DELLA SPESA:" << endl;
        for (const auto& it : spesaList)
            cout << it << endl;
        cout << endl;
    }


private:
    list<string> spesaList;
};


#endif //MARKETLIST_SHOPPINGLIST_H
