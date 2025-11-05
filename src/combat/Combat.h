#ifndef COMBAT_H
#define COMBAT_H

#include "character/Character.h"
#include <iostream>

struct Combat {
    Character* player;
    Character* enemy;
    int turnCount;

    Combat(Character* player, Character* e);

    void printInfo() const;
    void endInfo(Character* p, Character* e) const;

    // each turn returns the skill the player or the enemy picks for that turn
    Skill& playerChoice();
    Skill& enemyChoice();

    bool combatLoop();
};

#endif