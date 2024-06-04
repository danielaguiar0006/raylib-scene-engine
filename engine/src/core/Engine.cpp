#include "core/Engine.h"
#include "core/GameCallbacks.h"
// #include "scenes/Scene.h"
// #include "graphics/Renderer.h"
#include "raylib.h"

// Singleton instance
Engine& Engine::GetInstance()
{
    static Engine instance;
    return instance;
}

Engine::Engine()
    : sceneManager(std::make_unique<SceneManager>())
    , renderer(std::make_unique<Renderer>())
{
    Init();
}

Engine::~Engine()
{
    Cleanup();
}

void Engine::Init()
{
    GameInit();

    // renderer->Init();
    // sceneManager->SetScene(Scene::Creat(Scene::SceneType::MainMenu));
}

void Engine::Run()
{
    while (!WindowShouldClose()) {
        Update();
        Render();
    }
}

void Engine::Update()
{
    GameUpdate();

    sceneManager->Update();
}

void Engine::Render()
{
    GameRender();
}

void Engine::Cleanup()
{
    sceneManager->Cleanup();
    renderer->Cleanup();
    CloseWindow(); // Close window and OpenGL context
}
