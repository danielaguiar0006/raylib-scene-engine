#pragma once

#include "graphics/Renderer.h"
#include "SceneManager.h"
#include <memory>

class Game {
public:
    // Delete the copy constructor and assignment operator to prevent copying
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    // TODO: docs
    static Game& GetInstance(); // provide a global access point to the instance
    void Run();

private:
    Game();
    ~Game();

    void Init();
    void Update();
    void Render();
    void Cleanup();

    std::unique_ptr<SceneManager> sceneManager;
    std::unique_ptr<Renderer> renderer;
};
