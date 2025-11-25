// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "character.h"
#include "combat.h"
#include "helperutils.h"

int main(int argc, char** argv)
{
    std::string jack_str = std::string("Jack");
    Character A(jack_str);

    PropertySet& a_props = A.GetPropertySet();
    a_props.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
    a_props.set("health", Range<float>(0.0f, 100.0f, 100.0f));
    a_props.set("strength", 10.0f);
    a_props.set("dexterity", 10.0f);
    a_props.set("level", 1);

    A.SetAction(Character::CharacterActions::Attack, [](int level) -> float { return 5 * level + 30;  });

    std::string jim_str = std::string("Jim");
    Character B(jim_str);

    PropertySet& b_props = B.GetPropertySet();
    b_props.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
    b_props.set("health", Range<float>(0.0f, 100.0f, 100.0f));
    b_props.set("strength", 10.0f);
    b_props.set("dexterity", 10.0f);
    a_props.set("level", 1);

    Combat::Attack(A, B);

    return 0;
}
