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
    m_WindowManager->Init(1280, 720, "Test Game");


    // renderer->Init();
    // sceneManager->SetScene(Scene::Creat(Scene::SceneType::MainMenu));
}

void Engine::Run()
{
    // TODO: Maybe move Engine.Init() here???

    // Setup game - Called here to avoid recursive calls to Engine::GetInstance()
    GameInit();
    m_SceneManager->Init();

    while (!WindowShouldClose()) {
        Update();
        Render();
    }
}

void Engine::Update()
{
    float deltaTime = GetFrameTime();
    GameUpdate(deltaTime);
    m_SceneManager->Update(deltaTime);
}

void Engine::Render()
{
    GameRender();
    //m_Renderer->Render();  TODO: figure out if I even want a "renderer" class instead of having the scene render itself
    m_SceneManager->Render();
}

void Engine::Cleanup()
{
    // These are already cleaned up in their respective destructors because they are smart pointers
    // sceneManager->Cleanup();
    // renderer->Cleanup();
    // windowManager->Cleanup();
}
