// #include "raylib.h"
#include "core/Engine.h"

// #define RAYGUI_IMPLEMENTATION
#include "core/GameCallbacks.h"
#include "raygui.h"

void GameInit()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------
}

void GameUpdate()
{
    // Update
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
}

void GameRender()
{
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

void GameCleanup()
{
    // De-Initialization
    //--------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------
}

int main()
{
    Engine& engine = Engine::GetInstance();

    // Needs to be done before the engine is initialized for now
    // engine.SetWindowTitle("Test Game"); 
    // engine.SetWindowWidth(100);
    // engine.SetWindowHeight(100);

    engine.Run();
    return 0;
}
