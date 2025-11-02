#include "Skill.h"

Skill::Skill(bool magic, bool attack, bool group, bool multi, float p, float c)
    : isMagic(magic), attackSkill(attack), groupAttack(group), multiHit(multi), points(p), cost(c) {}

bool Skill::getIsMagic() const { return isMagic; }
bool Skill::getAttackSkill() const { return attackSkill; }
bool Skill::getGroupAttack() const { return groupAttack; }
bool Skill::getMultiHit() const { return multiHit; }
float Skill::getPoints() const { return points; }
float Skill::getCost() const { return cost; }