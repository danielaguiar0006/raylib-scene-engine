#include "core/Engine.h"
#include <memory>
// #define RAYGUI_IMPLEMENTATION
#include "core/GameCallbacks.h"
// #include "raygui.h"
#include "scenes/TestScene.h"
#include <raylib.h>

void GameInit()
{
    Engine& engine = Engine::GetInstance();
    WindowManager& windowManager = engine.GetWindowManager();
    SceneManager& sceneManager = engine.GetSceneManager();

    windowManager.SetMaxFPS(144);
    sceneManager.SetScene(std::make_unique<TestScene>());
}

void GameUpdate(float deltaTime)
{
}

void GameRender()
{
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
