// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "combat.h"

// ********************************************************************************
void CombatSystem::Attack(Character& a, Character& b)
{
    formula_cb_t attack_action;
    if ((attack_action = a.GetAction(Character::Formula::Attack)))
    {
        std::printf("Combat between %s and %s\n", a.GetName().c_str(), b.GetName().c_str());

        float damage = attack_action(*a.GetPropertySet().get<int>("lvl"));
        Range<float>* health = b.GetPropertySet().get<Range<float>>("hp");
        if (!health)
        {
            std::printf("The attack had no effect on the victim.\n");
        }

        if (health->value <= 0)
        {
            Console::SetColor(Console::Color::BrightRed);
            std::printf("%s has died already.", b.GetName().c_str());
            Console::SetColor(Console::Color::Default);
            return;
        }

        float prev_hp = health->value;

        // TODO: use defense and other factors like mt_rand64 to determine damage and final hp
        health->value = Clamp(health->min, health->max, health->value - damage);

        Console::SetColor(Console::Color::Default);
        std::printf("%s did ", a.GetName().c_str());
        Console::SetColor(Console::Color::BrightRed);
        std::printf("%.2f", prev_hp - health->value);
        Console::SetColor(Console::Color::Default);
        std::printf(" damage to %s.\n", b.GetName().c_str());
        std::printf("%s now has %.2f health.\n", b.GetName().c_str(), health->value);
    }
}
// ********************************************************************************