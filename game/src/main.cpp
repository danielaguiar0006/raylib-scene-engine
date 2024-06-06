#include "core/Engine.h"
#define RAYGUI_IMPLEMENTATION
#include "core/GameCallbacks.h"
#include "raygui.h"
#include <raylib.h>

void GameInit()
{
    WindowManager& windowManager = Engine::GetInstance().GetWindowManager();
    windowManager.SetMaxFPS(144);
}

void GameUpdate()
{
}

void GameRender()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

void GameCleanup()
{
}

int main()
{
    Engine& engine = Engine::GetInstance();
    engine.Run();
    return 0;
}
