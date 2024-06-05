# Raylib Scene Engine

## Overview
This project is a game engine built in C++ using the [raylib](https://www.raylib.com/) library. The engine is designed to support scene-based game development, similar to Godot, where scenes can be both regular game maps and prefabs containing entities. The `game/` directory is currently used as a test bench to validate and demonstrate the engine's capabilities.

## Features
- **Scene-Based Architecture**: The engine allows for the creation of modular scenes that can include various entities. Scenes can act as prefabs, enabling reusable game components (enables scenes within scenes).
- **Entity Management**: Easily manage and update game entities within scenes.
- **UI Styling**: Includes multiple UI styles stored under `assets/ui-styles`.

### Prerequisites
- [CMake](https://cmake.org/)
- [raylib](https://www.raylib.com/)

Ensure you have `CMake` and `raylib` installed.
Alternatively, you can auto install `raylib` by uncommenting the following lines in the `engine/CMakeLists.txt` file:
```cmake
#[[ Uncomment this block to automatically download and build raylib if it is not found

# If raylib is not found, fetch and build it
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

]]#
```

### Build Instructions

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/multiplayer-game-engine.git
    cd multiplayer-game-engine
    ```

2. Create a build directory:
    ```sh
    mkdir build
    cd build
    ```

3. Configure the project with CMake:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    make
    ```

