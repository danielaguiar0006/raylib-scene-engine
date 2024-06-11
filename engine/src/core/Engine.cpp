#include "core/Engine.h"
#include "core/GameCallbacks.h"
#include <raylib.h>
// #include "scenes/Scene.h"

// Singleton instance
Engine &Engine::GetInstance() {
    static Engine instance;
    return instance;
}

Engine::Engine()
    : m_WindowManager(std::make_unique<WindowManager>()),
      m_SceneManager(std::make_unique<SceneManager>()) {}

Engine::~Engine() { Cleanup(); }

void Engine::Init() {
    // Setup Raylib window - ! IMPORTANT: This must be called before any other
    // raylib functions
    m_WindowManager->Init(1280, 720, "Test Game");

    GameInit();
    m_SceneManager->Init();
    // sceneManager->SetScene(Scene::Creat(Scene::SceneType::MainMenu));
}

void Engine::Run() {
    // Init called here to avoid Engine::GetInstance() constructor problems
    Init();

    while (!WindowShouldClose()) {
        Update();
        Render();
    }
}

void Engine::Update() {
    float deltaTime = GetFrameTime();
    GameUpdate(deltaTime);
    m_SceneManager->Update(deltaTime);
}

void Engine::Render() {
    GameRender();
    m_SceneManager->Render();
}

void Engine::Cleanup() {
    // These are already cleaned up in their respective destructors because they
    // are smart pointers m_SceneManager->Cleanup(); m_Renderer->Cleanup();
}
