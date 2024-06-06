#pragma once

#include "scenes/Scene.h"
#include <memory>

class SceneManager {
public:
    SceneManager() { }
    ~SceneManager() { 
        Cleanup();
    }

    void SetScene(std::unique_ptr<Scene> scene)
    {
        m_CurrentScene = std::move(scene);
    }

    Scene* GetCurrentScene() const
    {
        return m_CurrentScene.get();
    }

    void Init()
    {
        m_CurrentScene->Init();
    }

    void Update(float deltaTime)
    {
        m_CurrentScene->Update(deltaTime);
    }

    void Render()
    {
        m_CurrentScene->Render();
    }

    void Cleanup()
    {
        // Don't cleanup the current scene, because it will be deleted automatically by the unique_ptr
        // if (m_CurrentScene != nullptr) {
        //     m_CurrentScene->Cleanup();
        // }
    }

private:
    std::unique_ptr<Scene> m_CurrentScene;
};
