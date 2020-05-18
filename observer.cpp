#include "observer.h"

void Observer::add_unit(Unit* unit, bool if_soviet) {
    if (if_soviet) {
        soviet_subscribers.push_back(unit);
        closest_to_soviet.push_back(nullptr);
    } else {
        german_subscribers.push_back(unit);
        closest_to_german.push_back(nullptr);
    }
}

void Observer::remove_unit(Unit* unit, bool if_soviet) {
    if (if_soviet) {
        remove_from_vector(soviet_subscribers, closest_to_german, unit);
    } else {
        remove_from_vector(german_subscribers, closest_to_soviet, unit);
    }
}

void Observer::recalc_distances() {
    for (int i = 0; i < soviet_subscribers.size(); ++i) {
        int shortest_dist = INF;
        Unit* target = nullptr;
        for (auto & german_subscriber : german_subscribers) {
            int distance = get_dist(soviet_subscribers[i], german_subscriber);
            if (distance < shortest_dist) {
                shortest_dist = distance;
                target = german_subscriber;
            }
        }
        closest_to_soviet[i] = target;
    }
    for (int i = 0; i < german_subscribers.size(); ++i) {
        int shortest_dist = INF;
        Unit* target = nullptr;
        for (auto & soviet_subscriber : soviet_subscribers) {
            int distance = get_dist(soviet_subscriber, german_subscribers[i]);
            if (distance < shortest_dist) {
                shortest_dist = distance;
                target = soviet_subscriber;
            }
        }
        closest_to_german[i] = target;
    }
}

int Observer::get_dist(Unit* a, Unit* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

Unit* Observer::get_closest(Unit* unit) {
    if (unit->is_soviet) {
        for (int i = 0; i < soviet_subscribers.size(); ++i) {
            if (soviet_subscribers[i] == unit) {
                return closest_to_soviet[i];
            }
        }
    } else {
        for (int i = 0; i < german_subscribers.size(); ++i) {
            if (german_subscribers[i] == unit) {
                return closest_to_german[i];
            }
        }
    }
    return nullptr;
}

bool Observer::if_you_lose() {
    return soviet_subscribers.empty();
}

bool Observer::if_you_win() {
    return german_subscribers.empty();
}

Observer::~Observer() {
    soviet_subscribers.clear();
    german_subscribers.clear();
    closest_to_german.clear();
    closest_to_soviet.clear();
}

void Observer::remove_from_vector(vector<Unit*> &line, vector<Unit*> closest, Unit* unit) {
    vector<Unit*> new_vector, new_closest;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] != unit) {
            new_vector.push_back(line[i]);
            new_closest.push_back(closest[i]);
        }
    }
    line = new_vector, closest = new_closest;
    new_vector.clear(), new_closest.clear();
}