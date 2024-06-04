# game/CMakeLists.txt
project(MyGame)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/engine/include)

# Recursively get all the source files
file(GLOB_RECURSE GAME_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Create the executable for the game
add_executable(${PROJECT_NAME} ${GAME_SOURCES})

# Link the engine library
target_link_libraries(${PROJECT_NAME} GameEngine)
