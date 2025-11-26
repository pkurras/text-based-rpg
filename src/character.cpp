// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "character.h"

// ********************************************************************************
Character::Character(const char* name) :
    name(name)
{
    actions.resize(static_cast<size_t>(Formula::MAX));
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
void Character::SetFormula(Formula slot, formula_cb_t formula)
{
    actions[static_cast<size_t>(slot)] = formula;
}
// ********************************************************************************
formula_cb_t Character::GetAction(Formula slot)
{
    size_t idx = static_cast<size_t>(slot);
    if (idx >= static_cast<size_t>(Formula::MAX))
    {
        return nullptr;
    }

    return actions[idx];
}
// ********************************************************************************
