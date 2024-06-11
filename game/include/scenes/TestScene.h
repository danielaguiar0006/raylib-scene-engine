#pragma once

#include "scenes/Scene.h"

class TestScene : public Scene {
  public:
    // TestScene() = default;
    TestScene();
    ~TestScene() override;

    void Init() override;
    void Update(float deltaTime) override;
    void Render() override;
    void Cleanup() override;

  private:
    Vector3 m_CubePosition = {0.0f, 0.0f, 0.0f};
    Vector2 m_CubeScreenPosition = {0.0f, 0.0f};
};
