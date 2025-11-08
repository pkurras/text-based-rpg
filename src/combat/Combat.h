#ifndef COMBAT_H
#define COMBAT_H

#include "Character/Character.h"
#include "Party.h"
#include <iostream>

struct Combat {
    Party playerParty;
    Party enemyParty;
    int turnCount;

    Combat(Party player, Party enemy);

    void printTurn() const;
    void endInfo(Party player, Party enemy) const;
    void battleStart() const;

    // each turn returns the skill the player or the enemy picks for that turn
    Skill* playerChoice();
    Skill* enemyChoice();

    bool combatLoop();
};

#endif