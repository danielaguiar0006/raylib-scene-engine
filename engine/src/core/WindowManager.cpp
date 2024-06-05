#include "core/WindowManager.h"
#include <raylib.h>

WindowManager::WindowManager()
    : m_WindowWidth(800)
    , m_WindowHeight(450)
    , m_MaxFPS(60)
    , m_Fullscreen(false)
{
}

WindowManager::~WindowManager()
{
    if (Cleanup()) {
        TraceLog(LOG_INFO, "WindowManager succesfully destroyed");
    } else {
        TraceLog(LOG_ERROR, "WindowManager was not destroyed properly");
    }
}

void WindowManager::Init(int pixelWidth, int pixelHeight, const char* windowTitle)
{
    m_WindowWidth = pixelWidth;
    m_WindowHeight = pixelHeight;
    m_Fullscreen = false;
    InitWindow(pixelWidth, pixelHeight, windowTitle);
    SetMaxFPS(m_MaxFPS);

    // HACK: Logging is done here because the window is created in this function, not in the constructor
    if (IsWindowReady()) {
        TraceLog(LOG_INFO, "WindowManager succesfully initialized");
    } else {
        TraceLog(LOG_ERROR, "WindowManager was not initialized properly");
    }
}

bool WindowManager::Cleanup()
{
    CloseWindow();

    // Check if the window was successfully closed
    if (IsWindowReady()) {
        return false;
    } else {
        return true;
    }
}

void WindowManager::SetResolution(int pixelWidth, int pixelHeight)
{
    m_WindowWidth = pixelWidth;
    m_WindowHeight = pixelHeight;
    SetWindowSize(pixelWidth, pixelHeight);
}

void WindowManager::SetMaxFPS(int fps)
{
    m_MaxFPS = fps;
    SetTargetFPS(fps);
}

// TODO: Maybe keep the get function in the .h file?
int WindowManager::GetWidth() const
{
    return m_WindowWidth;
}

int WindowManager::GetHeight() const
{
    return m_WindowHeight;
}

int WindowManager::GetMaxFPS() const
{
    return m_MaxFPS;
}

bool WindowManager::IsFullscreen() const
{
    return IsWindowFullscreen();
}
