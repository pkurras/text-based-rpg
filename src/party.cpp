// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "party.h"

// ********************************************************************************
Party::Party(size_t max_size)
{
	this->members.resize(max_size);
}
// ********************************************************************************
Party::~Party()
{ }
// ********************************************************************************
bool Party::IsMember(const char* Name)
{
	for (auto& m : this->members)
	{
		if (!m) continue;

		if (strcmp(m->GetName().c_str(), Name) == 0)
		{
			return true;
		}
	}

	return false;
}
// ********************************************************************************
bool Party::IsMember(Character* character)
{
	for (auto& m : this->members)
	{
		if (!m) continue;

		if (strcmp(m->GetName().c_str(), character->GetName().c_str()) == 0)
		{
			return true;
		}
	}

	return false;
}
// ********************************************************************************
bool Party::AllMembersAlive()
{
	for (auto& m : this->members)
	{
		if (!m) continue;

		Range<float>* range = m->GetPropertySet().get<Range<float>>("hp");

		if (range->value <= 0)
			return false;
	}

	return true;
}
// ********************************************************************************
size_t Party::GetMaxMemberCount()
{
	return this->members.capacity();
}
// ********************************************************************************
bool Party::IsAlive(Character* character)
{
	for (auto& m : this->members)
	{
		if (!m) continue;

		std::string& name = m->GetName();
		if (strcmp(character->GetName().c_str(), name.c_str()) == 0)
		{
			Range<float>* range = character->GetPropertySet().get<Range<float>>("hp");
			if (!range)
			{
				return false;
			}

			return range->value > 0;
		}
	}

	return false;
}
// ********************************************************************************
void Party::AddMember(Character* character)
{
	this->members.emplace_back(character);
}
// ********************************************************************************
void Party::Print()
{
	std::printf("Party Members:\n");
	for (auto& m : this->members)
	{
		if (!m) continue;
		std::printf(" %s\n", m->GetName().c_str());
	}
}
// ********************************************************************************
