#include "scenes/Scene.h"

void Scene::AddEntity(Entity* entity)
{
    m_Entities.push_back(std::unique_ptr<Entity>(entity));
}

void Scene::RemoveEntity(Entity* entity)
{
    for (auto it = m_Entities.begin(); it != m_Entities.end(); ++it) {
        if (it->get() == entity) {
            m_Entities.erase(it);
            break;
        }
    }
}

void Scene::AddScene(Scene* scene)
{
    m_SubScenes.push_back(std::unique_ptr<Scene>(scene));
}

void Scene::RemoveScene(Scene* scene)
{
    for (auto it = m_SubScenes.begin(); it != m_SubScenes.end(); ++it) {
        if (it->get() == scene) {
            m_SubScenes.erase(it);
            break;
        }
    }
}
