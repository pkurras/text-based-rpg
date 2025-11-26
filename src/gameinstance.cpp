// EXTERNAL INCLUDES
#include <memory>
// INTERNAL INCLUDES
#include "archetype.h"
#include "character.h"
#include "combat.h"
#include "gameinstance.h"
#include "mt19937.h"
#include "party.h"
#include "platform/console.h"
#include "platform/random.h"

// ********************************************************************************
void GameInstance::Init() const
{
    mt_seed(Random::GetTrueRandomNumber());
}
// ********************************************************************************
void GameInstance::Exec() const
{
    std::unique_ptr<Character> A{ Archetype::CreateWarrior("Warrior") };
    std::unique_ptr<Character> B{ Archetype::CreateMage("Mage") };

    Party party(2);
    party.AddMember(A.get());
    party.AddMember(B.get());

    Console::SetColor(Console::Color::Yellow);
    std::printf("===== GAME STARTED =====\n");
    Console::SetColor(Console::Color::Default);

    bool running = true;
    while (running)
    {
        std::printf("\nChoose an option:\n");
        for (int i = 0; i < Option::OPT_MAX-1; i++)
        {
            std::printf("%i. %s\n", i+1, OptionNames[i]);
        }
        std::printf("\n");

        std::string option;
        std::getline(std::cin, option);

        Console::Clear();

        switch (std::atoi(option.c_str()))
        {
            case Option::OPT_FIGHT:
            {
                CombatSystem::Attack(*A, *B);
                break;
            }
            case Option::OPT_PARTY_INFO:
            {
                party.Print();
                break;
            }
            case Option::OPT_QUIT:
            {
                running = false;
                break;
            }
            default:
            {
                Console::SetColor(Console::Color::Red);
                std::printf("Invalid option.\n");
                Console::SetColor(Console::Color::Default);
                break;
            }
        }
    }

    Console::SetColor(Console::Color::Yellow);
    std::printf("===== GAME OVER =====\n");
    Console::SetColor(Console::Color::Default);
}
// ********************************************************************************
void GameInstance::Quit() const
{

}
// ********************************************************************************