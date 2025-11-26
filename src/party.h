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

	Party(size_t max_size);
	~Party();

	bool IsMember(const char* Name);
	bool IsMember(Character* character);

	bool AllMembersAlive();
	bool IsAlive(Character* character);

	size_t GetMaxMemberCount();
	void AddMember(Character* character);
	void RemoveMember(Character* character);

	virtual void Print() override;

private:

	std::vector<Character*> members;

};

#endif // PARTY_H