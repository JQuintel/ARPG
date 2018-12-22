//
// Created by mikag on 12/22/2018.
//

#include "Window.h"
#include "Util.h"

bool Window::Initialise(int width, int height, std::string title, bool windowed, int monitor)
{
    if(window != nullptr)
    {
        Util::LogWarning("[Engine][Window] Attempted to initialise a window while another window is active. Discarding...");
        return false;
    }

    window_height = height;
    window_width = width;
    window_title = title;

    if(windowed)
    {
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    }
    else
    {
        int monitor_count = 0;
        GLFWmonitor ** monitors = glfwGetMonitors(&monitor_count);
        if(monitor_count == 0)
        {
            Util::LogError("[Engine][Window] Failed to initialise window in fullscreen mode.");
            return false;
        }
        if(monitor >= monitor_count)
        {
            Util::LogError("[Engine][Window] Can not create window on monitor " + std::to_string(monitor) + ".");
            return false;
        }

        window = glfwCreateWindow(width, height, title.c_str(), monitors[monitor], nullptr);
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, window_width, window_height);
    //Store this object as the user pointer for this window so we can retrieve it later.
    glfwSetWindowUserPointer(window, this);
    glfwSetWindowSizeCallback(window, OnSizeChanged);

    initialised = true;

    return true;
}

bool Window::Initialise(std::string title, int monitor)
{
    if(window != nullptr)
    {
        Util::LogWarning("[Engine][Window] Attempted to initialise a window while another window is active. Discarding...");
        return false;
    }

    int monitor_count;
    GLFWmonitor ** monitors = glfwGetMonitors(&monitor_count);

    if(monitor_count == 0)
    {
        Util::LogError("[Engine][Window} Failed to initialise window in fullscreen mode.");
        return false;
    }
    if(monitor >= monitor_count)
    {
        Util::LogError("[Engine][Window] Can not create window on monitor " + std::to_string(monitor) + ".");
        return false;
    }

    const GLFWvidmode * vid_mode = glfwGetVideoMode(monitors[monitor]);

    window_height = vid_mode->height;
    window_width = vid_mode->width;
    window_title = title;

    window = glfwCreateWindow(window_width, window_height, title.c_str(), monitors[monitor], nullptr);
    glfwMakeContextCurrent(window);
    glViewport(0, 0, window_width, window_height);

    //Store this object as the user pointer for this window so we can retrieve it later.
    glfwSetWindowUserPointer(window, this);
    glfwSetWindowSizeCallback(window, OnSizeChanged);

    initialised = true;

    return true;
}

void Window::SetWindowTitle(std::string title)
{
    window_title = title;
}

void Window::SetWindowWidth(int width)
{
    window_width = width;
}

void Window::SetWindowHeight(int height)
{
    window_height = height;
}

Window::Window()
= default;

Window::~Window()
= default;

const int &Window::WindowWidth() const
{
    return window_width;
}

const int &Window::WindowHeight() const
{
    return window_height;
}

const std::string &Window::WindowTitle() const
{
    return window_title;
}

GLFWwindow *Window::InternalWindowd() const
{
    return window;
}

bool Window::ShouldClose() const
{
    return static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::OnSizeChanged(GLFWwindow *window, int width, int height)
{
    Window* target = static_cast<Window *>(glfwGetWindowUserPointer(window));
    target->window_height = height;
    target->window_width = width;
    glViewport(0, 0, width, height);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(window);
}
