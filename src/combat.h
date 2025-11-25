#ifndef COMBAT_H
#define COMBAT_H

// EXTERNAL INCLUDES
#include <iostream>
// INTERNAL INCLUDES
#include "character.h"
#include "helperutils.h"

class Combat
{
    public: static void Attack(Character& a, Character& b)
    {
        action_cb_t attack_action;
        if ((attack_action = a.GetAction(Character::CharacterActions::Attack)))
        {
            printf("Combat between %s and %s\n", a.GetName().c_str(), b.GetName().c_str());

            float damage = attack_action(*a.GetPropertySet().get<int>("level"));
            Range<float>* health = b.GetPropertySet().get<Range<float>>("health");
            if (!health)
            {
                printf("The attack had no effect on the victim.\n");
            }

            health->value = Clamp(health->min, health->max, health->value - damage);

            printf("%s did %.2f damage to %s.\n", a.GetName().c_str(), damage, b.GetName().c_str());
            printf("%s now has %.2f health.\n", b.GetName().c_str(), health->value);
        }
    }
};

#endif COMBAT_H