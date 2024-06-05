#pragma once

#include "scenes/Scene.h"
#include <memory>

class SceneManager {
public:
    SceneManager() { }
    ~SceneManager() { }

    void SetScene(std::unique_ptr<Scene> scene)
    {
        // currentScene = std::move(scene);
    }

    Scene* GetCurrentScene()
    {
        // return currentScene.get();
    }

    void Update()
    {
        // Update the current scene
    }

    void Cleanup()
    {
        // Cleanup the current scene
    }

private:
    std::unique_ptr<Scene> m_CurrentScene;
};
