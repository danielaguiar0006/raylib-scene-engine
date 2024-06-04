//#include "raylib.h"
#include "core/Game.h"

//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"

int main()
{
    Game& game = Game::GetInstance();
    game.Run();
    return 0;
}
