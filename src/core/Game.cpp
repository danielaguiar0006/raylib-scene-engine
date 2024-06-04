#include "core/Game.h"
// #include "scenes/Scene.h"
// #include "graphics/Renderer.h"
#include "raylib.h"

// Singleton instance
Game& Game::GetInstance()
{
    static Game instance;
    return instance;
}

Game::Game()
    : sceneManager(std::make_unique<SceneManager>())
    , renderer(std::make_unique<Renderer>())
{
    Init();
}

Game::~Game()
{
    Cleanup();
}

void Game::Init()
{
    InitWindow(800, 450, "raylib test");
    SetTargetFPS(144);
    // renderer->Init();
    // sceneManager->SetScene(Scene::Creat(Scene::SceneType::MainMenu));
}

void Game::Run()
{
    while (!WindowShouldClose()) {
        Update();
        Render();
    }
}

void Game::Update()
{
    sceneManager->Update();
}

void Game::Render()
{
    Camera2D camera = { 0 };

    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    BeginMode2D(camera);
    EndMode2D();

    // renderer->Render(sceneManager->GetCurrentScene());

    EndDrawing();
}

void Game::Cleanup()
{
    sceneManager->Cleanup();
    renderer->Cleanup();
}
