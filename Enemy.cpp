#include "Enemy.h"

Enemy::Enemy(const string n,int level)
    : Character(n, level, enemyHp(level), enemyHp(level), enemyAtk(level), enemyDef(level)) {};

void Enemy::setHp() { maxHp = enemyHp(level); hp = enemyHp(level); }

void Enemy::setAtk() { atk = enemyAtk(level); }

void Enemy::setDef() { def = enemyDef(level); }