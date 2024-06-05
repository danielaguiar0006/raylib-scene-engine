#include "core/Engine.h"
#include "core/GameCallbacks.h"
#include <raylib.h>
// #include "scenes/Scene.h"

// Singleton instance
Engine& Engine::GetInstance()
{
    static Engine instance;
    return instance;
}

Engine::Engine()
    : m_WindowManager(std::make_unique<WindowManager>())
    , m_SceneManager(std::make_unique<SceneManager>())
    , m_Renderer(std::make_unique<Renderer>())
{
    Init();
}

Engine::~Engine()
{
    Cleanup();
}

void Engine::Init()
{
    // Setup Raylib window
    m_WindowManager->Init(100, 100, "Test Game");

    // Setup game
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

    m_SceneManager->Update();
}

void Engine::Render()
{
    GameRender();
}

void Engine::Cleanup()
{
    // These are already cleaned up in their respective destructors because they are smart pointers
    // sceneManager->Cleanup();
    // renderer->Cleanup();
    // windowManager->Cleanup();
}
