#ifndef COMBAT_H
#define COMBAT_H

// EXTERNAL INCLUDES
#include <iostream>
// INTERNAL INCLUDES
#include "character.h"
#include "helperutils.h"
#include "platform/console.h"

class CombatSystem
{
public:
	static void Attack(Character& a, Character& b);
};

#endif // COMBAT_H
