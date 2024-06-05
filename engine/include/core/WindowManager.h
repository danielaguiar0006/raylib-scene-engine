#pragma once

class WindowManager {
public:
    WindowManager();
    ~WindowManager();

    void Init(int windowWidth, int windowHeight, const char* windowTitle);
    void Cleanup();

    void SetResolution(int width, int height);
    void SetMaxFPS(int fps);

    int GetWidth() const;
    int GetHeight() const;
    int GetMaxFPS() const;
    bool IsFullscreen() const;

private:
    int windowWidth;
    int windowHeight;
    int maxFPS;
    bool fullscreen;
};
