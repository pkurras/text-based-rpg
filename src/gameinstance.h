#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

// EXTERNAL INCLUDES
#include <string>
// INTERNAL INCLUDES
#include "archetype.h"
#include "character.h"
#include "combat.h"
#include "helperutils.h"
#include "mt19937.h"
#include "party.h"
#include "platform/console.h"
#include "platform/random.h"
#include "singleton.h"

enum Option
{
    OPT_FIGHT = 1,
    OPT_QUIT
};

class GameInstance
{
public:

    void Init()
    {
        mt_seed(Random::GetTrueRandomNumber());
    }
    void Run()
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
            std::printf("Choose an option:\n");
            std::printf("1. Fight\n");
            std::printf("3. Quit\n");

            std::string option;
            std::getline(std::cin, option);

            int opt = std::atoi(option.c_str());

            switch (opt)
            {
                case Option::OPT_FIGHT:
                {
                    CombatSystem::Attack(*A, *B);
                    break;
                }
                case Option::OPT_QUIT:
                {
                    Console::SetColor(Console::Color::Yellow);
                    std::printf("===== GAME OVER =====\n");
                    Console::SetColor(Console::Color::Default);
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
    }
    void Quit()
    {

    }
};

#endif // GAMEINSTANCE_H
