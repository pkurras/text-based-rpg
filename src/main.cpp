// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "character.h"
#include "combat.h"
#include "helperutils.h"

int main(int argc, char** argv)
{
    Character A("Jack");
    PropertySet& a_props = A.GetPropertySet();
    a_props.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
    a_props.set("hp", Range<float>(0.0f, 100.0f, 100.0f));
    a_props.set("str", 10.0f);
    a_props.set("dex", 10.0f);
    a_props.set("lvl", 1);

    A.SetFormula(Character::CharacterFormulas::Attack, [](int level) -> float { return 5 * level + 30;  });

    Character B("Jim");
    PropertySet& b_props = B.GetPropertySet();
    b_props.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
    b_props.set("hp", Range<float>(0.0f, 100.0f, 100.0f));
    b_props.set("str", 10.0f);
    b_props.set("dex", 10.0f);
    a_props.set("lvl", 1);

    CombatSystem::Attack(A, B);

    return 0;
}
