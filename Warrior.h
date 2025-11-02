#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
public:
    Warrior(const string& n,int lvl);

    void setHp() override;
    void setAtk() override;
    void setDef() override;
};

#endif