#pragma once

#include "entities/Entity.h"
#include <memory>
#include <vector>

class Scene {
  public:
    Scene() {}
    virtual ~Scene() {}

    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;

    void AddEntity(Entity *entity);
    void RemoveEntity(Entity *entity);
    void AddScene(Scene *scene);
    void RemoveScene(Scene *scene);

    size_t GetEntityCount() const { return m_Entities.size(); }
    size_t GetSubSceneCount() const { return m_SubScenes.size(); }
    Entity *GetEntity(size_t index) { return m_Entities[index].get(); }
    Scene *GetSubScene(size_t index) { return m_SubScenes[index].get(); }

  protected:
    std::vector<std::unique_ptr<Entity>> m_Entities;
    std::vector<std::unique_ptr<Scene>> m_SubScenes;

    Camera3D m_Camera = {0};
    Vector3 m_LocalPosition = {0};
    Vector3 m_GlobalPosition = {0};
};
