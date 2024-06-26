#pragma once

#include "SceneManager.h"
#include "WindowManager.h"
#include <memory>

// Singelton class
class Engine {
  public:
    // Delete the copy constructor and assignment operator to prevent copying
    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;

    // TODO: docs
    static Engine &
    GetInstance(); // provide a global access point to the instance

    WindowManager &GetWindowManager() { return *m_WindowManager; }
    SceneManager &GetSceneManager() { return *m_SceneManager; }

    void Run();

  private:
    Engine();
    ~Engine();

    void Init();
    void Update();
    void Render();
    void Cleanup();

    std::unique_ptr<WindowManager> m_WindowManager;
    std::unique_ptr<SceneManager> m_SceneManager;
};
