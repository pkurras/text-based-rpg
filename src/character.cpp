// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "character.h"

// ********************************************************************************
Character::Character(const char* name) :
    name(name)
{
    actions.resize(static_cast<size_t>(CharacterFormulas::MAX));
}
// ********************************************************************************
Character::~Character()
{ }
// ********************************************************************************
std::string& Character::GetName(void)
{
    return name;
}
// ********************************************************************************
PropertySet& Character::GetPropertySet(void)
{
    return stats;
}
// ********************************************************************************
void Character::SetFormula(CharacterFormulas slot, formula_cb_t formula)
{
    actions[static_cast<size_t>(slot)] = formula;
}
// ********************************************************************************
formula_cb_t Character::GetAction(CharacterFormulas slot)
{
    size_t idx = static_cast<size_t>(slot);
    if (idx >= static_cast<size_t>(CharacterFormulas::MAX))
    {
        return nullptr;
    }

    return actions[idx];
}
// ********************************************************************************
