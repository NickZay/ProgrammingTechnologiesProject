#include <vector>
#include "army.h"

vector<Infantry*> Army::get_infantry() {
    return infantry;
}

vector<Tank*> Army::get_tanks() {
    return tanks;
}

vector<Artillery*> Army::get_artillery() {
    return artillery;
}

vector<Rocket*> Army::get_rockets() {
    return rockets;
}

void Army::add_soldiers(vector<Infantry*> added) {
    for (auto soldier: added){
        infantry.push_back(soldier);
    }
}

void Army::add_tank(vector<Tank*> added) {
    for (auto tank: added){
        tanks.push_back(tank);
    }
}

void Army::add_artillery(vector<Artillery*> added) {
    for (auto artillery_unit: added){
        artillery.push_back(artillery_unit);
    }
}

Army::~Army() {
    infantry.clear();
    tanks.clear();
    artillery.clear();
    rockets.clear();
}

bool operator ==(const Army& a, const Army& b) {
    if (a.infantry.size() != b.infantry.size() || a.tanks.size() != b.tanks.size() ||
        a.artillery.size() != b.artillery.size()) {
        return false;
    }

    for (int i = 0; i < a.infantry.size(); ++i){
        if ((*a.infantry[i]) != (*b.infantry[i])) {
            return false;
        }
    }

    for (int i = 0; i < a.tanks.size(); ++i){
        if ((*a.tanks[i]) != (*b.tanks[i])) {
            return false;
        }
    }

    for (int i = 0; i < a.artillery.size(); ++i){
        if ((*a.artillery[i]) != (*b.artillery[i])) {
            return false;
        }
    }
    return true;
}

