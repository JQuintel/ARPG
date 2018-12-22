#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

unsigned int window_width = 800;
unsigned int window_height = 600;

void OnWindowSizeChanged(GLFWwindow * window, int width, int height)
{
    window_width = static_cast<unsigned int>(width);
    window_height = static_cast<unsigned int>(height);
    glViewport(0, 0, window_width, window_height);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow * window = glfwCreateWindow(window_width, window_height, "ARPG", nullptr, nullptr);
    glfwSetWindowSizeCallback(window, OnWindowSizeChanged);

    if(!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to intialise GLAD." << std::endl;
        return -1;
    }

    glViewport(0, 0, window_width, window_height);
    glClearColor(0.2, 0.2, 0.2, 1);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    return 0;
}