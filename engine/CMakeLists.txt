# engine/CMakeLists.txt
project(GameEngine)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Recursively get all the source files
file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Add raylib dependency
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} REQUIRED)

# Add raygui as an interface library
add_library(raygui INTERFACE)
target_include_directories(raygui INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/ui)

# Create the engine library
add_library(GameEngine STATIC ${ENGINE_SOURCES})

# Link raylib to the engine
target_link_libraries(GameEngine raylib raygui m)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(GameEngine "-framework IOKit")
    target_link_libraries(GameEngine "-framework Cocoa")
    target_link_libraries(GameEngine "-framework OpenGL")
endif()
