#pragma once

#include "entities/Entity.h"
#include <memory>
#include <vector>

class Scene {
public:
    Scene() { }
    virtual ~Scene() { }

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    void AddScene(Scene* scene);
    void RemoveScene(Scene* scene);

protected:
    std::vector<std::unique_ptr<Entity>> m_Entities;
    std::vector<std::unique_ptr<Scene>> m_SubScenes;
};
