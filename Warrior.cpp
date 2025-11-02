#include "Warrior.h"

Warrior::Warrior(const string& n,int level)
    : Character(n, level, warriorHp(level), warriorHp(level), warriorAtk(level), warriorDef(level)) {};

void Warrior::setHp() { maxHp = warriorHp(level); hp = warriorHp(level); }

void Warrior::setAtk() {atk = warriorAtk(level); }

void Warrior::setDef() {def = warriorDef(level); }