#ifndef SKILL_H
#define SKILL_H

class Skill {
private:
    bool isMagic;
    bool attackSkill;
    bool groupAttack;
    bool multiHit;
    float points;
    float cost;
public:
    // constructor / destructor
    Skill(bool magic, bool attack, bool group, bool multi, float p, float c);
    virtual ~Skill();

    // getters
    bool getIsMagic() const;
    bool getAttackSkill() const;
    bool getGroupAttack() const;
    bool getMultiHit() const;
    float getPoints() const;
    float getCost() const;
};

#endif