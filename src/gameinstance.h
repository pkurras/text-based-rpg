#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES

enum Option
{
    OPT_FIGHT = 1,
    OPT_QUIT,
    OPT_MAX
};

static const char* OptionNames[] =
{
    "Fight",
    "Quit",
    "N/A"
};

class GameInstance
{
public:

    void Init();
    void Run();
    void Quit();
};

#endif // GAMEINSTANCE_H
