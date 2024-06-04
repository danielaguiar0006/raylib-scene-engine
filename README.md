# raylib-scene-engine
Scene based game engine built on top of raylib. (C++)

## Game Architecture Overview
Core Components

    Game: Manages the overall game state, including initialization, running the game loop, cleanup, and holding unique pointers to the Renderer and SceneManager.
    SceneManager: Manages different scenes, handles transitions between scenes, and updates the current scene.

Graphics Component

    Renderer: Responsible for rendering the current scene.

Entities Component

    Entity: Base class for all game entities. Each entity has methods for initialization, updating, rendering, and cleanup.
    Player: Inherits from Entity and includes player-specific properties and behaviors.

Scenes Component

    Scene: Abstract base class for all scenes, supporting nested scenes and entities. Scenes handle their own initialization, updating, rendering, and cleanup.
    MenuScene: A specific scene that represents the main menu of the game.
    GameScene: A specific scene that represents the main gameplay area, including player interactions.

How Everything Connects

    Game Initialization:
        The Game class is a singleton and is responsible for initializing the game components. It creates unique pointers to the Renderer and SceneManager.

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
        Game::Init() initializes the Renderer and SceneManager. The initial scene (e.g., MenuScene) is set using SceneManager::SetScene().

    Running the Game:
        Game::Run() starts the main game loop, which continues until the window should close. In each iteration, Update() and Render() methods are called.

    Updating:
        Game::Update() calls SceneManager::Update(), which in turn calls Update() on the current scene. Each scene updates its entities and nested scenes.

    Rendering:
        Game::Render() retrieves the current scene from the SceneManager using SceneManager::GetCurrentScene() and passes it to Renderer::Render(), which then calls the Render() method on the scene to draw all its entities and nested scenes.

    Scene Transitions:
        The SceneManager handles transitions between scenes. When a scene transition is needed (e.g., switching from MenuScene to GameScene), SceneManager::SetScene() is called with a new scene. The current scene is cleaned up, and the new scene is initialized.

    Entity and Scene Management:
        Entities are added to scenes using Scene::AddEntity(), and nested scenes are added using Scene::AddSubScene(). Each scene manages its own entities and nested scenes, ensuring they are updated and rendered appropriately.

