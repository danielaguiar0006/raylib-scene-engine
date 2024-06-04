cmake_minimum_required(VERSION 3.11)
project(MultiplayerGame)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Dependencies
set(RAYLIB_VERSION 5.0)  # Update to the latest version if needed
find_package(raylib ${RAYLIB_VERSION} REQUIRED)

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

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add raygui as an interface library
add_library(raygui INTERFACE)
target_include_directories(raygui INTERFACE ${CMAKE_SOURCE_DIR}/include/ui)

# Recursively get all the include directories
file(GLOB_RECURSE INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include/*")

# Recursively get all the source files
file(GLOB_RECURSE CPP_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${CPP_FILES})

# Link the libraries
target_link_libraries(${PROJECT_NAME} raylib raygui m)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

