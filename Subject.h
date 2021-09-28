//
// Created by fraer on 27/09/2021.
//

#ifndef MARKETLIST_SUBJECT_H
#define MARKETLIST_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notify() = 0;
protected:
    virtual ~Subject() = default;
};


#endif //MARKETLIST_SUBJECT_H
