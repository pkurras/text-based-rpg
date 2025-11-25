#ifndef CHARACTER_H
#define CHARACTER_H

// EXTERNAL INCLUDES
#include <string>
#include <unordered_map>
// INTERNAL INCLUDES
#include "propertyset.h"

typedef float(*action_cb_t)(int level);

class Character
{
public:

    enum class CharacterActions
    {
        Attack,
        Heal,
        MAX
    };

    Character(std::string& name) :
        name(name)
    {
        actions.resize(static_cast<size_t>(CharacterActions::MAX));
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
    void SetAction(CharacterActions slot, action_cb_t action)
    {
        actions[static_cast<size_t>(slot)] = action;
    }
    action_cb_t GetAction(CharacterActions slot)
    {
        size_t idx = static_cast<size_t>(slot);
        if (idx >= static_cast<size_t>(CharacterActions::MAX))
        {
            return nullptr;
        }

        return actions[idx];
    }

private:

    std::string name;
    PropertySet stats;

    std::vector<action_cb_t> actions;

};

#endif // CHARACTER_H