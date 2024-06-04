cmake_minimum_required(VERSION 3.11)
project(TestGame)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Add the engine
add_subdirectory(engine)

# Add the game
add_subdirectory(game)

