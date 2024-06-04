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
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED

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
