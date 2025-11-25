#ifndef PARTY_H
#define PARTY_H

// EXTERNAL INCLUDES
#include <vector>
#include <memory>
// INTERNAL INCLUDES
#include "character.h"
#include "helperutils.h"
#include "print.h"

class Party : public PrintInfo
{
public:

	Party(size_t max_size)
	{
		this->members.resize(max_size);
	}
	~Party() { }

	bool IsMember(const char* Name)
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
	bool IsMember(Character* character)
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

	bool AllMembersAlive()
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

	size_t GetMaxMemberCount()
	{
		return this->members.capacity();
	}

	bool IsAlive(Character* character)
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

	void AddMember(Character* character)
	{
		this->members.emplace_back(character);
	}

	virtual void Print() override
	{
		printf("Party Members:\n");
		for (auto& m : this->members)
		{
			if (!m) continue;
			printf(" %s\n", m->GetName().c_str());
		}
	}

private:

	std::vector<Character*> members;

};

#endif // PARTY_H