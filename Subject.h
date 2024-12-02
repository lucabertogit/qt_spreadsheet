//
// Created by lucaberto on 01/12/24.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() = 0;
};

#endif //SUBJECT_H
