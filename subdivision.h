#ifndef SUBDIVISION_H
#define SUBDIVISION_H

#include "army.h"
#include "artillery_adapter.h"
#include "observer.h"


class Subdivision {
    vector<Subdivision*> subordinated_subdivisions;
    vector<Unit*> subordinated_units;
    vector<Artillery*> subordinated_guns_only;

public:
    Subdivision(Army* army);
    Subdivision() = default;

    void add_unit(Unit* unit);
    void add_artillery(Artillery* unit);

    void divide();

    void shoot_all(Observer* observer);
    void go_all();
    void transform_all_guns();
    vector<Unit*> get_all_units();

    ~Subdivision();
};

#endif
