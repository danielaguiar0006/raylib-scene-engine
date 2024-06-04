// #include "raylib.h"
#include "core/Engine.h"

// #define RAYGUI_IMPLEMENTATION
#include "core/GameCallbacks.h"
#include "raygui.h"
//
void GameInit()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Test Game");

    SetTargetFPS(144); // Set our game to run at 60 frames-per-second
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
    engine.Run();
    return 0;
}
