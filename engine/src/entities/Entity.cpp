#include "entities/Entity.h"

// Initialize the next entity id
int Entity::s_NextId = 0;

Entity::Entity()
    : m_Id(s_NextId++)
    , m_Position({ 0.0f, 0.0f, 0.0f })
{
}

int Entity::GetId() const
{
    return m_Id;
}

Vector3 Entity::GetPosition() const
{
    return m_Position;
}
