// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "archetype.h"

// ********************************************************************************
Character* Archetype::CreateArcher(const char* name)
{
	Character* c = new Character(name);
	auto& ps = c->GetPropertySet();
	ps.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("hp", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("def", 10.0f);
	ps.set("atk", 10.0f);
	ps.set("str", 10.0f);
	ps.set("dex", 10.0f);
	ps.set("lvl", 1);

	c->SetFormula(Character::CharacterFormulas::Attack, [](int level) -> float { return 13 + level * 3; });
	c->SetFormula(Character::CharacterFormulas::Defense, [](int level) -> float { return 7 + level * 3; });
	c->SetFormula(Character::CharacterFormulas::Resistance, [](int level) -> float { return 5 + level * 2; });

	return c;
}
// ********************************************************************************
Character* Archetype::CreateMage(const char* name)
{
	Character* c = new Character(name);
	auto& ps = c->GetPropertySet();
	ps.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("hp", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("def", 10.0f);
	ps.set("atk", 10.0f);
	ps.set("str", 10.0f);
	ps.set("dex", 10.0f);
	ps.set("lvl", 1);

	c->SetFormula(Character::CharacterFormulas::Attack, [](int level) -> float { return 9 + level * 3; });
	c->SetFormula(Character::CharacterFormulas::Defense, [](int level) -> float { return 5 + level * 2; });
	c->SetFormula(Character::CharacterFormulas::Resistance, [](int level) -> float { return 7 + level * 3; });

	return c;
}
// ********************************************************************************
Character* Archetype::CreateHealer(const char* name)
{
	Character* c = new Character(name);
	auto& ps = c->GetPropertySet();
	ps.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("hp", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("def", 10.0f);
	ps.set("atk", 10.0f);
	ps.set("str", 10.0f);
	ps.set("dex", 10.0f);
	ps.set("lvl", 1);

	c->SetFormula(Character::CharacterFormulas::Attack, [](int level) -> float { return 7 + level * 2; });
	c->SetFormula(Character::CharacterFormulas::Defense, [](int level) -> float { return 5 + level * 2; });
	c->SetFormula(Character::CharacterFormulas::Resistance, [](int level) -> float { return 9 + level * 4; });

	return c;
}
// ********************************************************************************
Character* Archetype::CreateWarrior(const char* name)
{
	Character* c = new Character(name);
	auto& ps = c->GetPropertySet();
	ps.set("mana", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("hp", Range<float>(0.0f, 100.0f, 100.0f));
	ps.set("def", 10.0f);
	ps.set("atk", 10.0f);
	ps.set("str", 10.0f);
	ps.set("dex", 10.0f);
	ps.set("lvl", 1);

	c->SetFormula(Character::CharacterFormulas::Attack, [](int level) -> float { return 15 + level * 4; });
	c->SetFormula(Character::CharacterFormulas::Defense, [](int level) -> float { return 7 + level * 3; });
	c->SetFormula(Character::CharacterFormulas::Resistance, [](int level) -> float { return 5 + level * 2; });

	return c;
}
// ********************************************************************************