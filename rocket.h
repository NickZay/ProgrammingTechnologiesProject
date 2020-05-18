#ifndef ROCKET_H
#define ROCKET_H

#include "unit.h"


class Rocket: public Unit {
public:
    Rocket();
    void go() override ;
    void shoot(Visitor *v, Observer* obs) override ;
    Rocket* clone() const override ;
};

#endif
