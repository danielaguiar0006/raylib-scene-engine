#pragma once

class WindowManager {
public:
    /**
     * @brief Sets default values for private memeber variables.
     */
    WindowManager();

    /**
     * @brief If Cleanup() returns true, it logs a success message if not, it logs an error message.
     */
    ~WindowManager();

    /**
     * @brief Initializes the WindowManager with the given parameters and logs its success or failure.
     *
     * @param windowWidth The width of the window to be created.
     * @param windowHeight The height of the window to be created.
     * @param windowTitle The title of the window to be created.
     */
    void Init(int windowWidth, int windowHeight, const char* windowTitle);

    /**
     * @brief Cleans up the WindowManager by closing the window.
     *
     * @return true if the window was successfully closed, false otherwise (to be used for logging).
     */
    bool Cleanup();

    /**
     * @brief Sets the resolution of the window.
     *
     * @param width The new width of the window.
     * @param height The new height of the window.
     */
    void SetResolution(int width, int height);

    /**
     * @brief Sets the max FPS of the window.
     *
     * @param fps The max fps of the window.
     */
    void SetMaxFPS(int fps);

    // --- Getters ---
    int GetWidth() const;
    int GetHeight() const;
    int GetMaxFPS() const;
    bool IsFullscreen() const;

private:
    int m_WindowWidth;
    int m_WindowHeight;
    int m_MaxFPS;
    bool m_Fullscreen;
};
