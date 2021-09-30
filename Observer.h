//
// Created by fraer on 27/09/2021.
//

#ifndef MARKETLIST_OBSERVER_H
#define MARKETLIST_OBSERVER_H

class Observer {
public:
    virtual void update() = 0;
protected:
    virtual ~Observer() = default;
};

#endif //MARKETLIST_OBSERVER_H
