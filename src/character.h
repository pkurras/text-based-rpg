#ifndef CHARACTER_H
#define CHARACTER_H

// EXTERNAL INCLUDES
#include <string>
#include <unordered_map>
// INTERNAL INCLUDES
#include "propertyset.h"

typedef float(*formula_cb_t)(int level);

class Character
{
public:

    enum class CharacterFormulas
    {
        NextLevel,
        DropChance,
        DropBossChance,
        Attack,
        Defense,
        Resistance,
        MAX
    };

    Character(const char* name) :
        name(name)
    {
        actions.resize(static_cast<size_t>(CharacterFormulas::MAX));
    }
    ~Character() {}

    std::string& GetName(void)
    {
        return name;
    }
    PropertySet& GetPropertySet(void)
    {
        return stats;
    }
    void SetFormula(CharacterFormulas slot, formula_cb_t formula)
    {
        actions[static_cast<size_t>(slot)] = formula;
    }
    formula_cb_t GetAction(CharacterFormulas slot)
    {
        size_t idx = static_cast<size_t>(slot);
        if (idx >= static_cast<size_t>(CharacterFormulas::MAX))
        {
            return nullptr;
        }

        return actions[idx];
    }

private:

    std::string name;
    PropertySet stats;

    std::vector<formula_cb_t> actions;

};

#endif // CHARACTER_H