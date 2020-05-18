#include "artillery.h"

Artillery::Artillery() {
    x = 0;
    y = rand()%(GAME_FIELD_SIZE+1);
    lives = LIVES_DEFAULT;
    gun_power = ARTILLERY_DEFAULT;
}

void Artillery::shoot(Visitor *v, Observer* obs) {
    v->shootArt(this, obs);
}

void Artillery::go() {
    x = rand() % (GAME_FIELD_SIZE + 1);
    y = rand() % (GAME_FIELD_SIZE + 1);
}

Artillery* Artillery::clone() const {
    return new Artillery(*this);
}

bool operator !=(const Artillery& a, const Artillery& b) {
    return a.x != b.x || a.y != b.y;
}
