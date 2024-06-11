#include "scenes/TestScene.h"

TestScene::TestScene() {
    // Init();  // Already called by SceneManager
}

TestScene::~TestScene() {
    Cleanup();
    TraceLog(LOG_INFO, "TestScene succesfully destroyed");
}

void TestScene::Init() {
    // Create entities
    // Entity* entity = new Entity();
    // AddEntity(entity);

    m_Camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
    m_Camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    m_Camera.up = (Vector3){0.0f, 1.0f,
                            0.0f}; // Camera up vector (rotation towards target)
    m_Camera.fovy = 45.0f;         // Camera field-of-view Y
    m_Camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    Vector2 cubeScreenPosition = {0.0f, 0.0f};

    DisableCursor(); // Limit cursor to relative movement inside the window
    // Fps should be set by a settings scene or something
}

void TestScene::Update(float deltaTime) {
    // Update entities
    // for (auto& entity : m_Entities) {
    //     entity->Update();
    // }
    UpdateCamera(&m_Camera, CAMERA_THIRD_PERSON);

    // TODO: Create an entity, components, and entity manager

    // Calculate cube screen space position (with a little offset to be in top)
    m_CubeScreenPosition = GetWorldToScreen(
        (Vector3){m_CubePosition.x, m_CubePosition.y + 2.5f, m_CubePosition.z},
        m_Camera);
}

void TestScene::Render() {
    // Render entities
    // for (auto& entity : m_Entities) {
    //     entity->Render();
    // }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(m_Camera);

    DrawCube(m_CubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(m_CubePosition, 2.0f, 2.0f, 2.0f, MAROON);

    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("Enemy: 100 / 100",
             (int)m_CubeScreenPosition.x -
                 MeasureText("Enemy: 100/100", 20) / 2,
             (int)m_CubeScreenPosition.y, 20, BLACK);

    DrawText(TextFormat("Cube position in screen space coordinates: [%i, %i]",
                        (int)m_CubeScreenPosition.x,
                        (int)m_CubeScreenPosition.y),
             10, 10, 20, LIME);
    DrawText("Text 2d should be always on top of the cube", 10, 40, 20, GRAY);

    EndDrawing();
}

void TestScene::Cleanup() {
    // Remove entities
    // for (auto& entity : m_Entities) {
    //     RemoveEntity(entity.get());
    // }
}
