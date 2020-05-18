#include "rocket.h"

Rocket::Rocket(){
    lives = LIVES_DEFAULT * 2;
    gun_power = ARTILLERY_DEFAULT * 2;
}

void Rocket::go(){
    x = rand() % (GAME_FIELD_SIZE + 1);
    y = rand() % (GAME_FIELD_SIZE + 1);
}

void Rocket::shoot(Visitor *v, Observer* obs){
    v->shootRocket(this, obs);
}

Rocket* Rocket::clone() const{
    return new Rocket(*this);
}