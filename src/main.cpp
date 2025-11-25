// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "character.h"
#include "combat.h"
#include "helperutils.h"
#include "party.h"
#include "archetype.h"
#include "platform/random.h"
#include "mt19937.h"

int main(int argc, char** argv)
{
    mt_seed(Platform::GetTrueRandomNumber());

    std::unique_ptr<Character> A{ Archetype::CreateWarrior("Warrior") };
    std::unique_ptr<Character> B{ Archetype::CreateMage("Mage") };

    Party party(2);
    party.AddMember(A.get());
    party.AddMember(B.get());

    party.Print();

    CombatSystem::Attack(*A, *B);

    return 0;
}
