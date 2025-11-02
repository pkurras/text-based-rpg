#include "Boss.h"

Boss::Boss(const string n,int level)
    : Character(n, level, bossHp(level), bossHp(level), bossAtk(level), bossDef(level)) { expDrop = expDropBossFormula(level); }

void Boss::setHp() { maxHp = bossHp(level); hp = bossHp(level); }

void Boss::setAtk() { atk = bossAtk(level); }

void Boss::setDef() { def = bossDef(level); }