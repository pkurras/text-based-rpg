#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES

enum Option
{
    OPT_FIGHT = 1,
    OPT_PARTY_INFO,
    OPT_QUIT,
    OPT_MAX
};

static const char* OptionNames[] =
{
    "Fight",
    "Party Info",
    "Quit",
    "N/A"
};

class GameInstance
{
public:
    void Init() const;
    void Exec() const;
    void Quit() const;
};

#endif // GAMEINSTANCE_H
