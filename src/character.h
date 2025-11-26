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

    enum class Formula
    {
        NextLevel,
        DropChance,
        DropBossChance,
        Attack,
        Defense,
        Resistance,
        MAX
    };

    Character(const char* name);
    ~Character();

    std::string& GetName(void);
    PropertySet& GetPropertySet(void);
    void SetFormula(Formula slot, formula_cb_t formula);
    formula_cb_t GetAction(Formula slot);

private:

    std::string name;
    PropertySet stats;
    std::vector<formula_cb_t> actions;

};

#endif // CHARACTER_H
