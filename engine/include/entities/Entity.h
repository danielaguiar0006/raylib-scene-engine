#pragma once

#include <raylib.h>

class Entity {
public:
    Entity();

    int GetId() const;
    Vector3 GetPosition() const;

protected:
    Vector3 m_Position;

private:
    int m_Id;
    static int s_NextId;
};
