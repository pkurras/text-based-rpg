#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(const string n,int lvl);

    void setHp() override;
    void setAtk() override;
    void setDef() override;
};

#endif