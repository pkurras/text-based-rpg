#ifndef ARCHETYPE_H
#define ARCHETYPE_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "character.h"
#include "helperutils.h"

class Archetype
{
public:

	static Character* CreateArcher(const char* name);
	static Character* CreateMage(const char* name);
	static Character* CreateHealer(const char* name);
	static Character* CreateWarrior(const char* name);

};

#endif // ARCHETYPE_H