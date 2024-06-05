#include "core/WindowManager.h"
#include <raylib.h>

WindowManager::WindowManager() : windowWidth(800), windowHeight(450), maxFPS(60), fullscreen(false)
{
}

WindowManager::~WindowManager()
{
    Cleanup();
    TraceLog(LOG_INFO, "WindowManager destroyed");
}

void WindowManager::Init(int windowWidth, int windowHeight, const char* windowTitle)
{
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->fullscreen = false;
    InitWindow(windowWidth, windowHeight, windowTitle);
    SetMaxFPS(maxFPS);
}

void WindowManager::Cleanup()
{
    CloseWindow();
}

void WindowManager::SetResolution(int width, int height)
{
    this->windowWidth = width;
    this->windowHeight = height;
    SetWindowSize(width, height);
}

void WindowManager::SetMaxFPS(int fps)
{
    this->maxFPS = fps;
    SetTargetFPS(fps);
}

// TODO: Maybe keep the get function in the .h file?
int WindowManager::GetWidth() const
{
    return windowWidth;
}

int WindowManager::GetHeight() const
{
    return windowHeight;
}

int WindowManager::GetMaxFPS() const
{
    return maxFPS;
}

bool WindowManager::IsFullscreen() const
{
    return IsWindowFullscreen();
}
