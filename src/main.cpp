// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "gameinstance.h"

// ********************************************************************************
int main(int argc, char** argv)
{
    GameInstance game;
    game.Init();
    game.Run();
    game.Quit();

    return 0;
}
// ********************************************************************************
