#pragma once

class Scene {
public:
    Scene() {}
    virtual ~Scene() {}

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;
};
