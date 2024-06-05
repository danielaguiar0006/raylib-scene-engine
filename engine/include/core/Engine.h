#pragma once

#include "SceneManager.h"
#include "WindowManager.h"
#include "graphics/Renderer.h"
#include <memory>

class Engine {
public:
    // Delete the copy constructor and assignment operator to prevent copying
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    // TODO: docs
    static Engine& GetInstance(); // provide a global access point to the instance
    void Run();

private:
    Engine();
    ~Engine();

    void Init();
    void Update();
    void Render();
    void Cleanup();

    std::unique_ptr<WindowManager> windowManager;
    std::unique_ptr<SceneManager> sceneManager;
    std::unique_ptr<Renderer> renderer;
};
