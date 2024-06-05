# raylib-scene-engine
Scene based game engine built on top of raylib. (C++)

## Engine Architecture Overview
Core Components

    Engine: Manages the overall game state, including initialization, running the game loop, cleanup, and holding unique pointers to the Renderer and SceneManager.
    Engine (Engine.cpp)

    Window Management: Initialize, resize, and close the window.
    Game Loop Control: Manage the main game loop, including updating game state and invoking rendering operations.
    Input Handling: Capture and process user input events.

    SceneManager: Manages different scenes, handles transitions between scenes, and updates the current scene.

Graphics Component

    Renderer: Responsible for rendering the current scene.
    Renderer (Render.cpp)

    Rendering Operations: Render entities and scenes.
    Graphics Resource Management: Load and manage textures, shaders, and other graphics resources.
    Camera Control: Handle camera transformations and viewports.

Entities Component

    Entity: Base class for all game entities. Each entity has methods for initialization, updating, rendering, and cleanup. Entities make up Scenes.
    Component: Base class for all components that can be attached to entities. Components can modify an entity's behavior or appearance.

Scenes Component

    Scene: Abstract base class for all scenes, supporting nested scenes and entities. Scenes handle their own initialization, updating, rendering, and cleanup.

How Everything Connects

    Engine Initialization:
        The Engine class is a singleton and is responsible for initializing the game components. It creates unique pointers to the Renderer and SceneManager.

    Renderer Initialization:
        The Renderer class initializes the game window using raylib and is responsible for rendering the current scene.

    Scene Management:
        The SceneManager manages the active scene, including transitioning between scenes. It holds a unique pointer to the current scene and handles its lifecycle.

    Scene Composition:
        Each Scene can contain multiple Entity objects and other nested Scene objects. This allows for a flexible, hierarchical structure similar to Godot.

    Game Loop:
        The Game class runs the main game loop, which consists of updating and rendering the current scene. The SceneManager updates and renders the current scene via the Renderer.

How Everything Works

    Initialization:
        Engine::Init() initializes the Renderer and SceneManager. The initial scene (e.g., MenuScene) is set using SceneManager::SetScene().

    Running the Game:
        Engine::Run() starts the main game loop, which continues until the window should close. In each iteration, Update() and Render() methods are called.

    Updating:
        Engine::Update() calls SceneManager::Update(), which in turn calls Update() on the current scene. Each scene updates its entities and nested scenes.

    Rendering:
        Engine::Render() retrieves the current scene from the SceneManager using SceneManager::GetCurrentScene() and passes it to Renderer::Render(), which then calls the Render() method on the scene to draw all its entities and nested scenes.

    Scene Transitions:
        The SceneManager handles transitions between scenes. When a scene transition is needed (e.g., switching from MenuScene to GameScene), SceneManager::SetScene() is called with a new scene. The current scene is cleaned up, and the new scene is initialized.

    Entity and Scene Management:
        Entities are added to scenes using Scene::AddEntity(), and nested scenes are added using Scene::AddSubScene(). Each scene manages its own entities and nested scenes, ensuring they are updated and rendered appropriately.

