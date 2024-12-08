//
// Created by lucaberto on 30/11/24.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include "Observer.h"

class Function : public Observer {
public:
    ~Function() override = default;

    void update() override;

    virtual void compute() = 0;
};

#endif //FUNCTION_H
