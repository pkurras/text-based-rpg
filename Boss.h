#ifndef BOSS_H
#define BOSS_H

#include "Character.h"

class Boss : public Character {
public:
    Boss(const string n,int lvl);

    void setHp() override;
    void setAtk() override;
    void setDef() override;
};

#endif