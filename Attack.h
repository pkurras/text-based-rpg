#ifndef ATTACK_H
#define ATTACK_H

#include "Character.h"

class Attack {
public:
    float baseDmg;
    float modifier;
    float critChance;
    Character* source;

    float computeDmg() {
        // TODO - Compute Damage
    }
};

#endif