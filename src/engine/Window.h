//
// Created by mikag on 12/22/2018.
//

#ifndef ARPG_WINDOW_H
#define ARPG_WINDOW_H

#include <GLFW/glfw3.h>
#include <string>

class Window {
private:
    int window_width;
    int window_height;
    std::string window_title;
    GLFWwindow *window = nullptr;
    bool initialised;

    static void OnSizeChanged(GLFWwindow * window, int width, int height);

public:
    /// Initialise a new window
    /// \param width - Width of the window
    /// \param height - Height of the window
    /// \param title - Title of the window
    /// \param windowed - Whether or not to be windowed
    /// \param monitor - Which monitor the window should appear on (0 by default)
    /// \return - Whether or not initialisation was successful.
    bool Initialise(int width, int height, std::string title, bool windowed, int monitor = 0);

    /// Initialise a new window in full screened mode
    /// \param title - Title of the window
    /// \param monitor - Which monitor the window should appear on (0 by default)
    /// \return - Whether or not initialisation was successful
    bool Initialise(std::string title, int monitor = 0);

    /// Set the title of the window
    /// \param title - New title
    void SetWindowTitle(std::string title);

    /// Set the width of the window
    /// \param width - New width
    void SetWindowWidth(int width);

    /// Set the height of the window
    /// \param height - New height
    void SetWindowHeight(int height);

    /// Swap window buffers.
    void SwapBuffers();

    Window();

    ~Window();

    /// Get the width of the window
    /// \return - Window Width
    const int & WindowWidth() const;

    /// Get the height of the window
    /// \return - Window Height
    const int & WindowHeight() const;

    /// Get the title of the window
    /// \return - Window Title
    const std::string & WindowTitle() const;

    /// Get the internal representation of the window
    /// \return - GLFWwindow representation
    GLFWwindow * InternalWindowd() const;

    /// Check whether the window should be closing.
    /// \return - Whether or not the window should close.
    bool ShouldClose() const;

};


#endif //ARPG_WINDOW_H
